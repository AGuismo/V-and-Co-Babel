#ifndef		SERIALIZER_H_
# define	SERIALIZER_H_

# include	<string>
# include	<deque>
# include	<vector>
# include	"types.hh"
# include	"Salt.hpp"

class Serializer
{
public:
  class invalid_argument
  {
  public:
    invalid_argument(const std::string &msg) throw();
    virtual ~invalid_argument() throw();

  public:
    invalid_argument(invalid_argument const&) throw();
    invalid_argument& operator=(invalid_argument const&) throw();

  public:
    const char		*what(void) const throw();

  protected:
    std::string		_what;
  };

public:
  typedef Ruint8			Byte;
  typedef std::deque<Byte>		container_type;
  typedef container_type::size_type	size_type;

public:
  Serializer&                 operator<<(const Rint8);
  Serializer&                 operator<<(const Rint32);
  Serializer&                 operator<<(const Rint64);
  Serializer&                 operator<<(const Rint16);
  Serializer&                 operator<<(const Ruint8);
  Serializer&                 operator<<(const Ruint32);
  Serializer&                 operator<<(const Ruint64);
  Serializer&                 operator<<(const Ruint16);
  Serializer&                 operator<<(const Rdouble);
  Serializer&                 operator<<(const Rfloat);
  Serializer&                 operator<<(const std::string & s);

  Serializer&                 operator>>(Rint8 &);
  Serializer&                 operator>>(Rint32 &);
  Serializer&                 operator>>(Rint64 &);
  Serializer&                 operator>>(Rint16 &);
  Serializer&                 operator>>(Ruint8 &);
  Serializer&                 operator>>(Ruint32 &);
  Serializer&                 operator>>(Ruint64 &);
  Serializer&                 operator>>(Ruint16 &);
  Serializer&                 operator>>(Rdouble &);
  Serializer&                 operator>>(Rfloat &);
  Serializer&                 operator>>(std::string & s);

public:
  Serializer();
  virtual ~Serializer();

private:
  template <typename T>
  T			&pop(T&);
  char		*&pop(char *&);

public:
  template <typename T>
  void			push(const T *, size_type count = 1);
  template <typename T>
  T				push(const T);
  std::string	push(const std::string);
  std::string	push(const std::string, size_type count);
  std::string	&pop(std::string &, size_type count = 1);


public:
  Rbool		empty() const;
  Ruint32	size() const;
  const container_type	&content() const;
  Byte		*data();

public:
  Serializer(Serializer const&);
  Serializer& operator=(Serializer const&);

protected:
  container_type	_container;
  Byte			*_data;

  friend std::ostream &	operator<<(std::ostream& stream, Serializer& rhs)
  {
    Salt		salt;

    salt.update(rhs.data(), rhs.size());
    salt.final();
    stream << salt;
    stream.write((char*) rhs.data(), rhs.size());
    return stream;
  }

  friend std::istream &	operator>>(std::istream& file, Serializer& rhs)
  {
    char			prev[Salt::LENGTH + 1];
    Salt			salt;

    file.seekg(0, file.end);
    const std::streamsize	size = file.tellg();
    file.seekg(0, file.beg);

    if (size < Salt::LENGTH) throw invalid_argument("wrong file size");

    file.read(prev, Salt::LENGTH);
    prev[Salt::LENGTH] = '\0';
    for (std::streamsize o = size - Salt::LENGTH; o > 0; o -= sizeof(Byte) )
      {
	Byte	byte;

	byte = file.get();
	rhs.push(byte);
      }
    salt.update(rhs.data(), rhs.size());
    salt.final();

    if (salt != prev) throw invalid_argument("corrupted file");
    return file;
  }
};

template <typename T>
void			Serializer::push(const T *val, size_type count)
{
	const Byte	*buffer = reinterpret_cast<const Byte*>(val);
	_container.resize(_container.size() + (count * sizeof(T)));

  for (size_t size = 0; size < (sizeof(T) * count); size += sizeof(Byte))
    {
      _container.push_back(buffer[size]);
    }
}

template <typename T>
T		Serializer::push(const T val)
{
  const Byte*	buffer = reinterpret_cast<const Byte*>(&val);

  for (size_t size = 0; size < sizeof(val); size += sizeof(Byte))
    {
      _container.push_back(buffer[size]);
    }
  return (val);
}

template <typename T>
T		&Serializer::pop(T &val)
{
  Byte*		buffer = reinterpret_cast<Byte*>(&val);

  if (sizeof(T) > _container.size())
    throw invalid_argument("Not enough size");
  for (size_t size = 0; size < sizeof(val); size += sizeof(Byte))
    {
      buffer[size] = _container.front();
      _container.pop_front();
    }
  return (val);
}

#endif /* SERIALIZER_H_ */
