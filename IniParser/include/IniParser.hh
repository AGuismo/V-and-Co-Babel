#ifndef INIPARSER_H_
# define INIPARSER_H_

# include	<map>
# include	<string>
# include	"ProducterStream.hpp"
# include	"ConsumerParser.hpp"

namespace	parser
{
  class Ini : public ConsumerParser
  {
  public:
    class Exception : public ConsumerParser::Exception
    {
    public:
      Exception(const std::string &, Ini &) throw();
      virtual ~Exception() throw();
      const char	*what() const throw();

    public:
      Exception(Exception const&) throw();
      Exception& operator=(Exception const&) throw();
    };

  public:
    typedef std::string			key;
    typedef std::string			value;
    typedef std::string			section;
    typedef std::map<key, value>	key_val;
    typedef std::map<section, key_val>	section_key_val;

  public:
    Ini(bool strict = false);
    virtual ~Ini();
    bool	loadFile(const std::string &filename);
    bool	run();
    void	addKey(const section &, const key &);
    void	addSection(const section &);
    void	strict(bool);
    bool	strict(void) const;
    const section_key_val	&output() const;

  private:
    bool	readIni();
    bool	readSection();
    bool	readComment();
    bool	readVars(key &, value &);
    bool	readValue(value &);
    bool	readKey(key &);

  private:
    Ini(Ini const&);
    Ini& operator=(Ini const&);

  private:
    ProducterStream	_stream;
    section_key_val	_output;
    bool		_strict;
  };
}

#endif /* INIPARSER_H_ */
