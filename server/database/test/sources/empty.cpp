#include	<iostream>
#include	<fstream>
#include	"Database.hh"
#include	"FriendRequest.hh"
#include	"MD5.hh"

bool	empty(Database &db)
{
  const char	*filename = "./misc/empty.db";
  std::ofstream	ofs(filename, std::ifstream::trunc);

  db.drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (db.loadFile(filename))
    return (false);
  return (true);
}
