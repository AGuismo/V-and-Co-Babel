#include				"AGraphic.hh"


void					AGraphic::setTryConnectHandler(Function<void (unsigned short, std::string)> handle)
{
	_tryConnectHandler = handle;
}
