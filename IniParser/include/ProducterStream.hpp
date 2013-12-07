#ifndef PRODUCTERSTREAM_H_
# define PRODUCTERSTREAM_H_

# include	<string>
# include	<stdexcept>

class ProducterStream
{
public:
  class Exception
  {
  public:
    Exception(const std::string &) throw();
    virtual ~Exception() throw();

  public:
    Exception(Exception const&) throw();
    Exception& operator=(Exception const&) throw();

  public:
    const char	*what(void) const throw();

  protected:
    std::string	_what;
  };

public:
  static const short	maxReadBlock = 4096;

public:
  ProducterStream();
  ~ProducterStream();

private:
  ProducterStream(ProducterStream const&);
  ProducterStream&	operator=(ProducterStream const&);

public:
  std::string	nextString();
  bool		loadFile(const char *path);
  bool		loadStdin();

private:
  std::istream		*stream;
  bool			isFile;
};

#endif /* PRODUCTERSTREAM_H_ */
