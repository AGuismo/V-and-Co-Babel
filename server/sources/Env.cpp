#include	<sstream>
#include	<boost/filesystem.hpp>
#include	"IniParser.hh"
#include	"Env.hh"

const Env::file_path	Env::server::CONF_PATH		= "./misc/conf.ini";
const Env::file_path	Env::database::DB_PATH		= "./babel.db";
const Env::file_path	Env::plugin::LIBRARY_PATH	= "./lib";

#if defined(WIN32)
const Env::file_extension	Env::plugin::LIBRARY_EXTENSION =	".dll";
#elif defined(linux)
const Env::file_extension	Env::plugin::LIBRARY_EXTENSION =	".so";
#else
# error "Unsupported operating system"
#endif

Env::Env()
{
  server.Port = server::PORT;
  server.confPath = server::CONF_PATH;
  database.DatabasePath = database::DB_PATH;
  plugin.LibraryPath = plugin::LIBRARY_PATH;
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
  set(server.Port, "server", "PORT", ini.output());
  set(database.DatabasePath, "database", "PATH", ini.output());
  set(plugin.LibraryPath, "plugin", "PATH", ini.output());
  return (loadPlugins(ini.output()));
}

bool		Env::isPluginSection(const parser::Ini::section &sectionName,
				     const parser::Ini::key_val &sectionKeys)
{
  if (sectionName == "database" || sectionName == "server" || sectionName == "plugin")
    return (false);
  for (parser::Ini::key_val::const_iterator itKeys = sectionKeys.begin();
       itKeys != sectionKeys.end(); ++itKeys)
    {
      if (itKeys->first == "TYPE" && itKeys->second == "plugin")
	return (true);
    }
  return (false);
}

const Env::file_path		Env::resolveFilePath(const Env::file_path &file)
{
  boost::filesystem::path	p(server.confPath);
  std::stringstream		ss;

  ss << p.parent_path().c_str() << "/" << plugin.LibraryPath << "/"
     << file << plugin::LIBRARY_EXTENSION;
  return (ss.str());
}

bool		Env::loadPlugins(const parser::Ini::section_key_val &fileKeys)
{
  for (parser::Ini::section_key_val::const_iterator itSect = fileKeys.begin();
       itSect != fileKeys.end(); ++itSect)
    {
      if (isPluginSection(itSect->first, itSect->second))
	{
	  if (itSect->second.find("NAME") == itSect->second.end())
	    {
	      std::cerr << "Ini Warning: Can't load " << itSect->first << std::endl
			<< "Detail: There is no \"NAME\" key." << std::endl;
	      continue;
	    }
	  if (itSect->second.find("USED") != itSect->second.end() &&
	      itSect->second.find("USED")->second == "yes")
	    plugin.plugins.push_back(PluginDetail(itSect->second.find("NAME")->second,
						  resolveFilePath(itSect->second.find("NAME")->second),
						  true));
	  else
	    plugin.plugins.push_back(PluginDetail(itSect->second.find("NAME")->second,
						  resolveFilePath(itSect->second.find("NAME")->second)));
	}
    }
  return (true);
}

bool		Env::loadFile(const std::string &file)
{
  server.confPath = file;
  return (loadFile());
}

template <typename T>
void			Env::set(T &value, const std::string &section,
				 const std::string &key, const parser::Ini::section_key_val &fileKeys)
{
  std::stringstream	ss;

  if (fileKeys.find(section) != fileKeys.end() &&
      fileKeys.find(section)->second.find(key) != fileKeys.find(section)->second.end())
    {
      ss << fileKeys.find(section)->second.find(key)->second;
      ss >> value;
    }
}

Env::PluginDetail::PluginDetail(const plugin_name &name, const plugin_path path, bool used):
  name(name), path(path), used(used)
{

}
