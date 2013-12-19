#ifndef ISIGNALER_HH
#define ISIGNALER_HH

class IConnect
{
  virtual void  send_signal() = 0;
  virtual void  receive_signal() = 0;
};

#endif // ISIGNALER_HH
