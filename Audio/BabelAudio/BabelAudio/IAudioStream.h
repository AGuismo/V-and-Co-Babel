#ifndef				IAUDIOSTREAM_H
# define			 IAUDIOSTREAM_H

class				IAudioStream
{
public:
	virtual bool	init() = 0;
	virtual void	record() = 0;
	virtual void	play() = 0;
};

#endif