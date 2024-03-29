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




  Function<void (const request::Status &, const request::Message &)>	_statusHandler;

  
  // Friends
  Function<void (const request::Username &)>					_addFriendHandler;
  Function<void (const request::Username &)>					_delFriendHandler;
  Function<void (const request::Username &)>					_getFriendHandler;
  
  // Calls
  Function<void (const request::Username &)>					_callHandler;
  Function<void ()>												_hangupHandler;

  // Chat
  Function<void (const request::Username &, const request::Message &)> _chatHandler;
  
  // Answering machine
  Function<void ()>												_setAnswerHandler;
  Function<void ()>												_unSetAnswerHandler;

  // Other Events
  Function<void ()>												_aboutToCloseHandler;

public:
  // Connection
  virtual void		setTryConnectHandler(Function<void (unsigned short, const std::string &)>);

  // Authentification
  virtual void		setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // D�s-authentification
  virtual void		setDesAuthentificationHandler(Function<void ()>);

  // Create account
  virtual void		setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Delete account
  virtual void		setTryDeleteAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>);

  // Personal changes
  virtual void		setTryChangeAccountPasswordHandler(Function<void (const request::PasswordType &, const request::PasswordType &)>);
  virtual void		setTryChangeAccountPrivacyHandler(Function<void (const request::Privacy &)>);




  virtual void		setStatusHandler(Function<void (const request::Status &, const request::Message &)>);

  // Friends
  virtual void		setAddFriendHandler(Function<void (const request::Username &)>);
  virtual void		setDelFriendHandler(Function<void (const request::Username &)>);
  virtual void		setGetFriendHandler(Function<void (const request::Username &)>);

  // Calls
  virtual void		setCallHandler(Function<void (const request::Username &)>);
  virtual void		setHangUpHandler(Function<void ()>);

  // Chat
  virtual void		setChatHandler(Function<void (const request::Username &, const request::Message &)>);

  // Answering machine
  virtual void		setSetAnswerHandler(Function<void ()>);
  virtual void		setUnSetAnswerHandler(Function<void ()>);

  // Other
  virtual void		setAboutToCloseHandler(Function<void ()>);

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
