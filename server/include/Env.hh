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
  typedef long			minute;
  typedef long			second;
  typedef unsigned short	port;

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
    static const port			CLIENT_PORT;
    static const port			MIN_CLIENT_PORT;
    static const port			MAX_CLIENT_PORT;
    static const port			MAINTENANCE_PORT;
    static const port			MIN_MAINTENANCE_PORT;
    static const port			MAX_MAINTENANCE_PORT;

    static const file_path		CONF_PATH;

    port				ClientPort;
    port				MaintenancePort;
    file_path				confPath;
  }					server;

  struct				client
  {
    static const second			PONG_REFRESH;
    static const second			MIN_PONG_REFRESH;
    static const second			MAX_PONG_REFRESH;
    static const second			PONG_DELAY;
    static const second			MIN_PONG_DELAY;
    static const second			MAX_PONG_DELAY;

    second				pongDelay;
    second				pongRefresh;
  }					client;

  struct				database
  {
    static const file_path		DB_PATH;
    static const minute			AUTOSAVE_DB;
    static const minute			MIN_AUTOSAVE_DB;
    static const minute			MAX_AUTOSAVE_DB;

    file_path				DatabasePath;
    minute				AutosaveDB;
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

public:
  const file_path	rootPath() const;
  const file_path	databaseFilePath() const;

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
  void			set(long &, const parser::Ini::section &,
			    const parser::Ini::key &, const parser::Ini::section_key_val &,
			    long min = 0, long max = 0, long defaultVal = 0);
  template <typename T>
  void			set(T &, const parser::Ini::section &,
			    const parser::Ini::key &, const parser::Ini::section_key_val &,
			    T min, T max, T defaultVal);
  bool			isPluginSection(const parser::Ini::section &, const parser::Ini::key_val &);
  const file_path	resolveFilePath(const file_path &);
};


#endif /* ENV_H_ */
