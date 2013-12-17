#include		"Env.h"


void			Env::initAuthenticateInfo()
{
  authenticateInfo.login = "Login";
  authenticateInfo.password = "Password";
  authenticateInfo.addressIp = "127.0.0.1";
  authenticateInfo.portTCP = 44201;
}

void			Env::initCallInfo()
{
  callInfo.friendName = "";
  callInfo.friendAddressIp = "";
  callInfo.userAddressIp = "";
  callInfo.friendPortUDP = 0;
  callInfo.userPortUDP = 0;
}

void			Env::initSelectedFriend()
{
  selectedFriend.friendName = "";
}

void			Env::initUserInfo()
{
	userInfo.status = 0; // à check
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
  initAuthenticateInfo();
  initCallInfo();
  initUserInfo();
  initSelectedFriend();
}

Env::~Env()
{
}
