#include	<iostream>
#include	"Maintenance.hh"
#include	"Application.hh"
#include	"Env.hh"

Application::Application():
  _server(_service, _database), _maintenance(_service, _adm)
{
}

Application::~Application()
{
  _database.saveFile(Env::getInstance().rootPath() + Env::getInstance().database.DatabasePath);
}

void	Application::init(const char *confPath)
{
  _adm.registerShutdownServer(Function<const std::string ()>(&Application::shutdownServer, this));
  _adm.registerDropDB(Function<const std::string ()>(&Application::dropDB, this));
  _adm.registerSaveDB(Function<const std::string ()>(&Application::saveDB, this));
  try
    {
      if (confPath == 0)
	{
	  if (!Env::getInstance().loadFile())
	    {
	      std::cerr << "Error while loading conf file" << std::endl;
	      return ;
	    }
	}
      else
	{
	  if (!Env::getInstance().loadFile(confPath))
	    {
	      std::cerr << "Error while loading conf file" << std::endl;
	      return ;
	    }
	}
      _database.loadFile(Env::getInstance().rootPath() + Env::getInstance().database.DatabasePath);
      _server.init();
      _maintenance.init();
    }
  catch (const Server::Exception &e)
    {
      std::cerr << "Failed to load due to Server init exception: "
		<< e.what() << std::endl;
      throw InitExcept("Unable to load Application");
    }
  catch (const Maintenance::Exception &e)
    {
      std::cerr << "Warning: Failed to load due to Maintenance init exception: "
		<< e.what() << std::endl
		<< "The maintenance service will no be available." << std::endl;
    }
  catch (...)
    {
      std::cerr << "An exception has occured" << std::endl;
      throw InitExcept("Unable to load Application");
    }
}

void	Application::run()
{
  _service.run();
}

void	Application::shutdown()
{
  _service.stop();
}

const std::string	Application::shutdownServer()
{
  shutdown();
  return ("Shutdown the server NOW !");
}

const std::string	Application::dropDB()
{
  if (_database.drop())
    return ("Database Successfully dropped.");
  return ("An error Occured when dropping Database.");
}

const::std::string	Application::saveDB()
{
  if (_database.saveFile(Env::getInstance().rootPath() + Env::getInstance().database.DatabasePath))
    return ("Database Successfully saved.");
  return ("An error Occured when saving Database.");
}

///////////////////////
//  Exception Class  //
///////////////////////
Application::InitExcept::InitExcept(const std::string &msg) throw() :
  _what(msg)
{

}

Application::InitExcept::InitExcept (const Application::InitExcept &src) throw() :
  _what(src._what)
{

}

Application::InitExcept::~InitExcept() throw()
{

}

Application::InitExcept& Application::InitExcept::operator=(Application::InitExcept const &src) throw()
{
  if (&src != this)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*Application::InitExcept::what() const throw()
{
  return (_what.c_str());
}
