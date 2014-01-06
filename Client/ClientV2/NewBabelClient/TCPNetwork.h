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
  bool  init();
  void  run();

public:
  void  tryConnect(unsigned short port, const std::string &ipAddress);
  void  sendData(const ANetwork::ByteArray &);
  void  closeConnection();

private slots:
  void  onRead();
  void	stateChanged(QAbstractSocket::SocketState st);

private:
  void	translateError();

private:
  TCPNetwork &operator=(const TCPNetwork &);
  TCPNetwork(const TCPNetwork &);

private:
  QTcpSocket  _sock;
};

#endif // TCPNETWORK_HH
