#ifndef ENV_HH
# define	ENV_HH

#include	<iostream>
#include	"FriendList.hh"


class Env
{
public:

  struct
  {
	std::string				login;
    std::string				loginTry;
	Status					status;
	bool					authenticated;
	bool					connected;
	bool					incall;
  }							userInfo;

  struct
  {
    std::string				name;
	std::string				addressIp;
	unsigned short int		portUDP;
  }							callInfo;


  
  struct
  {
    std::string				name;
	Status					status;
  }							selectedFriend;



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

#endif // !ENV_HH
