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

    namespace perso
    {
      static const ID  MISSED_CALLS =	1200; /**< Get the number of missed calls */
      static const ID  GET_MISSED =	1201; /**< Get a missed call information */
      static const ID  AUTO_ANSWER =	1203; /**< Set an auto answer message */
    }
    /** Server Friend codes */
    namespace friends
    {
      static const ID UPDATE =		1300; /**< Friend status update */
    }

    /** Server Call codes */
    namespace call
    {
      static const ID TIMEOUT =		1400; /**< Call Timeout */
      static const ID CALL =		1401; /**< Call someone */
    }

    /** Server Chat codes */
    namespace chat
    {
      static const ID MESSAGE =		1500; /**< Send a message to a client */
    }
  }
  /** Client codes */
  namespace client
  {
    /** Client authentification request codes */
    namespace auth
    {
      static const ID NEW =		100; /**< Add a new account */
      static const ID REMOVE =		101; /**< Remove an account */
      static const ID MODIFY =		102; /**< Modify an account */
      static const ID CONNECT =		103; /**< Connect to the server */
      static const ID DISCONNECT =	104; /**< Disconnect your client */
    }

    /** Client Personnal request codes */
    namespace perso
    {
      static const ID PRIVACY_MODE =		200; /**< Set the privacy mode */
      static const ID STATUS =			201; /**< Change your status */
      static const ID MISSED_CALLS =		202; /**< Ask for missed calls */
      static const ID GET_MISSED =		203; /**< Get missed call informations */
      static const ID DEL_MISSED =		204; /**< Delete missed call */
      static const ID SET_AUTO_ANSWER =		205; /**< Set an auto answer message */
      static const ID UNSET_AUTO_ANSWER =	206; /**< Delete your auto answer message */
    }

    /** Client Friend codes */
    namespace friends
    {
      static const ID REQUEST =		300; /**< Send a friend request */
      static const ID DEL_FRIEND =	301; /**< Delete a friend */
      static const ID ACCEPT =		302; /**< Accept a friend request */
      static const ID REFUSE =		303; /**< Refuse a friend request */
      static const ID LIST =		304; /**< List all your friends */
    }

    /** Client Calls request codes */
    namespace call
    {
      static const ID CALL =		400; /**< Call someone */
      static const ID ACCEPT =		401; /**< Accept a call */
      static const ID REFUSE =		402; /**< Refuse a call */
      static const ID HANG_UP =		403; /**< Hang up the current Call */
    }

    /** Client Chat codes */
    namespace chat
    {
      static const ID MESSAGE =		500; /**< Send a message */
    }
  }
}

#endif /* REQUESTCODE_H_ */
