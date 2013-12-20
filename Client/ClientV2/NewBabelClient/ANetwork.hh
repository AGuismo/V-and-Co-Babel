#ifndef ANETWORK_HH
# define ANETWORK_HH

# include		<iostream>
# include		"Function.hpp"

class ANetwork
{
protected:
	Function<void ()>		_onConnectHandler;
	Function<void (int)>		_onErrorHandler;

public:
	virtual void			setOnConnectHandler(Function<void ()>);
	virtual void			setErrorHandler(Function<void (int)>);

public:
	virtual void			tryConnect(unsigned short port, const std::string &ipAddress) = 0;

public:
	virtual void			init() = 0;
	virtual void			run() = 0;

public:
	ANetwork();
	virtual				~ANetwork();

private:
	ANetwork(const ANetwork &);
	ANetwork			&operator=(const ANetwork &);
};

#endif // INETWORK_HH
