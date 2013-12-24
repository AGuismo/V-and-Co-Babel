#ifndef AGRAPHIC_HH
#define AGRAPHIC_HH

# include		<iostream>
# include		"types.hh"
# include		"Function.hpp"
# include		"ANetwork.hh"

class AGraphic
{
protected:
  // Connection
  Function<void (unsigned short, const std::string &)>				_tryConnectHandler;

  // Authentification
  Function<void (const request::Username &, const request::PasswordType &)>	_tryAuthentificationHandler;

  // Des-Authentification
  Function<void ()>												_desAuthentificationHandler;

  // Create account
  Function<void (const request::Username &, const request::PasswordType &)> 	_tryCreateAccountHandler;

  // Personal changes

  // Friend
  Function<void (const std::string &, bool)>				_friendRequestResponseHandler;
  Function<void (const std::string &)>						_askForFriendHandler;

  // Calls
  Function<void (bool)>										_callResponseHandler;
  Function<void ()>											_hangupHandler;


public:
  // Connection
  virtual void		setTryConnectHandler(Function<void (unsigned short, const std::string &)>);

  // Authentification
  virtual void		setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Dès-authentification
  virtual void		setDesAuthentificationHandler(Function<void ()>);

  // Create account
  virtual void		setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Personal changes

  // Friend
  //virtual void		setFriendRequestResponse(Function<void (const std::string &, bool)>); // To do

  // Calls
  //virtual void		setCallResponse(Function<void (bool)>); // To do
  //virtual void		setHangup(Function<void ()>); // To do

public:
  // Connection
  // virtual void		ConnectionStateChanged(enum ANetwork::SocketState) = 0;  // To do

  // Authentification
  // virtual void		Authenticated(bool) = 0;  // To do

  // Personal Changes

  // Friends

  // Call
  // virtual void		Call(const std::string &) = 0;  // To do
  // virtual void		EndCall() = 0; // To do

public:
  virtual void		init() = 0;
  virtual void		run() = 0;

public:
  AGraphic() {}
  virtual			~AGraphic() {}

private:
  AGraphic(const AGraphic &);
  AGraphic		&operator=(const AGraphic &);
};

#endif // AGRAPHIC_HH
