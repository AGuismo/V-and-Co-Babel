#include	"AGraphic.hh"


void		AGraphic::setTryConnectHandler(Function<void (unsigned short, const std::string &)> handle)
{
  _tryConnectHandler = handle;
}

void		AGraphic::setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)> handle)
{
  _tryAuthentificationHandler = handle;
}
