#pragma once
# include	<vector>
# include	<map>
# include	<string>
# include	"Function.hpp"

class Administrator
{
public:
  typedef std::string					buffer;
  typedef std::vector<buffer>				args;
  typedef void (Administrator::*callback)(const args &, buffer &);
  typedef std::map<std::string, callback> callback_map;

public:
  static const std::string			BAD_REQUEST;
  static const std::string			OK;
  static const std::string			CONTENT;
  static const std::string			NOT_IMPLEMENT;

private:
  void	shutdown(const args &, buffer &response);
  void	dropDB(const args &, buffer &response);
  void	saveDB(const args &, buffer &response);
  void	help(const args &, buffer &response);
  void	dumpDB(const args &, buffer &response);

public:
  void	registerShutdownServer(Function<const std::string ()>);
  void	registerDropDB(Function<const std::string ()>);
  void	registerSaveDB(Function<const std::string ()>);
  void	registerDumpDB(Function<const std::string ()>);
  const std::string	ignoreCb();

public:
  Administrator();
  ~Administrator();
  void	operator()(const args &, buffer &response);

private:
  callback_map		_calls;
  Function<const std::string ()>	_shutdownServerHandler;
  Function<const std::string ()>	_dropDBHandler;
  Function<const std::string ()>	_saveDBHandler;
  Function<const std::string ()>	_dumpDBHandler;
};
