#include	"IniParser.hh"

using namespace	parser;

Ini::Ini(bool strict) :
  ConsumerParser(_stream), _strict(strict)
{
  skipBlank(true);
}

bool	Ini::strict() const
{
  return (_strict);
}

void	Ini::strict(bool strict)
{
  _strict = strict;
}

Ini::~Ini()
{
}

bool	Ini::readKey(key &key)
{
#if defined(DEBUG)
  std::cout << "parser::Ini::readKey(): " << std::endl;
#endif
  return (readIdentifier(key));
}

bool	Ini::readValue(value &value)
{
#if defined(DEBUG)
  std::cout << "parser::Ini::readValue(): " << std::endl;
#endif
  if (peekChar('\"'))
    {
      readChar('\"');
      return (readUntil('\"', value));
    }
  return (readIdentifier(value) || readInteger(value));
}

bool	Ini::readVars(key &key, value &value)
{

#if defined(DEBUG)
  std::cout << "parser::Ini::readVars(): " << std::endl;
#endif
  if (!readKey(key))
    return (false);
  if (!readChar('='))
    return (false);
  if (!readValue(value))
    return (false);
#if defined(DEBUG)
  std::cout << "parser::Ini::readVars(): " << "Key: " << key << ", value: " << value << std::endl;
#endif
  readComment();
  return (true);
}

bool	Ini::readSection()
{
  std::string	identifier;
  key		key;
  value		value;

#if defined(DEBUG)
  std::cout << "parser::Ini::readSection(): " << std::endl;
#endif
  if (!readChar('['))
    return (false);
  if (!readIdentifier(identifier) ||
      (_strict && _output.find(identifier) == _output.end()))
    return (false);
  if (!readChar(']'))
    return (false);
#if defined(DEBUG)
  std::cout << "parser::Ini::readSection(): " << "Section Name: " << identifier << std::endl;
#endif
  while (readVars(key, value))
    {
      if (_strict && _output[identifier].find(key) == _output[identifier].end())
	return (false);
      _output[identifier][key] = value;
      key.clear();
      value.clear();
    }
  return (true);
}

bool		Ini::readComment()
{
  std::string	comment;

  if (!readChar('#'))
    return (false);
  skipBlank(false);
  readUntil('\n', comment);
  skipBlank(true);
  return (true);
}

bool	Ini::readIni()
{
#if defined(DEBUG)
  std::cout << "parser::Ini::readIni(): " << std::endl;
#endif
  while (!readEOF())
    {
      if (!readSection() && !readComment())
	throw Ini::Exception("Unable to read Section", *this);
    }
  return (true);
}

bool	Ini::loadFile(const std::string &filename)
{
  return (_stream.loadFile(filename.c_str()));
}

void	Ini::addSection(const section &section)
{
  _output[section] = key_val();
}

void	Ini::addKey(const section &section, const key &key)
{
  _output[section][key] = "";
}

bool	Ini::run()
{
  return (readIni());
}

const Ini::section_key_val	&Ini::output() const
{
  return (_output);
}

/////////////////////
// Exception Class //
/////////////////////

Ini::Exception::Exception(const std::string &what, Ini &ini) throw():
  ConsumerParser::Exception(what, ini)
{

}

Ini::Exception::Exception(const Ini::Exception &src) throw():
  ConsumerParser::Exception(src)
{
}

Ini::Exception::~Exception() throw()
{
}

Ini::Exception	&Ini::Exception::operator=(const Exception &src) throw()
{
  if (this != &src)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*Ini::Exception::what() const throw()
{
  return (_what.c_str());
}
