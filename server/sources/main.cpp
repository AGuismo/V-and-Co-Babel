#include	"Application.hh"

int	main()
{
  Application	app;

  try
    {
      app.init();
    }
  catch (const Application::InitExcept &e)
    {
      std::cerr << e.what() << std::endl;
      return (0);
    }
  app.run();
  app.shutdown();
  return (0);
}
