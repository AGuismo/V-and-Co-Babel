#include		"Env.hh"


void			Env::initCallInfo()
{
  callInfo.friendName = "";
  callInfo.friendAddressIp = 0;
  callInfo.friendPortUDP = 0;
  callInfo.userName = "";
  callInfo.userAddressIp = 0;
  callInfo.userPortUDP = 40546;
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
