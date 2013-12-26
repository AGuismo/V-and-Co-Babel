#include	"AGraphic.hh"


void		AGraphic::setTryConnectHandler(Function<void (unsigned short, const std::string &)> handle)
{
  _tryConnectHandler = handle;
}

void		AGraphic::setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)> handle)
{
  _tryAuthentificationHandler = handle;
}

void		AGraphic::setTryDeleteAccountHandler(Function<void (const request::Username &, const request::PasswordType &)> handle)
{
  _tryDeleteAccountHandler = handle;
}

void		AGraphic::setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)> handle)
{
  _tryCreateAccountHandler = handle;
}

void		AGraphic::setDesAuthentificationHandler(Function<void ()> handle)
{
	_desAuthentificationHandler = handle;
}
