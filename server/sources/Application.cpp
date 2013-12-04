#include	<iostream>
#include	"Application.hh"

Application::Application()
{
}

Application::~Application()
{
}

void	Application::init()
{
  try
    {

    }
  catch (...)
    {
      std::cerr << "An exception has occured" << std::endl;
      throw InitExcept("Unable to load Application");
    }
}

void	Application::run()
{
  service.run();
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
