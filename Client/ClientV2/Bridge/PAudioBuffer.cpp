#include		<cstring>
#include		<iostream>
#include		<qdebug.h>
#include		<QThread>
#include		"PAudioBuffer.hh"

// CallBack Functions

void			PAudioBuffer::feed()
{
	SAMPLE			*frames;
	AudioChunk		*chunk;
	unsigned int	i = 0;

	chunk = _bridge.outputPop();
	if (chunk == NULL)
		return ;
	if (chunk->size() == 0)
		return ;
	frames = chunk->getContent();
	if (frames == NULL)
		return ;
	i = 0;
	while (i < chunk->size())
	{
		if (fWrOut >= fMaxOut)
			fWrOut = 0;
		output[fWrOut++] = frames[i++];
//		if (fWrOut == fRdOut)
//			return ;
	}
	_bridge.pushUnused(chunk);
}

void			PAudioBuffer::sendToNetwork()
{
  int						toReach;
  int						i;
  AudioChunk				*chunk;

  if (ABS(fRdIn - fWrIn) >= FRAMES_PER_BUFFER)
    {
		toReach = fRdIn + FRAMES_PER_BUFFER;
		if (toReach >= fMaxIn)
			toReach -= fMaxIn;
		i = 0;
		while (fRdIn != toReach)
		{
			_frameBuff[i++] = input[fRdIn++];
			if (fRdIn >= fMaxIn)
			fRdIn = 0;
		}
		chunk = _bridge.popUnused();
		if (chunk == NULL)
			return ;
		chunk->clean();
		//compressed = _codec->encode(_frameBuff, FRAME_PACKET_SIZE, encodedSize);
		//chunk->assign(_frameBuff, (FRAME_PACKET_SIZE * sizeof(float)));
		// Raw Mode
		chunk->assign(_frameBuff, FRAMES_PER_BUFFER);
		_bridge.inputPush(chunk);
	}
}

int				PAudioBuffer::streamCallBack(const void *inputBuff, void *outputBuff,
					     unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
					     PaStreamCallbackFlags statusFlags, void *userData)
{
	PAudioBuffer	*data = (PAudioBuffer *)(userData);

	data->recordCallBack(inputBuff, outputBuff, framesPerBuff, timeInfo, statusFlags, userData);
	data->sendToNetwork();
	data->sendToNetwork();
	data->feed();
	data->feed();
	data->playCallBack(inputBuff, outputBuff, framesPerBuff, timeInfo, statusFlags, userData);
	return (paContinue);
}

int						PAudioBuffer::recordCallBack(const void *inputBuff,
					     void *outputBuff,
					     unsigned long framesPerBuff,
					     const PaStreamCallbackTimeInfo *timeInfo,
					     PaStreamCallbackFlags statusFlags,
					     void *userData)
{
  PAudioBuffer			*data = (PAudioBuffer *)(userData);
  SAMPLE				*readPtr = (SAMPLE *)(inputBuff);
  SAMPLE				*writePtr = data->input;
  unsigned long			i;

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
			  writePtr[data->fWrIn++] = SAMPLE_SILENCE;
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
		  writePtr[data->fWrIn++] = *readPtr++;
		  if (NUM_CHANNELS == 2 && CHECK_CIRCULAR_IN(data))
		  {
			  if (!CHECK_CIRCULAR_IN(data))
				  data->fWrIn = 0;
			  writePtr[data->fWrIn++] = *readPtr++;
		  }
		  i++;
	  }
  }
  return (paContinue);
}

int				PAudioBuffer::playCallBack(const void *inputBuff, void *outputBuff,
							   unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
							   PaStreamCallbackFlags statusFlags, void *userData)
{
  PAudioBuffer		*data = (PAudioBuffer *)(userData);
  SAMPLE			*readPtr = data->output;
  SAMPLE			*writePtr = (SAMPLE *)(outputBuff);
  unsigned long		i = 0;
  unsigned long		framesLeft;

  (void)inputBuff;
  (void)timeInfo;
  (void)statusFlags;
  (void)userData;

  framesLeft = ((ABS(data->fRdOut - data->fWrOut)) / NUM_CHANNELS);
  if (framesLeft < framesPerBuff)
  {
	  while (i < framesLeft)
	  {
		  if (!CHECK_CIRCULAR_OUT(data))
			  data->fRdOut = 0;
		  *writePtr++ = readPtr[data->fRdOut++];
		  if (NUM_CHANNELS == 2)
		  {
			  if (!CHECK_CIRCULAR_OUT(data))
				  data->fRdOut = 0;
			  *writePtr++ = readPtr[data->fRdOut++];
		  }
		  i++;
	  }
	  while (i < framesPerBuff)
	  {
		  *writePtr++ = SAMPLE_SILENCE;
		  if (NUM_CHANNELS == 2)
			  *writePtr++ = SAMPLE_SILENCE;
		  i++;
	  }
  }
  else
  {
	  while (i < framesPerBuff)
	  {
		  if (!CHECK_CIRCULAR_OUT(data))
			  data->fRdOut = 0;
		  *writePtr++ = readPtr[data->fRdOut++];
		  if (NUM_CHANNELS == 2)
		  {
			  if (!CHECK_CIRCULAR_OUT(data))
				  data->fRdOut = 0;
			  *writePtr++ = readPtr[data->fRdOut++];
		  }
		  i++;
	  }
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
  _frameBuff = new (SAMPLE[FRAMES_PER_BUFFER]);
  if (_frameBuff != NULL)
    memset(_frameBuff, 0, FRAMES_PER_BUFFER);
}

PAudioBuffer::~PAudioBuffer()
{
  if (input != NULL)
    delete [] (input);
  if (output != NULL)
    delete [] (output);
}
