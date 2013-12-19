#include  "application.hh"
#include  "graphic.hh"
#include  "network.hh"

application::application(int ac, char *av[]) :
  _ac(ac), _app(_ac, av), _graph(new graphic), _net(new network)
{
}

application::~application()
{
  
}

void  application::init()
{
  _net->init();
  _graph->init();
}

void  application::run()
{
  _net->run();
  _graph->run();
  _app.exec();
}

void  application::stop()
{

}
