#ifndef			PAUDIOBUFFER_H
# define		 PAUDIOBUFFER_h

# include		"AudioParams.h"
# include		"portaudio.h"
# include		"pa_asio.h"

#define			CHECK_CIRCULAR(data)	((data->fRdIndex < data->fIndexMax) ? (true) : (false))

class			PAudioBuffer
{
public:
	int			fRdIndex;
	int			fWrIndex;
	int			fIndexMax;
	SAMPLE		*content;

public:
	static int	recordCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

	static int	playCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

public:
	PAudioBuffer();
	~PAudioBuffer();
};

#endif