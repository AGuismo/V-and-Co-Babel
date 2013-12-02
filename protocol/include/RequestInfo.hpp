#ifndef REQUESTINFO_H_
# define REQUESTINFO_H_

# include	<map>
# include	"RequestCode.hh"
# include	"ServerRequest.hh"

namespace	request
{
  // struct	detail
  // {
  //   static const char	*OK;
  //   static const char	*BAD_REQ;
  //   static const char	*FORBIDDEN;
  //   static const char	*NOT_IMPLEMENTED;
  //   static const char	*NO_CONTENT;
  //   static const char	*PARTIAL_CONTENT;
  //   static const char	*NO_SLOTS;
  // };

  template <typename T> struct	Info;

  template <> struct Info<server::Ok> {static const char *detail(void) {return (server::Ok::OK);}};
}

#endif /* REQUESTINFO_H_ */
