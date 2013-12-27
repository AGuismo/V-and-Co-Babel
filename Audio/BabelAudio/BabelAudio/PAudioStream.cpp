#include		<stdint.h>
#include		<iostream>
#include		"PAudioStream.h"

// Methods

bool			PAudioStream::initInput()
{
	if (_input->content == NULL)
		return (false);
	if (Pa_Initialize() != paNoError)
		return (false);
	if ((_inputParam.device = Pa_GetDefaultInputDevice()) == paNoDevice)
	{
		std::cout << "No default input device." << std::endl;
		return (false);
	}
	_inputParam.channelCount = 2;
	_inputParam.sampleFormat = PA_SAMPLE_TYPE;
	_inputParam.suggestedLatency = (Pa_GetDeviceInfo(_inputParam.device))->defaultLowInputLatency;
	_inputParam.hostApiSpecificStreamInfo = NULL;
	return (true);
}

bool			PAudioStream::initOutput()
{
	if (_output->content == NULL)
		return (false);
	if ((_outputParam.device = Pa_GetDefaultOutputDevice()) == paNoDevice)
	{
		std::cout << "No default output device." << std::endl;
		return (false);
	}
	_outputParam.channelCount = 2;
	_outputParam.sampleFormat = PA_SAMPLE_TYPE;
	_outputParam.suggestedLatency = (Pa_GetDeviceInfo(_outputParam.device))->defaultLowOutputLatency;
	_outputParam.hostApiSpecificStreamInfo = NULL;
	return (true);
}

bool			PAudioStream::init()
{
	return (_codec.init() && initInput() && initOutput());
}

void			PAudioStream::record()
{
	PaError		error = paNoError;

	error = Pa_OpenStream(&_stream, &_inputParam, NULL, SAMPLE_RATE,
		FRAMES_PER_BUFFER, paClipOff, PAudioBuffer::recordCallBack, _input);
	if (error != paNoError)
		return ;
	if (Pa_StartStream(_stream) != paNoError)
		return ;
	std::cout << "RECORDING, SPEAK INTO THE MICROPHONE PLEASE" << std::endl;
	while ((error = Pa_IsStreamActive(_stream)) == 1)
	{
		Pa_Sleep(1000);
		std::cout << "Index = " << _input->fWrIndex << std::endl;
	}
	if (error < 0)
		return ;
	if (Pa_CloseStream(_stream) != paNoError)
		return ;
}

void			PAudioStream::play()
{
	PaError		error = paNoError;

	error = Pa_OpenStream(&_stream, NULL, &_outputParam, SAMPLE_RATE,
		FRAMES_PER_BUFFER, paClipOff, PAudioBuffer::playCallBack, _output);
	if (error != paNoError)
		return ;
	_output->fRdIndex = 0;
	std::cout << "PLAYING BACK RECORDED DATA" << std::endl;
	if (_stream)
	{
		if (Pa_StartStream(_stream) != paNoError)
			return ;
		std::cout << "Waiting for playback to end..." << std::endl;
		while ((error = Pa_IsStreamActive(_stream)) == 1)
			Pa_Sleep(100);
		if (error < 0)
			return ;
		if (Pa_CloseStream(_stream) != paNoError)
			return ;
		std::cout << "Playback ended." << std::endl;
	}
}

// Constructor/Destructor

PAudioStream::PAudioStream()
{
	_input = new PAudioBuffer(&_codec);
	_output = new PAudioBuffer(&_codec);
}

PAudioStream::~PAudioStream()
{
}