#include	<iostream>
#include	<fstream>
#include	"ProducterStream.hpp"

//////////////////////////////////////////
//		Producter Class		//
//////////////////////////////////////////

ProducterStream::ProducterStream() :
  stream(0), isFile(false)
{

}

ProducterStream::~ProducterStream()
{
  if (isFile)
    delete (this->stream);
}

bool		ProducterStream::loadFile(const char *path)
{
  std::ifstream	*newStream;

  newStream = new std::ifstream(path);
  if (!newStream->is_open())
    {
      delete newStream;
      return (false);
    }
  if (isFile)
    delete stream;
  isFile = true;
  stream = newStream;
  return (true);
}

bool		ProducterStream::loadStdin()
{
  if (isFile)
    delete stream;
  stream = &std::cin;
  isFile = false;
  return (true);
}

std::string	ProducterStream::nextString()
{
  char		extracted[maxReadBlock];

  if (stream == 0)
    throw std::runtime_error("Stream not initialized.");
  stream->read(extracted, maxReadBlock);
  if (stream->gcount() == 0)
    throw std::runtime_error("Stream is empty.");
  return (std::string(extracted, stream->gcount()));
}


ProducterStream::Exception::Exception(const std::string &what) throw():
  _what(what)
{
}

ProducterStream::Exception::~Exception() throw()
{
}

ProducterStream::Exception::Exception(const Exception &src) throw():
  _what(src._what)
{
}

ProducterStream::Exception	&ProducterStream::Exception::operator=(const Exception &src) throw()
{
  if (this != &src)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*ProducterStream::Exception::what() const throw()
{
  return (_what.c_str());
}
