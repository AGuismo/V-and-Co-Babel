#include	"IniParser.hh"

using namespace	parser;

Ini::Ini() :
  ConsumerParser(_stream)
{
  skipBlank(true);
}

Ini::~Ini()
{
}

bool	Ini::readKey(key &key)
{
  return (readIdentifier(key));
}

bool	Ini::readValue(value &value)
{
  if (peekChar('\"'))
    {
      readChar('\"');
      return (readUntil('\"', value));
    }
  else
    return (readIdentifier(value));
}

bool	Ini::readVars()
{
  key	key;
  value	value;

  if (!readKey(key))
    return (false);
  if (!readChar('='))
    return (false);
  if (!readValue(value))
    return (false);
  return (true);
}

bool	Ini::readSection()
{
  std::string	identifier;

  if (!readChar('['))
    return (false);
  if (!readIdentifier(identifier) && _output.find(identifier) == _output.end())
    return (false);
  if (!readChar(']'))
    return (false);
  while (readVars());
  return (true);
}

bool	Ini::readIni()
{
  while (!readEOF())
    {
      if (!readSection())
	return (false);
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
