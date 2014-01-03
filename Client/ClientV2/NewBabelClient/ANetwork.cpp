#include  <string>
#include  "ANetwork.hh"

ANetwork::ANetwork()
{
}

ANetwork::~ANetwork()
{
}

void  ANetwork::setErrorHandler(Function<void (enum ANetwork::SocketState)> handler)
{
  _onErrorHandler = handler;
}

void  ANetwork::setOnConnectHandler(Function<void ()> handler)
{
  _onConnectHandler = handler;
}

void  ANetwork::setAvailableData(Function<void (const ByteArray)> handler)
{
  _onAvailableData = handler;
}