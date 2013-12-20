#include  "ANetwork.hh"

ANetwork::ANetwork()
{

}

ANetwork::~ANetwork()
{

}

void  ANetwork::setErrorHandler(Function<void (int)> handler)
{
  _onErrorHandler = handler;
}

void  ANetwork::setOnConnectHandler(Function<void ()> handler)
{
  _onConnectHandler = handler;
}

void  ANetwork::setAvailableData(Function<void (const std::string)> handler)
{
  _onAvailableData = handler;
}