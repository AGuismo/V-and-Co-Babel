#ifndef ENV_H_
# define ENV_H_

# include	<string>

class Env
{
public:
  struct
  {
    unsigned short int			Port;
    std::string				DatabasePath;
    std::string				LibraryPath;
    std::string				confPath;
  }					server;
  static const unsigned short int	PORT     =	44201;
  static const std::string		DB_PATH;
  static const std::string		LIBRARY_PATH;
  static const std::string		CONF_PATH;

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
};


#endif /* ENV_H_ */
