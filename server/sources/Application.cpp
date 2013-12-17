#include	<iostream>
#include	"Maintenance.hh"
#include	"Application.hh"
#include	"Env.hh"

Application::Application():
  _server(_service), _maintenance(_service)
{
}

Application::~Application()
{
}

void	Application::init(const char *confPath)
{
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
