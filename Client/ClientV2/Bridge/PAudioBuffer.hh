#ifndef			PAUDIOBUFFER_H
# define		 PAUDIOBUFFER_h

# include		"AudioParams.hh"
# include		"AudioBridge.hh"
# include		"IAudioCodec.hh"
# include		"portaudio.h"
//# include		"pa_asio.h"
# include		<fstream>

#define			CHECK_CIRCULAR_IN(data)		((data->fWrIn < data->fMaxIn) ? (true) : (false))
#define			CHECK_CIRCULAR_OUT(data)	((data->fWrOut < data->fMaxOut) ? (true) : (false))

class			PAudioBuffer
{
private:
	SAMPLE			*_frameBuff;
//	unsigned char	*_compressedBuff;
	IAudioCodec	*_codec;
	std::ofstream	myFile;

public:
	int			fRdIn;
	int			fWrIn;
	int			fMaxIn;
	SAMPLE		*input;

	int			fRdOut;
	int			fWrOut;
	int			fMaxOut;
	SAMPLE		*output;

	AudioBridge		&_bridge;

public:
	void		sendToNetwork();
	void		feed(AudioChunk &chunk);
	static int	streamCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

	int			recordCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);
	int			playCallBack(const void *inputBuff, void *outputBuff,
				unsigned long framesPerBuff, const PaStreamCallbackTimeInfo *timeInfo,
				PaStreamCallbackFlags statusFlags, void *userData);

public:
	PAudioBuffer(IAudioCodec *codec, AudioBridge &bridge);
	~PAudioBuffer();
};

#endif
