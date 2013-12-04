#ifndef TYPES_H_
# define TYPES_H_

/**
 * \file	types.hh
 * \brief	Define Cross-Platform Types and typedef's
 *
 *
 */

# include	<string>

#if defined(WIN32)

# include			<windows.h>

typedef __int8			Rbool;
typedef __int8			Rint8;
typedef __int16			Rint16;
typedef __int32			Rint32;

typedef unsigned __int8		Ruint8;
typedef unsigned __int16	Ruint16;
typedef unsigned __int32	Ruint32;

typedef float			Rfloat;
typedef double			Rdouble;

#elif defined(linux)

# include			<stdint.h>

typedef int8_t			Rbool;		/**< boolean */
typedef int8_t			Rint8;		/**< 8 bytes signed int */
typedef int16_t			Rint16;		/**< 16 bytes signed int */
typedef int32_t			Rint32;		/**< 32 bytes signed int */

typedef uint8_t			Ruint8;		/**< 8 bytes unsigned int */
typedef uint16_t		Ruint16;	/**< 16 bytes unsigned int */
typedef uint32_t		Ruint32;	/**< 32 bytes unsigned int */

typedef float			Rfloat;		/**< Simple floating point precision */
typedef double			Rdouble;	/**< Double floating point precision */

#else
# error "Unsupported Operating System"
#endif

/** request Namespace */
namespace	request
{
  typedef Ruint8	Rights;			/**< User Rights type */
  typedef Rbool		Privacy;		/**< Privacy Rights type */
  typedef Ruint16	ID;			/**< Request code ID type */
  typedef std::string	PasswordType;		/**< Password type */
  typedef Ruint8	UsernameLen;		/**< Username Len type */
  typedef std::string	Username;		/**< Username type */
  typedef Ruint8	Status;			/**< Status type */
  typedef Ruint8	StatusDetailLen;	/**< Status detail Len type */
  typedef std::string	StatusDetail;		/**< Status detail type */
  typedef Ruint16	Port;			/**< Port type */
  typedef Ruint32	IP;			/**< IP type */

  /** Crypt Trait Class info */
  struct Crypt
  {
    static const unsigned int	PASS_SIZE = 32;		/**< Cryptography Size */
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
      static const Status	DISCONNECTED = 0;	/**< Disconnected status */
      static const Status	CONNECTED = 1;		/**< Connected status */
      static const Status	ABSENT = 2;		/**< Absent status */
      static const Status	OCCUPIED = 3;		/**< Occupied status */
      static const Status	DELETED = 4;		/**< Deleted status */
      static const Status	INVISIBLE = 5;		/**< Invisible status */
    };

  };

}

#endif /* TYPES_H_ */
