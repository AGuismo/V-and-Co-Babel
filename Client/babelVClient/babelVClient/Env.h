#ifndef ENV_H
# define	ENV_H

#include	<QString>
#include	"FriendList.h"


class Env
{
public:
  struct
  {
    QString					login;
    QString					password;
    QString					addressIp;
    unsigned short int		portTCP;
  }							authenticateInfo;

  struct
  {
    QString					friendName;
	QString					friendAddressIp;
	unsigned short int		friendPortUDP;
	QString					userAddressIp;
	unsigned short int		userPortUDP;
  }							callInfo;

  struct
  {
	size_t					status;
	bool					connected;
	bool					incall;
  }							userInfo;
  
  struct
  {
    QString					friendName;
  }							selectedFriend;



public:
	FriendList				friendList;

public:
  static Env				&getInstance();

private:
  void						initAuthenticateInfo();
  void						initCallInfo();
  void						initUserInfo();
  void						initSelectedFriend();

private:
  Env();
  ~Env();
  Env	&operator=(const Env &);
  Env(const Env &);
};

#endif // !ENV_H
