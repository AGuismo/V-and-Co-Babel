#ifndef IDATABASE_H_
# define IDATABASE_H_

# include	"ISavable.hh"

class IDatabase : public save::ISavable
{
public:
  virtual ~IDatabase() {};

public:
  virtual Serializer &	save(Serializer &) = 0;
  virtual Serializer &	load(Serializer &) = 0;
};

#endif /* IDATABASE_H_ */
