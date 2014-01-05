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
  void  tryConnect(unsigned short port, int ip);
  void  sendData(const ANetwork::ByteArray &);
  unsigned short  localPort() const;

public:
  bool  init();
  void  start();
  void  stop();
  bool	reset();

private:
	void	run();
	void	closeConnection();

private slots:
  void  handleOutputRead();

signals:
  void	serverStarted();
  void	serverStopped();

private:
	QUdpSocket		*_sock;
	QHostAddress	_receiverIP;
	quint16			_receiverPort;
	QMutex			_lock;
};

#endif // UDPNETWORK_H
