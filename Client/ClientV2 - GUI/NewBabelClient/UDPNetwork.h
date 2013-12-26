#ifndef UDPNETWORK_H
#define UDPNETWORK_H

# include <QUdpSocket>
# include <QObject>
# include "ANetwork.hh"

class UDPNetwork : public QObject, public ANetwork
{
  Q_OBJECT

public:
  UDPNetwork();
  ~UDPNetwork();

public:
  void  tryConnect(unsigned short port, const std::string &ipAddress);
  void  sendData(const ANetwork::ByteArray &);
  void  closeConnection();
  unsigned short  localPort() const;

public:
  void  init();
  void  run();
  void  stop();

private slots:
  void  handleRead();

private:
  QUdpSocket    _sock;
  QHostAddress  _receiverIP;
  quint16       _receiverPort;
};

#endif // UDPNETWORK_H
