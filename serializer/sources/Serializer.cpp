#include	<iostream>
#include	"Serializer.hpp"

Serializer::Serializer():
  _data(0)
{

}

Serializer::~Serializer()
{
  delete [] _data;
}

Serializer::Serializer(const Serializer &src) :
  _container(src._container)
{
}

Serializer	&Serializer::operator=(const Serializer &src)
{
  if (&src != this)
    {
      _container = src._container;
    }
  return (*this);
}

Rbool	Serializer::empty() const
{
  return (_container.empty());
}

Ruint32	Serializer::size() const
{
  return (_container.size());
}

Serializer::Byte		*Serializer::data()
{
  const size_type	size = _container.size();

  delete [] _data;
  _data = new Byte[size];
  for (size_type it = 0; it < size; ++it)
    {
      _data[it] = _container[it];
    }
  return (_data);
}

Serializer::container_type const	&Serializer::content() const
{
  return (_container);
}

#define LC(T, val)				\
  <<(const T val)				\
  {						\
    push(val, 1);				\
    return (*this);				\
  }

#define RC(T, val)				\
  >>(T& val)					\
  {						\
    pop(val);					\
    return (*this);				\
  }

Serializer&	Serializer::operator LC(Rint8, val);
Serializer&	Serializer::operator LC(Rint16, val);
Serializer&	Serializer::operator LC(Rint32, val);
Serializer&	Serializer::operator LC(Ruint8, val);
Serializer&	Serializer::operator LC(Ruint16, val);
Serializer&	Serializer::operator LC(Ruint32, val);
Serializer&	Serializer::operator LC(Rdouble, val);
Serializer&	Serializer::operator LC(Rfloat, val);

Serializer&	Serializer::operator RC(Rint8, val);
Serializer&	Serializer::operator RC(Rint16, val);
Serializer&	Serializer::operator RC(Rint32, val);
Serializer&	Serializer::operator RC(Ruint8, val);
Serializer&	Serializer::operator RC(Ruint16, val);
Serializer&	Serializer::operator RC(Ruint32, val);
Serializer&	Serializer::operator RC(Rdouble, val);
Serializer&	Serializer::operator RC(Rfloat, val);


std::string	Serializer::push(const std::string val)
{
  const Byte*	buffer = reinterpret_cast<const Byte*>(val.c_str());
  size_type	total = sizeof(*val.c_str()) * val.size();

  for (size_t size = 0; size < total; size += sizeof(Byte))
    {
      _container.push_back(buffer[size]);
    }
  return (val);
}

std::string	Serializer::push(const std::string val, size_type count)
{
  const Byte*	buffer = reinterpret_cast<const Byte*>(val.c_str());
  size_type	total = sizeof(*val.c_str()) * count;

  for (size_t size = 0; size < total; size += sizeof(Byte))
    {
      _container.push_back(buffer[size]);
    }
  return (val);
}

std::string		&Serializer::pop(std::string &val, size_type count)
{
  size_type	total = sizeof(*val.c_str()) * count;

  if (total > _container.size())
    throw invalid_argument("Not enough size");
  val.assign(_container.begin(), _container.begin() + count);
  _container.erase(_container.begin(), _container.begin() + total);
  return (val);
}

Serializer::invalid_argument::invalid_argument(const std::string &what) throw() :
  _what(what)
{

}

Serializer::invalid_argument::~invalid_argument() throw()
{

}

Serializer::invalid_argument::invalid_argument(invalid_argument const &src) throw() :
  _what(src._what)
{

}

Serializer::invalid_argument	&Serializer::invalid_argument::operator=(invalid_argument const & src) throw()
{
  if (this != &src)
    {
      _what = src._what;
    }
  return (*this);
}

const char		*Serializer::invalid_argument::what() const throw()
{
  return (_what.c_str());
}
