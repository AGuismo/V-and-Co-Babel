#ifndef CONSUMERSTREAM_H_
# define CONSUMERSTREAM_H_

#include	<iostream>


# include	<string>
# include	<stack>
# include	<map>

class ProducterStream;

class ConsumerParser
{
public:
  class Exception
  {
  public:
    Exception(const std::string &, ConsumerParser &) throw();
    virtual ~Exception() throw();
    virtual const char	*what() const throw();

  public:
    Exception(Exception const&) throw();
    Exception& operator=(Exception const&) throw();

  protected:
    std::string	_what;
  };

protected:
  typedef std::string::iterator			Context;
  typedef std::string::iterator			Capture;
  typedef std::map<std::string, Capture>	capture_map;

public:
  ConsumerParser(ProducterStream &);
  ~ConsumerParser();

private:
  bool		addData();
  bool		skipBlanks();

protected:
  void		saveContext();
  void		restoreContext();

public:
  inline bool	peekChar(char c);
  inline bool	readChar(char c);
  inline bool	readRange(char begin, char end);
  bool		readText(char *text);
  bool		readEOF();
  bool		readUntil(char c, std::string &);
  bool		readUntilEOF();
  bool		readInteger(std::string &);
  bool		readIdentifier(std::string &);
  inline bool	beginCapture(std::string tag);
  inline bool	endCapture(std::string tag, std::string &out);
  void		skipBlank(bool);

public:
  ConsumerParser(ConsumerParser const&);
  ConsumerParser& operator=(ConsumerParser const&);

private:
  bool			_skipBlank;
  std::string::iterator	_rwHeader;

protected:
  ProducterStream	&_stream;
  std::stack<Context>	_contexts;
  std::string		_inputData;
  bool			_isEOF;
  capture_map		_captures;

  friend class	ConsumerParser::Exception;
};

inline bool	ConsumerParser::peekChar(char c)
{
  if (_skipBlank)
    skipBlanks();
  if (_rwHeader == _inputData.end() && !addData())
    {
      return (false);
    }
  if (*_rwHeader == c)
    return (true);
  return (false);
}

inline bool	ConsumerParser::readChar(char c)
{
  if (_skipBlank)
    skipBlanks();
  if (peekChar(c)) // He'll call addData()
    {
      _rwHeader++;
      return (true);
    }
  return (false);
}

inline bool	ConsumerParser::readRange(char begin, char end)
{
  saveContext();
  if (_skipBlank)
    skipBlanks();
  if (_rwHeader == _inputData.end() && !addData())
    {
      restoreContext();
      // std::cerr << "No more data" << std::endl;
      return (false);
    }
  // std::cout << "rwHeader pos : {" << *_rwHeader << "}" << std::endl;
  if (*_rwHeader >= begin && *_rwHeader <= end)
    {
      _rwHeader++;
      return (true);
    }
  restoreContext();
  return (false);
}

inline bool	ConsumerParser::beginCapture(std::string tag)
{
  if (_skipBlank)
    skipBlanks();
  _captures[tag] = _rwHeader;
  return (true);
}

inline bool	ConsumerParser::endCapture(std::string tag, std::string &out)
{
  if (_captures[tag] == _rwHeader)
    return (false);
  out = std::string(_captures[tag], _rwHeader);
  return (true);
}

#endif /* CONSUMERSTREAM_H_ */
