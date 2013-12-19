#ifndef INETWORK_HH
#define INETWORK_HH

class INetwork
{
public:
  virtual ~INetwork() {}

public:
  virtual void  init() = 0;
  virtual void  run() = 0;
  virtual void  setOnConnectHandler(function<void  (int)>) = 0;
};

#endif // INETWORK_HH
