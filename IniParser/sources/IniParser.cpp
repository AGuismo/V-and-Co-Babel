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
  if (!readIdentifier(identifier) || _output.find(identifier) == _output.end())
    return (false);
  if (!readChar(']'))
    return (false);
#if defined(DEBUG)
  std::cout << "parser::Ini::readSection(): " << "Section Name: " << identifier << std::endl;
#endif
  while (readVars(key, value))
    {
      if (_output[identifier].find(key) == _output[identifier].end())
	return (false);
      _output[identifier][key] = value;
      key.clear();
      value.clear();
    }
  return (true);
}

bool	Ini::readIni()
{
#if defined(DEBUG)
  std::cout << "parser::Ini::readIni(): " << std::endl;
#endif
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
