#include	"Application.hh"

#if defined(WIN32)
void	win32_symbol_loader();
#pragma comment(linker, "/include:??0Server@request@@IAE@G@Z") // protected: __thiscall request::Server::Server(unsigned short)
#pragma comment(linker, "/include:??1Server@request@@MAE@XZ") // protected: virtual __thiscall request::Server::~Server(void)
#pragma comment(linker, "/include:?getInstance@Database@@SAAAV1@XZ") // public: static class Database & __cdecl Database::getInstance(void)
#pragma comment(linker, "/include:?newClient@Database@@QAE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0EEE0_N@Z") // public: bool __thiscall Database::newClient(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,unsigned char,unsigned char,unsigned char,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,bool)
#pragma comment(linker, "/include:?clientExist@Database@@QAE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z") // public: bool __thiscall Database::clientExist(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &)
#endif
//#pragma comment(linker, "/include:") //

int	main(int ac, char *av[])
{
  Application	app;

#if defined(WIN32)
	win32_symbol_loader();
#endif
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
