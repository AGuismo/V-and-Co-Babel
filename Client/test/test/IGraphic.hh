#ifndef IGRAPHIC_HH
#define IGRAPHIC_HH

class IGraphic
{
public:
  virtual ~IGraphic() {}

public:
  virtual void  init() = 0;
  virtual void  run() = 0;
};

#endif // IGRAPHIC_HH
