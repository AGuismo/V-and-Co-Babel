#ifndef			PAUDIOBUFFER_H
# define		 PAUDIOBUFFER_h

# include		"AudioParams.hh"
# include		"Bridge.hh"
# include		"IAudioCodec.hh"
# include		"portaudio.h"
# include		"pa_asio.h"
# include		<fstream>

#define			CHECK_CIRCULAR(data)	((data->fWrIndex < data->fIndexMax) ? (true) : (false))

class			PAudioBuffer
{
private:
	SAMPLE		*_frameBuff;
	IAudioCodec	*_codec;
	std::ofstream	myFile;

public:
	int			fRdIndex;
	int			fWrIndex;
	int			fIndexMax;
	SAMPLE		*content;
	Bridge		&_bridge;

public:
	void		sendToNetwork();
	void		feed(char *data);
	static int	recordCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

	static int	playCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

public:
	PAudioBuffer(IAudioCodec *codec, Bridge &bridge);
	~PAudioBuffer();
};

#endif