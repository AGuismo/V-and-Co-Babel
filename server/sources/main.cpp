#include	"Application.hh"

int	main(int ac, char *av[])
{
  Application	app;

  try
    {
      if (ac == 2 && std::string(av[1], 7) == std::string("--conf="))
	app.init(std::string(av[1]).substr(7).c_str());
      else
	app.init();
    }
  catch (const Application::InitExcept &e)
    {
      std::cerr << e.what() << std::endl;
#if defined(WIN32)
	  system("pause");
#endif
      return (0);
    }
  app.run();
  app.shutdown();
#if defined(WIN32)
  char	path[1024];
  GetCurrentDirectory(1024, path);
  std::cout << path << std::endl;
  system("pause");
#endif
  return(0);
}
