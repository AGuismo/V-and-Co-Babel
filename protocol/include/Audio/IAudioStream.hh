#ifndef				IAUDIOSTREAM_H
# define			 IAUDIOSTREAM_H

class				IAudioStream
{
public:
	virtual bool	init() = 0;
	virtual void	run() = 0;
};

#endif