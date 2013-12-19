#ifndef NETWORK_HH
#define NETWORK_HH

# include "INetwork.hh"

class network : public INetwork
{
public:
  network();
  virtual ~network();

public:
  void  init();
  void  run();
};

#endif // NETWORK_HH
