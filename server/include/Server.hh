#ifndef SERVER_H_
# define SERVER_H_

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}

class Server
{
public:
  Server(boost::asio::io_service &service);
  ~Server();

private:
  Server(Server const&);
  Server& operator=(Server const&);

private:
  boost::asio::io_service	&_service;
};

#endif /* SERVER_H_ */
