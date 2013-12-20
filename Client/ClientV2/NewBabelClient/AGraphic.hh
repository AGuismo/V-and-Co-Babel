#ifndef AGRAPHIC_HH
#define AGRAPHIC_HH

# include		<iostream>
# include		"Function.hpp"

class AGraphic
{
protected:
	Function<void (unsigned short, const std::string &)>	_tryConnectHandler;

public:
	virtual void									setTryConnectHandler(Function<void (unsigned short, const std::string &)>);

public:
	virtual void									init() = 0;
	virtual void									run() = 0;

public:
	AGraphic() {}
	virtual											~AGraphic() {}

private:
	AGraphic(const AGraphic &);
	AGraphic										&operator=(const AGraphic &);
};

#endif // AGRAPHIC_HH
