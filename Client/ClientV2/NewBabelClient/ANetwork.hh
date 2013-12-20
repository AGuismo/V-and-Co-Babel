#ifndef ANETWORK_HH
# define ANETWORK_HH

# include		<iostream>
# include		"Function.hpp"

class ANetwork
{
protected:
	Function<void ()>		_onConnectHandler();
	Function<void (int)>	_onErrorHandler();

public:
	virtual void			setOnConnectHandler(Function<void ()>) = 0;	
	virtual void			setErrorHandler(Function<void (int)>) = 0;

public:
	void					tryConnect(unsigned short port, std::string &ipAddress);

public:
	virtual void			init() = 0;
	virtual void			run() = 0;

public:
	virtual					~ANetwork() {}

private:
	ANetwork(const ANetwork &);
	ANetwork				&operator=(const ANetwork &);
};

#endif // INETWORK_HH
