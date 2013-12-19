#ifndef APPLICATION_HH
#define APPLICATION_HH

#include  <QApplication>
#include  "IApplication.hh"
#include  "IGraphic.hh"
#include  "INetwork.hh"

class application : public IApplication
{
public:
  application(int ac, char *av[]);
  virtual ~application();

public:
  void  init();
  void  run();
  void  stop();

private:
  int           _ac;
  QApplication  _app;
  IGraphic      *_graph;
  INetwork      *_net;
};

#endif // APPLICATION_HH
