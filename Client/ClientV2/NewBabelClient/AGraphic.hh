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

  // Delete account
  Function<void (const request::Username &, const request::PasswordType &)> 	_tryDeleteAccountHandler;

  // Personal changes
  Function<void (const request::PasswordType &, const request::PasswordType &)>	_tryChangePasswordHandler;
  Function<void (const request::Privacy &)>										_tryChangePrivacyHandler;




  Function<void (const request::Status &)>						_statusHandler;
  Function<void (const request::Message &)>						_statusTxtHandler;
  
  // Friends
  Function<void (const request::Username &)>					_addFriendHandler;
  Function<void (const request::Username &)>					_delFriendHandler;
  
  // Calls
  Function<void (const request::Username &)>					_callHandler;
  Function<void ()>												_hangupHandler;

  // Chat
  Function<void (const request::Username &, const std::string &)> _chatHandler;
  
public:
  // Connection
  virtual void		setTryConnectHandler(Function<void (unsigned short, const std::string &)>);

  // Authentification
  virtual void		setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Dès-authentification
  virtual void		setDesAuthentificationHandler(Function<void ()>);

  // Create account
  virtual void		setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Delete account
  virtual void		setTryDeleteAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Personal changes
  virtual void		setTryChangeAccountPasswordHandler(Function<void (const request::PasswordType &, const request::PasswordType &)>);
  virtual void		setTryChangeAccountPrivacyHandler(Function<void (const request::Privacy &)>);




  virtual void		setStatusHandler(Function<void (const request::Status &)>);
  virtual void		setStatusTxtHandler(Function<void (const request::Message &)>);

  // Friends
  virtual void		setAddFriendHandler(Function<void (const request::Username &)>);
  virtual void		setDelFriendHandler(Function<void (const request::Username &)>);

  // Calls
  virtual void		setCallHandler(Function<void (const request::Username &)>);
  virtual void		setHangUpHandler(Function<void ()>);

  // Chat
  virtual void		setChatHandler(Function<void (const request::Username &, const request::Message &)>);

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
