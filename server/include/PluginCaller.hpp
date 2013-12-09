#ifndef PLUGINCALLER_H_
# define PLUGINCALLER_H_

# include	"IPlugin.hh"

namespace	plugin
{
  template <typename Key, typename Sign>
  class Caller
  {
  public:
    Caller()
    {

    }

    virtual ~Caller()
    {

    }

  private:
    Caller(Caller const&);
    Caller& operator=(Caller const&);

  protected:
    std::map<Key, Sign>		_calls;
  };

}

#endif /* PLUGINCALLER_H_ */
