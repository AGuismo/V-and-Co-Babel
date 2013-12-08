#ifndef REQUESTINFO_H_
# define REQUESTINFO_H_

# include	<map>
# include	"RequestCode.hh"
# include	"ServerRequest.hh"

namespace	request
{

  template <typename T> struct	Info;

  template <> struct Info<server::Ok> {static const char *detail(void) {return (server::Ok::OK);}};
}

#endif /* REQUESTINFO_H_ */
