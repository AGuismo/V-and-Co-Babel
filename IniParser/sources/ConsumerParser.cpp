#include	<sstream>
#include	<ctype.h>
#include	<cstring>
#include	<locale>
#include	<stdexcept>
#include	"ConsumerParser.hpp"
#include	"ProducterStream.hpp"

ConsumerParser::ConsumerParser(ProducterStream &stream) :
  _stream(stream), _isEOF(false)
{
  _inputData.reserve(1024);
  _rwHeader = _inputData.begin();
}

ConsumerParser::~ConsumerParser()
{

}

void	ConsumerParser::saveContext()
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::saveContext()" << std::endl;
#endif
  // std::cout << "~~~ Save context at pos " << std::distance(_inputData.begin(), _rwHeader)
  // 	    << " (Character : {" << *_rwHeader << "})" << std::endl;
  _contexts.push(_rwHeader);
}

void	ConsumerParser::restoreContext()
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::restoreContext()" << std::endl;
#endif
  _rwHeader = _contexts.top();
  _contexts.pop();
  // std::cout << "~~~ Restore context at pos " << std::distance(_inputData.begin(), _rwHeader)
  // 	    << " (Character : {" << *_rwHeader << "})" << std::endl;
  _isEOF = _rwHeader == _inputData.end();
}

bool		ConsumerParser::addData()
{
  std::string	out;

#if defined(DEBUG)
  std::cout << "ConsumerParser::addData()" << std::endl;
#endif
  try
    {
      out = _stream.nextString();
    }
  catch (const std::runtime_error &e)
    {
      (void)e;
      _isEOF = true;
#if defined(DEBUG)
      std::cout << "ConsumerParser::addData(): " << "Fail" << std::endl;
#endif
      return (false);
    }
  _inputData += out;
  return (true);
}

bool		ConsumerParser::skipBlanks()
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::skipBlanks(): " << std::endl;
#endif
  while (std::isspace(*_rwHeader, std::locale()))
    {
      _rwHeader++;
      if (_rwHeader == _inputData.end())
	if (!addData())
	  return (false);
    }
  return (true);
}

void		ConsumerParser::skipBlank(bool skipped)
{
  _skipBlank = skipped;
}

bool		ConsumerParser::readText(char *text)
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::readText(): " << std::endl;
#endif
  saveContext();
  if (_skipBlank)
    skipBlanks();
  while ((std::size_t)std::distance(_rwHeader, _inputData.end()) < ::strlen(text))
    {
      if (!addData())
	{
	  restoreContext();
	  return (false);
	}
    }
  if (std::string(_rwHeader, _rwHeader + ::strlen(text)) == text)
    {
      _rwHeader += ::strlen(text);
      return (true);
    }
  restoreContext();
  return (false);
}

bool		ConsumerParser::readEOF()
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::readEOF(): " << std::endl;
#endif
  if (_skipBlank)
    skipBlanks();
  if (_isEOF && _rwHeader == _inputData.end())
    return (true);
  return (false);
}

bool		ConsumerParser::readUntil(char c, std::string &output)
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::readUntil(): " << std::endl;
#endif
  if (_rwHeader == _inputData.end() && !addData())
    return (false);
  saveContext();
  if (_skipBlank)
    skipBlanks();
  while (*_rwHeader != c)
    {
      output.push_back(*_rwHeader);
      _rwHeader++;
      if (_rwHeader == _inputData.end() && !addData())
	{
	  restoreContext();
	  output.clear();
	  return (false);
	}
    }
  _rwHeader++;
  return (true);
}

bool		ConsumerParser::readUntilEOF()
{
  while (addData());
  _rwHeader = _inputData.end();
  return (true);
}

bool		ConsumerParser::readInteger(std::string &output)
{
  bool		isNum = false;

#if defined(DEBUG)
  std::cout << "ConsumerParser::readInteger(): " << std::endl;
#endif
  saveContext();
  if (_skipBlank)
    skipBlanks();
  while (true)
    {
      if (_rwHeader == _inputData.end() && !addData())
	break;
      if (!std::isdigit(*_rwHeader, std::locale()))
      	break;
      isNum = true;
      output.push_back(*_rwHeader);
      _rwHeader++;
    }
  if (isNum)
    return (true);
  restoreContext();
  return (false);
}

bool		ConsumerParser::readIdentifier(std::string &output)
{
#if defined(DEBUG)
  std::cout << "ConsumerParser::readIdentifier(): " << std::endl;
#endif
  if (_rwHeader == _inputData.end() && !addData())
    return (false);
  saveContext();
  if (_skipBlank)
    skipBlanks();
  if (!(std::isalpha(*_rwHeader, std::locale()) || *_rwHeader == '_'))
    {
      restoreContext();
      return (false);
    }
  output.push_back(*_rwHeader);
  ++_rwHeader;
  while (true)
    {
      if (_rwHeader == _inputData.end() && !addData())
	break;
      if (!(std::isalnum(*_rwHeader, std::locale()) || *_rwHeader == '_'))
	break;
      output.push_back(*_rwHeader);
      ++_rwHeader;
    }
  return (true);
}

/////////////////////
// Exception Class //
/////////////////////

ConsumerParser::Exception::Exception(const std::string &what, ConsumerParser &parser) throw():
  _what(what)
{
  std::string::iterator	begin_line = parser._rwHeader;
  std::string::iterator	end_line = parser._rwHeader;
  std::string		line;
  std::string		arrow;
  std::size_t		linum = 0;
  std::stringstream	ss;

  while (begin_line != parser._inputData.begin() && *begin_line != '\n')
    --begin_line;
  while (end_line != parser._inputData.end() && *end_line != '\n')
    ++end_line;
  for (std::string::iterator it = parser._inputData.begin(); it != parser._rwHeader; ++it)
    {
      if (*it == '\n')
	linum++;
    }
  line.assign(begin_line, end_line);
  arrow.append(std::distance(begin_line, parser._rwHeader), '-');
  arrow.append("^");
  ss << "Error at line " << linum << std::endl << line << std::endl << arrow << std::endl;
  _what = ss.str();
}

ConsumerParser::Exception::Exception(const ConsumerParser::Exception &src) throw():
  _what(src._what)
{
}

ConsumerParser::Exception::~Exception() throw()
{
}

ConsumerParser::Exception	&ConsumerParser::Exception::operator=(const Exception &src) throw()
{
  if (this != &src)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*ConsumerParser::Exception::what() const throw()
{
  return (_what.c_str());
}
