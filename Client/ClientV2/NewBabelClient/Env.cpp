#include		"Env.hh"


void			Env::initCallInfo()
{
  callInfo.name = "";
  callInfo.addressIp = "";
  callInfo.portUDP = 0;
}

void			Env::initSelectedFriend()
{
  selectedFriend.name = "";
  selectedFriend.status = DISCONNECTED;
}

void			Env::initUserInfo()
{
	userInfo.login = "";
	userInfo.loginTry = "";
	userInfo.status = DISCONNECTED;
	userInfo.connected = false;
	userInfo.authenticated = false;
	userInfo.incall = false;
}

Env		&Env::getInstance()
{
  static Env	env;

  return (env);
}

Env::Env()
{
  initCallInfo();
  initUserInfo();
  initSelectedFriend();
}

Env::~Env()
{
}
