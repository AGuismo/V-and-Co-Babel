#include	<iostream>
#include	<fstream>
#include	<boost/bind.hpp>
#include	"Database.hh"
#include	"MD5.hh"

const char	*red = "\033[22;31m";
const char	*green = "\033[22;32m";
const char	*reset = "\033[0m";

bool	empty()
{
  const char	*filename = "./misc/empty.db";
  std::ofstream	ofs(filename, std::ifstream::trunc);

  Database::getInstance().drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (Database::getInstance().loadFile(filename))
    return (false);
  return (true);
}

bool	single_user()
{
  const char	*filename = "./misc/single_user.db";
  std::ofstream	ofs(filename, std::ifstream::trunc);

  Database::getInstance().drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (!Database::getInstance().newClient("toto", md5("poil")))
    return (false);
  if (!Database::getInstance().saveFile(filename))
    return (false);
  if (!Database::getInstance().loadFile(filename))
    return (false);
  if (!Database::getInstance().clientExist("toto", md5("poil")))
    return (false);
  return (true);
}

bool	multiple_users()
{
  const char	*filename = "./misc/multiple_users.db";
  std::ofstream	ofs(filename, std::ifstream::trunc);

  Database::getInstance().drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (!Database::getInstance().newClient("toto", md5("poil")))
    return (false);
  if (!Database::getInstance().newClient("tata", md5("pwet")))
    return (false);
  if (!Database::getInstance().saveFile(filename))
    return (false);
  if (!Database::getInstance().loadFile(filename))
    return (false);
  if (!Database::getInstance().clientExist("toto", md5("poil")))
    return (false);
  if (!Database::getInstance().clientExist("tata", md5("pwet")))
    return (false);
  return (true);
}

bool	unitTest(bool (*func)())
{
  try
    {
      if (!func())
	return (false);
    }
  catch (const std::runtime_error &e)
    {
      std::cerr << red << "Error: " << reset << e.what() << std::endl;
      return (false);
    }
  return (true);
}

void	format(bool result, const std::string &detail)
{
  if (result)
    std::cout << detail << ": " << green << "Success" << reset << std::endl;
  else
    std::cout << detail << ": " << red << "Failure" << reset << std::endl;
}

int	main()
{
  format(unitTest(&empty), "easy test 1: empty file");
  format(unitTest(&single_user), "easy test 2: Single user");
  format(unitTest(&multiple_users), "easy test 3: Mutiple users");
}
