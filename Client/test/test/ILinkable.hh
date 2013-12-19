#ifndef ILINKABLE_HH
#define ILINKABLE_HH

class ILinkable
{
  virtual ~ILinkable() {}

  virtual void  signal() = 0;
  virtual void  slot() = 0;
};

#endif // ILINKABLE_HH
