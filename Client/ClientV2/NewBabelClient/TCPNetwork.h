#ifndef TCPNETWORK_HH
#define TCPNETWORK_HH

# include <QTcpSocket>
# include <QObject>
# include "ANetwork.hh"

class TCPNetwork: public QObject, public ANetwork
{
  Q_OBJECT
public:
  TCPNetwork();

public:
  void  init();
  void  run();

public:
  void  tryConnect(unsigned short port, const std::string &ipAddress);
  void  sendData(const ANetwork::ByteArray &);
  void  closeConnection();

public slots:
  void  onRead();

private:
  void	translateError();

private:
  TCPNetwork &operator=(const TCPNetwork &);
  TCPNetwork(const TCPNetwork &);

private:
  QTcpSocket  _sock;
};

#endif // TCPNETWORK_HH
