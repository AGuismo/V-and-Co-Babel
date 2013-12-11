#include	<typeinfo>
#include	"RequestFactory.hh"
#include	"Protocol.hpp"
#include	"ARequest.hh"
#include	"FriendRequest.hh"
#include	"ServerRequest.hh"
#include	"ChatRequest.hh"
#include	"AuthRequest.hh"

namespace	request
{

  Factory::Factory()
  {
    _lnk[request::server::OK] = new request::server::Ok;
    _lnk[request::server::BAD_REQ] = new request::server::BadRequest;
    _lnk[request::server::FORBIDDEN] = new request::server::Forbidden;
    _lnk[request::server::NOT_IMPLEMENTED] = new request::server::NotImplemented;
    _lnk[request::server::NO_CONTENT] = new request::server::NoContent;
    _lnk[request::server::PARTIAL_CONTENT] = new request::server::PartialContent;
    _lnk[request::server::NO_SLOTS] = new request::server::NoSlots;

    _lnk[request::client::auth::NEW] = new request::auth::client::NewClient;
    _lnk[request::client::auth::REMOVE] = new request::auth::client::DelClient;
    _lnk[request::client::auth::MODIFY] = new request::auth::client::ModifyClient;
    _lnk[request::client::auth::CONNECT] = new request::auth::client::ConnectClient;
    _lnk[request::client::auth::DISCONNECT] = new request::auth::client::DisconnectClient;

    _lnk[request::server::friends::UPDATE] = new request::friends::server::Update;
    _lnk[request::client::friends::REQUEST] = new request::friends::client::Request;
    _lnk[request::client::friends::DEL_FRIEND] = new request::friends::client::DelFriend;
    _lnk[request::client::friends::ACCEPT] = new request::friends::client::Accept;
    _lnk[request::client::friends::REFUSE] = new request::friends::client::Refuse;
    _lnk[request::client::friends::LIST] = new request::friends::client::List;

    _lnk[request::client::chat::MESSAGE] = new request::chat::client::Message;
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

  ARequest		*Factory::factory(const request::ID code)
  {
    Factory		&f = Factory::getInstance();
    lnk_type::iterator	it;
    ARequest		*req;

    if ((it = f._lnk.find(code)) == f._lnk.end())
      throw ARequest::Exception("Invalid Code");
    req = it->second->clone();
    return (req);
  }

  void			Factory::factory(Protocol &p, const ARequest &output)
  {
    output.serialize(p);
  }

}
