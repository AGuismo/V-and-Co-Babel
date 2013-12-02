#ifndef REQUESTFACTORY_H_
# define REQUESTFACTORY_H_

# include	<map>
# include	"ARequest.hh"
# include	"RequestCode.hh"

class		Protocol;

namespace	request
{
  class		Factory
  {
    typedef	std::map<ID, ARequest *> lnk_type;
  private:
    Factory();
    ~Factory();

  private:
    static Factory	&getInstance();

  public:
    template <typename T>
    void		add(ID id);
    static ARequest	*factory(Protocol &, const request::ID code);
    static void		factory(Protocol &, const ARequest &);

  private:
    lnk_type		_lnk;
  };

  template <typename T>
  void			Factory::add(request::ID id)
  {
    _lnk[id] = new T;
  }

}

#endif /* REQUESTFACTORY_H_ */
