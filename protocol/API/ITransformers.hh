#ifndef ITRANSFORMERS_H_
# define ITRANFORMERS_H_

/**
 *
 *	\file	ITransformers.hh
 *	API Class reference for the protocol
 *
 */

class	Protocol;
class	ARequest;

/** \brief Interface for both groups. Every request need to be inherit */
class ITransformers
{
public:
  virtual ~ITransformers() {};

public:

  /**
   *	Clone the class and return an allocated pointer
   */
  virtual ARequest	*clone() = 0;

  /**
   *	Serialize the class
   */
  virtual Protocol	&serialize(Protocol &) const = 0;

  /**
   *	Unserialize the class
   */
  virtual Protocol	&unserialize(Protocol &) = 0;
};

#endif /* ITRANSFORMERS_H_ */
