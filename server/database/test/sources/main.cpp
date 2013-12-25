#include	<iostream>
#include	<fstream>
#include	<boost/bind.hpp>
#include	"Database.hh"
#include	"FriendRequest.hh"
#include	"MD5.hh"
#include	"UnitTest.hh"

const char	*red = "\033[22;31m";
const char	*green = "\033[22;32m";
const char	*reset = "\033[0m";

bool	unitTest(bool (*func)(Database &))
{
  Database	db;

  try
    {
      if (!func(db))
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
  format(unitTest(&request_test1), "easy test 4: Simple request");
}
