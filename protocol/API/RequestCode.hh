#ifndef REQUESTCODE_H_
# define REQUESTCODE_H_

/**
 *
 *	\file	RequestCode.hh
 *	List of all request code
 *
 */

# include	"types.hh"

/** request Namespace */
namespace request
{
  /** Server codes */
  namespace server
  {
    static const ID OK =		1000; /**< Everything went fine */
    static const ID BAD_REQ =		1001; /**< Bad Request */
    static const ID FORBIDDEN =		1002; /**< You send a forbidden request due to the context */
    static const ID NOT_IMPLEMENTED =	1003; /**< Request not implemented */
    static const ID NO_CONTENT =	1004; /**< Request don't have */
    static const ID PARTIAL_CONTENT =	1005; /**< Request have partial content */
    static const ID NO_SLOTS =		1006; /**< No more slots available */

    /** Server Friend codes */
    namespace	friends
    {
      static const ID UPDATE =		1300;
    }
  }

  /** Client codes */
  namespace client
  {

    /** Client Friend codes */
    namespace	friends
    {
      static const ID REQUEST =		300;
      static const ID DEL_FRIEND =	301;
      static const ID ACCEPT =		302;
      static const ID REFUSE =		303;
      static const ID LIST =		304;
    }

  }
}

#endif /* REQUESTCODE_H_ */
