#include		<iostream>
#include		"PAudioBuffer.h"

// CallBacks

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
				data->fRdIndex = 0;
			writePtr[data->fRdIndex++] = SAMPLE_SILENCE;
			if (NUM_CHANNELS == 2)
			{
				if (!CHECK_CIRCULAR(data))
				data->fRdIndex = 0;
				writePtr[data->fRdIndex++] = *(readPtr++);
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
				data->fRdIndex = 0;
			writePtr[data->fRdIndex++] = (*readPtr++);
			if (NUM_CHANNELS == 2 && CHECK_CIRCULAR(data))
			{
				if (!CHECK_CIRCULAR(data))
				data->fRdIndex = 0;
				writePtr[data->fRdIndex++] = *(readPtr++);
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

PAudioBuffer::PAudioBuffer() : 
fRdIndex(0), fWrIndex(0), fIndexMax(CBUFF_SIZE), content(NULL)
{
	content = (SAMPLE *)(malloc(CBUFF_SIZE * sizeof(SAMPLE)));
	if (content != NULL)
		memset(content, 0, 65536);
}

PAudioBuffer::~PAudioBuffer()
{
	if (content != NULL)
		free(content);
}