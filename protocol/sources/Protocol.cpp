#include	<iostream>
#include	"RequestFactory.hh"
#include	"Protocol.hpp"

Protocol::Protocol()
{

}

Protocol::~Protocol()
{
}

Protocol::Protocol(const Serializer &src)
{
  _container = src.content();
}

ARequest		*Protocol::consume(const serialized_data &input, int &extracted)
{
  Protocol		p;
  request::ID		code;
  ARequest		*req;

#if defined(DEBUG)
  std::cerr << "Protocol::consume(): " << input.size() << std::endl;
#endif
  p._container.clear();
  p._container.insert(p._container.begin(), input.begin(), input.end());
  p >> code;
#if defined(DEBUG)
  std::cout << "Protocol::consume(): " << "Request id -" << code << "- Contruction..." << std::endl;
#endif
  try
    {
      req = request::Factory::factory(p, code);
    }
  catch (const Serializer::invalid_argument &e)
    {
      throw ConstructRequest(e.what());
    }
  catch (const ARequest::Exception &e)
    {
      throw ConstructRequest(e.what());
    }
  extracted = input.size() - p._container.size();
  req->code(code);
#if defined(DEBUG)
  std::cout << "Protocol::consume(): " << "Request id -" << code << "- Complete" << std::endl;
#endif
  return (req);
}

Protocol::serialized_data	Protocol::product(const ARequest &output)
{
  Protocol		p;
  serialized_data	bytes;

#if defined(DEBUG)
  std::cout << "Protocol::product(): " << "Request id -" << output.code() << "- Contruction..." << std::endl;
#endif

  p._container.clear();
  request::Factory::factory(p, output);
  bytes.insert(bytes.begin(), p._container.begin(), p._container.end());
#if defined(DEBUG)
  std::cout << "Protocol::product(): " << "Request id -" << output.code() << "- Complete" << std::endl;
#endif
  return (bytes);
}

Protocol::ConstructRequest::ConstructRequest(const std::string &what) throw() :
  Serializer::invalid_argument(what)
{

}

Protocol::ConstructRequest::~ConstructRequest() throw()
{

}

Protocol::ConstructRequest::ConstructRequest(ConstructRequest const &src) throw() :
  Serializer::invalid_argument(src)
{

}

Protocol::ConstructRequest	&Protocol::ConstructRequest::operator=(ConstructRequest const & src) throw()
{
  if (this != &src)
    {
      _what = src._what;
    }
  return (*this);
}

const char		*Protocol::ConstructRequest::what() const throw()
{
  return (_what.c_str());
}
