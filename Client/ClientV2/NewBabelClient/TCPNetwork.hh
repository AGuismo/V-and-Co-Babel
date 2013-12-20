#ifndef TCPNETWORK_HH
#define TCPNETWORK_HH

# include <QTcpSocket>
# include <QObject>
# include "ANetwork.hh"

class TCPNetwork: public QObject, public ANetwork
{
public:
  TCPNetwork();
  ~TCPNetwork();

public:
  void  init();
  void  run();

public:
  void  tryConnect(unsigned short port, const std::string &ipAddress);

private slots:
  void  onRead();

private:
  TCPNetwork &operator=(const TCPNetwork &);
  TCPNetwork(const TCPNetwork &);

private:
  QTcpSocket  _sock;
};

#endif // TCPNETWORK_HH
