#ifndef ITRANSFORMERS_H_
# define ITRANFORMERS_H_

/**
 *
 *	\file	ITransformers.hh
 *	\brief API Class reference for the protocol
 *
 */

class	Protocol;

/** \brief Interface for both groups. Every request need to be inherit */
class ITransformers
{
public:
  virtual ~ITransformers() {};

public:

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
