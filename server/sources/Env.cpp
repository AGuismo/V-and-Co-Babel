#include	"IniParser.hh"
#include	"Env.hh"

const std::string	Env::CONF_PATH		= "./misc/conf.ini";
const std::string	Env::DB_PATH		= "./";
const std::string	Env::LIBRARY_PATH	= "./lib";

Env::Env()
{
  server.Port = PORT;
  server.DatabasePath = DB_PATH;
  server.LibraryPath = LIBRARY_PATH;
  server.confPath = CONF_PATH;
}

Env::~Env()
{

}

Env		&Env::getInstance()
{
  static Env	*self = new Env;

  return (*self);
}

bool		Env::loadFile()
{
  parser::Ini	ini(false);

  if (!ini.loadFile(server.confPath))
    {
      std::cerr << "Unable to open conf file(" << server.confPath << ")" << std::endl;
      return (false);
    }
  try
    {
      ini.run();
    }
  catch (const parser::Ini::Exception &e)
    {
      std::cerr << "Unable to load properly conf file (" << server.confPath << ")" << std::endl
		<< e.what() << std::endl;
      return (false);
    }
  return (true);
}

bool		Env::loadFile(const std::string &file)
{
  server.confPath = file;
  return (loadFile());
}
