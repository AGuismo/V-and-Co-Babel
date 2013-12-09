#include	"PluginManager.hpp"

///////////////////////
//  Exception Class  //
///////////////////////
plugin::Exception::Exception(const std::string &msg) throw() :
  _what(msg)
{

}

plugin::Exception::Exception(const plugin::Exception &src) throw() :
  _what(src._what)
{

}

plugin::Exception::~Exception() throw()
{

}

plugin::Exception& plugin::Exception::operator=(plugin::Exception const &src) throw()
{
  if (&src != this)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*plugin::Exception::what() const throw()
{
  return (_what.c_str());
}
