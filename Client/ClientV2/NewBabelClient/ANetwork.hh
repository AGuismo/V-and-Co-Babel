#ifndef ANETWORK_HH
# define ANETWORK_HH

# include		<iostream>
# include               <vector>
# include		"Function.hpp"

class ANetwork
{
public:
  enum	SocketState
    {
      CONNECTED = 0,
      ERRCONNREFUSED = 1,
      ERRTIMEDOUT = 2,
      ERRHANDSHAKE = 3,
      ERRUNKNOWN = 4
    };

  typedef std::vector<unsigned char>  ByteArray;

protected:
  Function<void ()>				_onConnectHandler;
  Function<void (enum ANetwork::SocketState)>	_onErrorHandler;
  Function<void (const ByteArray)>		_onAvailableData;
  Function<void ()>				_aboutToCloseHandler;

public:
  virtual void			setOnConnectHandler(Function<void ()>);
  virtual void			setErrorHandler(Function<void (enum ANetwork::SocketState)>);
  virtual void			setAvailableData(Function<void (const ByteArray)>);
  virtual void			setAboutToCloseHandler(Function<void ()>);

public:
  virtual void					tryConnect(unsigned short port, const std::string &ipAddress) = 0;
  virtual void                  sendData(const ByteArray &) = 0;
  virtual void                  closeConnection() = 0;

public:
  virtual bool			init() = 0;
  virtual void			run() = 0;

public:
  ANetwork();
  virtual				~ANetwork();

private:
  ANetwork(const ANetwork &);
  ANetwork			&operator=(const ANetwork &);
};

#endif // INETWORK_HH
