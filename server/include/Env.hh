#ifndef ENV_H_
# define ENV_H_

# include	<string>
# include	<list>
# include	"IniParser.hh"

class Env
{
public:
  typedef std::string		plugin_name;
  typedef std::string		plugin_path;
  typedef std::string		file_path;
  typedef std::string		file_extension;

  struct	PluginDetail
  {
    PluginDetail(const plugin_name &name, const plugin_path path, bool used = false);

    plugin_name	name;
    plugin_path	path;
    bool	used;
  };

  typedef std::list<PluginDetail>	plugin_list;

  struct				server
  {
    static const unsigned short int	CLIENT_PORT	   =	44201;
    static const unsigned short int	MAINTENANCE_PORT   =	44202;

    static const file_path		CONF_PATH;

    unsigned short int			ClientPort;
    unsigned short int			MaintenancePort;
    file_path				confPath;
  }					server;

  struct				database
  {
    static const file_path		DB_PATH;

    file_path				DatabasePath;
  }					database;

  struct				plugin
  {
    static const file_path		LIBRARY_PATH;
    static const file_extension		LIBRARY_EXTENSION;

    file_path				LibraryPath;
    plugin_list				plugins;
  }					plugin;

public:
  static Env	&getInstance();

public:
  bool	loadFile(const std::string &);
  bool	loadFile();

private:
  Env();
  virtual ~Env();
  Env	&operator=(const Env &);
  Env(const Env &);

private:
  bool			loadPlugins(const parser::Ini::section_key_val &);
  template <typename T>
  void			set(T &, const parser::Ini::section &,
			    const parser::Ini::key &, const parser::Ini::section_key_val &);
  bool			isPluginSection(const parser::Ini::section &, const parser::Ini::key_val &);
  const file_path	resolveFilePath(const file_path &);
};


#endif /* ENV_H_ */
