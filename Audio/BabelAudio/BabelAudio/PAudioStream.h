#ifndef					PAUDIOSTREAM_H
# define				 PAUDIOSTREAM_H

# include				<string>
# include				<vector>
# include				"PAudioBuffer.h"

class					PAudioStream
{
private:
	PaStream*			_stream;
	PaStreamParameters	_inputParam;
	PaStreamParameters	_outputParam;
	PAudioBuffer		_input;
	PAudioBuffer		_output;

protected:
	bool				initInput();
	bool				initOutput();

public:
	virtual bool		init();
	virtual void		record();
	virtual void		play();

public:
	PAudioStream();
	~PAudioStream();
};

#endif