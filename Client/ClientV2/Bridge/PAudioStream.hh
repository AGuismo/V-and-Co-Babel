#ifndef					PAUDIOSTREAM_H
# define				 PAUDIOSTREAM_H

# include				<string>
# include				<vector>
# include				"AudioBridge.hh"
# include				"IAudioStream.hh"
# include				"PAudioBuffer.hh"
# include				"OpAudioCodec.hh"

class					PAudioStream : public IAudioStream
{
private:
	PaStream*			_stream;
	PaStreamParameters	_inputParam;
	PaStreamParameters	_outputParam;
	OpAudioCodec		_codec;
	PAudioBuffer		*_input;
	PAudioBuffer		*_output;

protected:
	bool				initInput();
	bool				initOutput();
	AudioBridge				&_bridge;

public:
	virtual bool		init();
	virtual void		run();

public:
	PAudioStream(AudioBridge &bridge);
	~PAudioStream();
};

#endif
