#ifndef TYPES_H_
# define TYPES_H_

/**
 * \file	types.hh
 * \brief	Define Cross-Platform Types and typedef's
 *
 *
 */

# include	<string>

# if defined(WIN32)

#  include			<windows.h>

typedef __int8			Rint8;
typedef __int16			Rint16;
typedef __int32			Rint32;
typedef __int64			Rint64;

typedef unsigned __int8		Rbool;
typedef unsigned __int8		Ruint8;
typedef unsigned __int16	Ruint16;
typedef unsigned __int32	Ruint32;
typedef unsigned __int64	Ruint64;

typedef float			Rfloat;
typedef double			Rdouble;

# elif defined(linux)

#  include			<stdint.h>

typedef int8_t			Rint8;		/**< 8 bytes signed int */
typedef int16_t			Rint16;		/**< 16 bytes signed int */
typedef int32_t			Rint32;		/**< 32 bytes signed int */
typedef int64_t			Rint64;		/**< 64 bytes signed int */

typedef uint8_t			Rbool;		/**< boolean */
typedef uint8_t			Ruint8;		/**< 8 bytes unsigned int */
typedef uint16_t		Ruint16;	/**< 16 bytes unsigned int */
typedef uint32_t		Ruint32;	/**< 32 bytes unsigned int */
typedef uint64_t		Ruint64;	/**< 64 bytes unsigned int */

typedef float			Rfloat;		/**< Simple floating point precision */
typedef double			Rdouble;	/**< Double floating point precision */

# else
#  error "Unsupported Operating System"
# endif

# define	GET_MINOR(version)		(version & 0xFF)			/**< Get the minor */
# define	SET_MINOR(version, minor)	((version &= 0x00FF) += minor)		/**< Set the minor */
# define	GET_MAJOR(version)		(version >> 8)				/**< Get the major*/
# define	SET_MAJOR(version, major)	((version &= 0xFF) += (major << 8))	/**< Set the major */
# define	SET_VERSION(major, minor)	(major << 8 + minor)			/**< Set the version */

# define	SET_OPTION(option, type)	(option |= type)			/**< Set an option describe in options struct */
# define	UNSET_OPTION(option, type)	(option &= ~type)			/**< Unset an option describe in options struct */
# define	GET_OPTION(option, type)	(option & type)				/**< Get an option describe in options struct */

/** request Namespace */
namespace	request
{
  typedef Ruint8	Rights;			/**< User Rights type */
  typedef Rbool		Privacy;		/**< Privacy Rights type */
  typedef Ruint16	ID;			/**< Request code ID type */
  typedef std::string	PasswordType;		/**< Password type */
  typedef Ruint8	UsernameLen;		/**< Username Len type */
  typedef std::string	Username;		/**< Username type */
  typedef Ruint16	MessageLen;		/**< Message Len type */
  typedef std::string	Message;		/**< Message type */
  typedef Ruint8	Status;			/**< Status type */
  typedef Ruint8	StatusDetailLen;	/**< Status detail Len type */
  typedef std::string	StatusDetail;		/**< Status detail type */
  typedef Ruint16	Port;			/**< Port type */
  typedef Ruint32	IP;			/**< IP type */
  typedef Ruint64	Time;			/**< Time type */
  typedef Ruint8	IdxAnswer;		/**< Idx of the answer type */
  typedef Ruint16	AnswerLen;		/**< Size of the answer type */
  typedef std::string	Answer;			/**< Answer type */
  typedef Ruint8	FromLen;		/**< Size of the name of the sender type */
  typedef std::string	From;			/**< Name of the sender type */
  typedef Rdouble	SinceWhen;		/**< Time when the message was received type */
  typedef Ruint8	Options;		/**< Options type */
  typedef Ruint16	MsgLen;			/**< Size of the message type */
  typedef std::string	Msg;			/**< message type */
  typedef Ruint16	Version;		/**< Version type */
  typedef Ruint8	Major;			/**< Major Version type */
  typedef Ruint8	Minor;			/**< Minor Version type */
  typedef Ruint16	StreamLen;		/**< StreamLen type */
  typedef Ruint8	PingPongID;		/**< Ping-Pong id code */
  typedef Ruint32	IP;			/**< IP type */
  typedef Ruint16	Port;			/**< Port type */

  /** Crypt Trait Class info */
  struct Crypt
  {
    static const unsigned int	PASS_SIZE = 32;		/**< Cryptography Size */
  };

  /** Define the current Version of API */
  struct	version
  {
    static const Major		MAJOR = 1;		/**< Current Major version */
    static const Minor		MINOR = 1;		/**< Current Minor version */
  };

  /** options list */
  struct	options
  {
    static const Options	AUDIO = 1;		/**< Audio Mode */
    static const Options	VIDEO = 2;		/**< Video Mode */
    static const Options	CONF = 4;		/**< Conf Mode */
  };

  /** User Class info */
  struct	User
  {
    static const Privacy	PRIVATE = 0;		/**< Private mode */
    static const Privacy	PUBLIC = 1;		/**< Public mode */
    static const Rights		ROOT = 0;		/**< Root mode */
    static const Rights		USER = 1;		/**< User mode */

    /** User Status Class info */
    struct	Status
    {
      static const request::Status	DISCONNECTED = 0;	/**< Disconnected status */
      static const request::Status	CONNECTED = 1;		/**< Connected status */
      static const request::Status	ABSENT = 2;		/**< Absent status */
      static const request::Status	OCCUPIED = 3;		/**< Occupied status */
      static const request::Status	DELETED = 4;		/**< Deleted status */
      static const request::Status	INVISIBLE = 5;		/**< Invisible status */
    };

  };

} // !request

#endif /* TYPES_H_ */
