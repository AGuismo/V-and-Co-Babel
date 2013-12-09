#include	<iostream>
#include	"Application.hh"

Application::Application():
  _server(_service)
{
}

Application::~Application()
{
}

void	Application::init()
{
  try
    {
      _server.init();
    }
  catch (const Server::Exception &e)
    {
      std::cerr << "Failed to load due to Server init exception: "
		<< e.what() << std::endl;
      throw InitExcept("Unable to load Application");
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
