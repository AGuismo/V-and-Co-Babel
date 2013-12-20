#include				"AGraphic.hh"


void					AGraphic::setTryConnectHandler(Function<void (unsigned short, const std::string &)> handle)
{
	_tryConnectHandler = handle;
}
