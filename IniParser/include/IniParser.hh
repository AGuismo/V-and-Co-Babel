#ifndef INIPARSER_H_
# define INIPARSER_H_

# include	<map>
# include	"ProducterStream.hpp"
# include	"ConsumerParser.hpp"

namespace	parser
{
  class Ini : public ConsumerParser
  {
  public:
    typedef std::string			key;
    typedef std::string			value;
    typedef std::string			section;
    typedef std::map<key, value>	key_val;
    typedef std::map<section, key_val>	section_key_val;

  public:
    Ini();
    virtual ~Ini();
    bool	loadFile(const std::string &filename);
    bool	run();
    void	addKey(const section &, const key &);
    void	addSection(const section &);

  private:
    bool	readIni();
    bool	readSection();
    bool	readVars();
    bool	readValue(value &);
    bool	readKey(key &);

  private:
    Ini(Ini const&);
    Ini& operator=(Ini const&);

  private:
    ProducterStream	_stream;
    section_key_val	_output;
  };
}

#endif /* INIPARSER_H_ */
