#ifndef AGRAPHIC_HH
#define AGRAPHIC_HH


# include		<iostream>

class AGraphic
{
protected:
	Function<void (unsigned short, std::string &)>	_tryConnectHandler();

public:
	virtual void									setTryConnectHandler(Function<void (unsigned short, std::string)>) = 0;

public:
	virtual void									init() = 0;
	virtual void									run() = 0;

public:
	virtual											~AGraphic() {}

private:
	AGraphic(const AGraphic &);
	AGraphic										&operator=(const AGraphic &);
};

#endif // AGRAPHIC_HH
