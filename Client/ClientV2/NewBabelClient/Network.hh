#ifndef INETWORK_HH
# define INETWORK_HH

# include		"Network.hh"
# include		<QtNetwork>


class Network : public ANetwork
{
private:
	QTcpSocket				_tcpSocket;

public slots:
	void					onConnect();
	void					onError(QAbstractSocket::SocketError socketError);

public:
	Network();

public:
	~INetwork() {}

private:
	Network(const Network &);
	Network					&operator=(const Network &);
};

#endif // INETWORK_HH
