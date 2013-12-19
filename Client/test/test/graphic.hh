#ifndef GRAPHIC_HH
#define GRAPHIC_HH

# include <QMainWindow>
# include "IGraphic.hh"

class graphic : public QMainWindow, public IGraphic
{
  Q_OBJECT

public:
  graphic();
  virtual ~graphic();

public:
  void  init();
  void  run();
};

#endif // GRAPHIC_HH
