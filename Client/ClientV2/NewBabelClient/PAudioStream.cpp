#include		<stdint.h>
#include		<iomanip> // Debug purpose
#include		<qdebug.h>
#include		<QThread>
#include		<iostream>
#include		"PAudioStream.hh"

// Methods

bool			PAudioStream::initInput()
{
  if (_buffer->input == NULL)
    return (false);
  if ((_inputParam.device = Pa_GetDefaultInputDevice()) == paNoDevice)
    {
      qDebug() << "No default input device.";
      return (false);
    }
  _inputParam.channelCount = NUM_CHANNELS;
  _inputParam.sampleFormat = PA_SAMPLE_TYPE;
  _inputParam.suggestedLatency = (Pa_GetDeviceInfo(_inputParam.device))->defaultLowInputLatency;
  _inputParam.hostApiSpecificStreamInfo = NULL;
  return (true);
}

bool			PAudioStream::initOutput()
{
  if (_buffer->output == NULL)
    return (false);
  if ((_outputParam.device = Pa_GetDefaultOutputDevice()) == paNoDevice)
    {
      qDebug() << "No default output device.";
      return (false);
    }
  _outputParam.channelCount = NUM_CHANNELS;
  _outputParam.sampleFormat = PA_SAMPLE_TYPE;
  _outputParam.suggestedLatency = (Pa_GetDeviceInfo(_outputParam.device))->defaultLowOutputLatency;
  _outputParam.hostApiSpecificStreamInfo = NULL;
  return (true);
}

bool			PAudioStream::init()
{
  if (Pa_Initialize() != paNoError)
    return (false);
  return (_codec.init() && initInput() && initOutput());
}

void			PAudioStream::run()
{
  PaError		error = paNoError;
  AudioBridge::output_buffer	buff;

  error = Pa_OpenStream(&_stream, &_inputParam, &_outputParam, SAMPLE_RATE,
			FRAMES_PER_BUFFER, paClipOff, PAudioBuffer::streamCallBack, _buffer);
  if (error != paNoError)
    return ;
  if (Pa_StartStream(_stream) != paNoError)
    return ;
  qDebug() << QThread::currentThreadId() << "RECORDING, SPEAK INTO THE MICROPHONE PLEASE";
  _start = true;
  while (_start && (error = Pa_IsStreamActive(_stream)) == 1)
    {
//		lock(audioLock);
//		if (record.empty() && play.empty())
//		waitCondition(dataAvailable);
//		unlock(audioLock);
//		_buffer->sendToNetwork();
//		_buffer->feed();
		Pa_Sleep(40);
    }
  if (Pa_IsStreamActive(_stream) == 1)
    Pa_StopStream(_stream);
  qDebug() << QThread::currentThreadId() << "RECORDING ENDED";
  if (error < 0)
    return;
  if ((error = Pa_CloseStream(_stream)) != paNoError)
    {
      std::cout << "PAudioStream::run(): " << Pa_GetErrorText(error) << std::endl;
      return;
    }
  if ((error = Pa_Terminate()) != paNoError)
    {
      std::cout << "PAudioStream::run(): " << Pa_GetErrorText(error) << std::endl;
      return;
    }
}

void			PAudioStream::stop()
{
  _start = false; // Ugly way, but stopstream deadlock, don't know why
  // Pa_StopStream(_stream);
}

// Constructor/Destructor

PAudioStream::PAudioStream(AudioBridge &bridge) : _bridge(bridge)
{
  _buffer = new PAudioBuffer(&_codec, bridge);
}

PAudioStream::~PAudioStream()
{
}
