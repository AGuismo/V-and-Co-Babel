#include	<iostream>
#include	<fstream>
#include	"Database.hh"
#include	"FriendRequest.hh"
#include	"MD5.hh"

bool	request_test1(Database &db)
{
  const char	*filename = "./misc/request_test1.db";
  request::friends::client::Request	req("toto", "tata");
  std::ofstream	ofs(filename, std::ifstream::trunc);

  db.drop();
  if (!ofs.is_open())
    throw std::runtime_error(std::string("can't open ") + filename);
  ofs.close();
  if (!db.newClient("toto", md5("poil")))
    return (false);
  if (!db.newClient("tata", md5("pwet")))
    return (false);
  if (!db.addRequest("toto", req))
    return (false);
  if (!db.saveFile(filename))
    return (false);
  if (!db.loadFile(filename))
    return (false);
  if (!db.clientExist("toto", md5("poil")))
    return (false);
  if (!db.clientExist("tata", md5("pwet")))
    return (false);
  if (!db.delRequest("toto", req))
    return (false);
  return (true);
}
