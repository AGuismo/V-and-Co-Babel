#include		<iostream>
#include		"PAudioBuffer.h"

// CallBacks

void			PAudioBuffer::sendToNetwork()
{
	int				toReach;
	int				i;
	int				diff;
	unsigned char	*compressed;
	SAMPLE			*decompressed;

	myFile << fRdIndex << " - " << fWrIndex << std::endl;
	while (ABS(fRdIndex - fWrIndex) >= FRAME_PACKET_SIZE)
	{
		myFile << "SENDING PACKET, ";
		toReach = fRdIndex + FRAME_PACKET_SIZE;
		if (toReach >= fIndexMax)
			toReach -= fIndexMax;
		myFile << "ToReach : " << toReach << std::endl;
		i = 0;
		while (fRdIndex != toReach)
		{
			_frameBuff[i++] = content[fRdIndex++];
			if (fRdIndex >= fIndexMax)
				fRdIndex = 0;
			if (fWrIndex >= fIndexMax)
				fWrIndex = 0;
		}
		myFile << _frameBuff[0] << "<->" << _frameBuff[1] << std::endl;
		compressed = _codec->encode(_frameBuff, FRAME_PACKET_SIZE);
		myFile << "Data : " << compressed << std::endl;;
	}
}

int				PAudioBuffer::recordCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData)
{
	PAudioBuffer	*data = (PAudioBuffer *)(userData);
	SAMPLE			*readPtr = (SAMPLE *)(inputBuff);
	SAMPLE			*writePtr = data->content;
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
			if (!CHECK_CIRCULAR(data))
				data->fWrIndex = 0;
			writePtr[data->fWrIndex++] = SAMPLE_SILENCE;
			if (NUM_CHANNELS == 2)
			{
				if (!CHECK_CIRCULAR(data))
					data->fWrIndex = 0;
				writePtr[data->fWrIndex++] = *(readPtr++);
			}
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < framesPerBuff)
		{
			if (!CHECK_CIRCULAR(data))
				data->fWrIndex = 0;
			writePtr[data->fWrIndex++] = (*readPtr++);
			if (NUM_CHANNELS == 2 && CHECK_CIRCULAR(data))
			{
				if (!CHECK_CIRCULAR(data))
				data->fWrIndex = 0;
				writePtr[data->fWrIndex++] = *(readPtr++);
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
	PAudioBuffer	*data = (PAudioBuffer *)(userData);
	SAMPLE			*readPtr = data->content;
	SAMPLE			*writePtr = (SAMPLE *)(outputBuff);
	long			i;

	(void)inputBuff;
	(void)timeInfo;
	(void)statusFlags;
	(void)userData;

	std::cout << "Entering callback, framesPerBuff = " << framesPerBuff << ", fRdIndex = " << data->fRdIndex << std::endl;
	for (i = 0; i < framesPerBuff;  i++)
	{
		if (!CHECK_CIRCULAR(data))
			data->fRdIndex = 0;
		*(writePtr++) = readPtr[data->fRdIndex++];
		if (NUM_CHANNELS == 2)
		{
			if (!CHECK_CIRCULAR(data))
			data->fRdIndex = 0;
			*(writePtr++) = readPtr[data->fRdIndex++];
		}
	}
	return (paContinue);
}

// Constructors & Destructors

PAudioBuffer::PAudioBuffer(IAudioCodec *codec) : 
fRdIndex(0), fWrIndex(0), fIndexMax(CBUFF_SIZE), content(NULL), _frameBuff(NULL), _codec(codec)
{
	myFile.open("Audio.wav");
	content = new (SAMPLE[CBUFF_SIZE]);
	if (content != NULL)
		memset(content, 0, CBUFF_SIZE);
	_frameBuff = new (SAMPLE[FRAME_PACKET_SIZE]);
	if (_frameBuff != NULL)
		memset(_frameBuff, 0, FRAME_PACKET_SIZE);
}

PAudioBuffer::~PAudioBuffer()
{
	if (content != NULL)
		free(content);
	myFile.close();
}