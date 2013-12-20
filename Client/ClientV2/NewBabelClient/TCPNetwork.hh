#ifndef TCPNETWORK_HH
#define TCPNETWORK_HH

# include <QTcpSocket>
# include "ANetwork.hh"

class TCPNetwork: public ANetwork
{
public:
  TCPNetwork();
  ~TCPNetwork();

public:
  void  init();
  void  run();

public:
  void  tryConnect(unsigned short port, const std::string &ipAddress);

private:
  TCPNetwork &operator=(const TCPNetwork &);
  TCPNetwork(const TCPNetwork &);

private:
  QTcpSocket  _sock;
};

#endif // TCPNETWORK_HH
