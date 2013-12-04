#ifndef CLIENT_H_
# define CLIENT_H_

class Client
{
public:
  Client(boost::asio::io_service &service);
  virtual ~Client();

private:
  Client(Client const&);
  Client& operator=(Client const&);

private:
  boost::asio::io_service	&_service;
};

#endif /* CLIENT_H_ */
