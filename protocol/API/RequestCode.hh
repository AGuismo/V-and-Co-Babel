#ifndef REQUESTCODE_H_
# define REQUESTCODE_H_

# include	"types.hh"

namespace request
{
  namespace server
  {
    static const request::ID OK =		1000;
    static const request::ID BAD_REQ =		1001;
    static const request::ID FORBIDDEN =	1002;
    static const request::ID NOT_IMPLEMENTED =	1003;
    static const request::ID NO_CONTENT =	1004;
    static const request::ID PARTIAL_CONTENT =	1005;
    static const request::ID NO_SLOTS =		1006;
  }
}

#endif /* REQUESTCODE_H_ */
