#include  "TCPNetwork.hh"

TCPNetwork::TCPNetwork()
{

}

TCPNetwork::~TCPNetwork()
{

}

void  TCPNetwork::init()
{

}

void  TCPNetwork::run()
{

}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  _sock.connectToHost(QString(ipAddress.c_str()), port);
  if (_sock.waitForConnected())
    _onConnectHandler();
  else
    _onErrorHandler((int)_sock.error());
}
