#include		<cstring>
#include		<iostream>
#include		<qdebug.h>
#include		<QThread>
#include		"PAudioBuffer.hh"

// CallBacks

void			PAudioBuffer::feed(AudioChunk &chunk)
{
	SAMPLE			*frames;
	unsigned int	i = 0;

//	if (chunk.size() == 0)
//		return ;
	if (chunk.empty())
		return ;
//	frames = _codec->decode(chunk.getContent(), FRAME_PACKET_SIZE);
	frames = reinterpret_cast<float *>(chunk.getContent());
	if (frames == NULL)
		return ;
	i = 0;
	while (i < FRAME_PACKET_SIZE)
	{
		if (fRdOut >= fMaxOut)
			fRdOut = 0;
		if (fWrOut >= fMaxOut)
			fWrOut = 0;
		output[fWrOut++] = frames[i++];
		if (fWrOut == fRdOut)
			return ;
	}
}

void			PAudioBuffer::sendToNetwork()
{
  int						toReach;
  int						i;
  unsigned char				*compressed;
  unsigned int				encodedSize;
  AudioChunk				*chunk;

  while (ABS(fRdIn - fWrIn) >= FRAME_PACKET_SIZE)
    {
      toReach = fRdIn + FRAME_PACKET_SIZE;
	  if (toReach >= fMaxIn)
		  toReach -= fMaxIn;
      i = 0;
      while (fRdIn != toReach)
	{
	  _frameBuff[i++] = input[fRdIn++];
	  if (fRdIn >= fMaxIn)
	    fRdIn = 0;
	  if (fWrIn >= fMaxIn)
	    fWrIn = 0;
	}
      encodedSize = 0;
//    compressed = _codec->encode(_frameBuff, FRAME_PACKET_SIZE, encodedSize);
	  chunk = _bridge.popUnused();
	  chunk->assign(reinterpret_cast<unsigned char *>(_frameBuff), (FRAME_PACKET_SIZE * sizeof(float)));
//    chunk.assign(compressed, encodedSize);
//      qDebug() << QThread::currentThreadId() << "Sending packet";
      _bridge.inputPush(chunk);
    }
}

int				PAudioBuffer::streamCallBack(const void *inputBuff, void *outputBuff,
					     unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
					     PaStreamCallbackFlags statusFlags, void *userData)
{
	PAudioBuffer	*data = (PAudioBuffer *)(userData);

	data->recordCallBack(inputBuff, outputBuff, framesPerBuff, timeInfo, statusFlags, userData);
	data->playCallBack(inputBuff, outputBuff, framesPerBuff, timeInfo, statusFlags, userData);
	return (paContinue);
}

int				PAudioBuffer::recordCallBack(const void *inputBuff,
					     void *outputBuff,
					     unsigned long framesPerBuff,
					     const PaStreamCallbackTimeInfo *timeInfo,
					     PaStreamCallbackFlags statusFlags,
					     void *userData)
{
  PAudioBuffer	*data = (PAudioBuffer *)(userData);
  SAMPLE		*readPtr = (SAMPLE *)(inputBuff);
  SAMPLE		*writePtr = data->input;
  long			i;

  (void)outputBuff;
  (void)timeInfo;
  (void)statusFlags;
  (void)userData;

  if (inputBuff == NULL)
    {
      i = 0;
      while (i < framesPerBuff)
	  {
		  if (!CHECK_CIRCULAR_IN(data))
			  data->fWrIn = 0;
		  writePtr[data->fWrIn++] = SAMPLE_SILENCE;
		  if (NUM_CHANNELS == 2)
		  {
			  if (!CHECK_CIRCULAR_IN(data))
				  data->fWrIn = 0;
			  writePtr[data->fWrIn++] = *(readPtr++);
		  }
		  i++;
	  }
  }
  else
  {
	  i = 0;
      while (i < framesPerBuff)
	  {
		  if (!CHECK_CIRCULAR_IN(data))
			  data->fWrIn = 0;
		  writePtr[data->fWrIn++] = (*readPtr++);
		  if (NUM_CHANNELS == 2 && CHECK_CIRCULAR_IN(data))
		  {
			  if (!CHECK_CIRCULAR_IN(data))
				  data->fWrIn = 0;
			  writePtr[data->fWrIn++] = *(readPtr++);
		  }
		  i++;
	  }
  }
  data->sendToNetwork();
  return (paContinue);
}

int				PAudioBuffer::playCallBack(const void *inputBuff, void *outputBuff,
							   unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
							   PaStreamCallbackFlags statusFlags, void *userData)
{
  PAudioBuffer		*data = (PAudioBuffer *)(userData);
  SAMPLE			*readPtr = data->output;
  SAMPLE			*writePtr = (SAMPLE *)(outputBuff);
  AudioBridge::output_buffer	chunkList;
  long				i = 0;

  (void)inputBuff;
  (void)timeInfo;
  (void)statusFlags;
  (void)userData;

//  _bridge.outputRead(chunkList, 1, false);
//  if (chunkList.size() != 0)
//	  data->feed(chunkList[0]);
  while ((ABS(data->fRdOut - data->fWrOut) > 0) && (i < framesPerBuff))
  {
	  writePtr[i++] = readPtr[data->fRdOut++];
	  if (data->fRdOut >= data->fMaxOut)
	    data->fRdOut = 0;
	  if (data->fWrOut >= data->fMaxOut)
	    data->fWrOut = 0;
  }
  return (paContinue);
}

// Constructors & Destructors

PAudioBuffer::PAudioBuffer(IAudioCodec *codec, AudioBridge &bridge) :
  fRdIn(0), fWrIn(0), fMaxIn(CBUFF_SIZE), input(NULL),
  fRdOut(0), fWrOut(0), fMaxOut(CBUFF_SIZE), output(NULL),
  _frameBuff(NULL), _codec(codec), _bridge(bridge)
{
  input = new (SAMPLE[CBUFF_SIZE]);
  if (input != NULL)
    memset(input, 0, CBUFF_SIZE);
  output = new (SAMPLE[CBUFF_SIZE]);
  if (output != NULL)
    memset(output, 0, CBUFF_SIZE);
  _frameBuff = new (SAMPLE[FRAME_PACKET_SIZE]);
  if (_frameBuff != NULL)
    memset(_frameBuff, 0, FRAME_PACKET_SIZE);
//  _compressedBuff = new (unsigned char[1105]);
//  if (_compressedBuff != NULL)
//	  memset(_compressedBuff, 0, 1105);
}

PAudioBuffer::~PAudioBuffer()
{
  if (input != NULL)
    delete [] (input);
  if (output != NULL)
    delete [] (output);
}
