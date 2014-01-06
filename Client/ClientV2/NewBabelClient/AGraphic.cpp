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

void		AGraphic::setTryChangeAccountPasswordHandler(Function<void (const request::PasswordType &, const request::PasswordType &)> handle)
{
	_tryChangePasswordHandler = handle;
}

void		AGraphic::setTryChangeAccountPrivacyHandler(Function<void (const request::Privacy &)> handle)
{
	_tryChangePrivacyHandler = handle;
}

void		AGraphic::setDesAuthentificationHandler(Function<void ()> handle)
{
	_desAuthentificationHandler = handle;
}




void		AGraphic::setAddFriendHandler(Function<void (const request::Username &)> handle)
{
	_addFriendHandler = handle;
}

void		AGraphic::setGetFriendHandler(Function<void (const request::Username &)> handle)
{
	_getFriendHandler = handle;
}

void		AGraphic::setDelFriendHandler(Function<void (const request::Username &)> handle)
{
	_delFriendHandler = handle;
}

void		AGraphic::setCallHandler(Function<void (const request::Username &)> handle)
{
	_callHandler = handle;
}

void		AGraphic::setHangUpHandler(Function<void ()> handle)
{
	_hangupHandler = handle;
}

void		AGraphic::setChatHandler(Function<void (const request::Username &, const request::Message &)> handle)
{
	_chatHandler = handle;
}

void		AGraphic::setStatusHandler(Function<void (const request::Status &, const request::Message &)> handle)
{
	_statusHandler = handle;
}


void		AGraphic::setSetAnswerHandler(Function<void ()> handle)
{
	_setAnswerHandler = handle;
}

void		AGraphic::setUnSetAnswerHandler(Function<void ()> handle)
{
	_unSetAnswerHandler = handle;
}

void		AGraphic::setAboutToCloseHandler(Function<void ()> handle)
{
	_aboutToCloseHandler = handle;
}