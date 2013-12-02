#include	<typeinfo>
#include	"RequestFactory.hh"
#include	"Protocol.hpp"
#include	"ARequest.hh"

namespace	request
{

  Factory::Factory()
  {
  }

  Factory::~Factory()
  {

  }

  Factory	&Factory::getInstance()
  {
    static Factory	f;

    return (f);
  }

  ARequest		*Factory::factory(Protocol &p, const request::ID code)
  {
    Factory		&f = Factory::getInstance();
    lnk_type::iterator	it;
    ARequest		*req;

    if ((it = f._lnk.find(code)) == f._lnk.end())
      throw ARequest::Exception("Invalid Code");
    req = it->second->clone();
    req->unserialize(p);
    return (req);
  }

  void			Factory::factory(Protocol &p, const ARequest &output)
  {
    output.serialize(p);
  }

}
