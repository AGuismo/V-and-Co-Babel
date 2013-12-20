#ifndef IAPPLICATION_HH
#define IAPPLICATION_HH

class IApplication
{
public:
  virtual ~IApplication() {}

public:
  virtual void  run() = 0;
  virtual void  init() = 0;
  virtual void  stop() = 0;
};

#endif // IAPPLICATION_HH
