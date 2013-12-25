#include	<iostream>
#include	<fstream>
#include	"Database.hh"
#include	"FriendRequest.hh"
#include	"MD5.hh"

bool	single_user(Database &db)
{
  const char	*filename = "./misc/single_user.db";
  std::ofstream	ofs(filename, std::ifstream::trunc);

  db.drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (!db.newClient("toto", md5("poil")))
    return (false);
  if (!db.saveFile(filename))
    return (false);
  if (!db.loadFile(filename))
    return (false);
  if (!db.clientExist("toto", md5("poil")))
    return (false);
  return (true);
}
