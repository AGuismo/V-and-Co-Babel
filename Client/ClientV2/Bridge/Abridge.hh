#ifndef BRIDGE_HH
#define BRIDGE_HH

# include <vector>

template <typename T, typename U>
class ABridge
{
public:
  typedef std::vector<T>  input_buffer;
  typedef std::vector<U>  output_buffer;

public:
  virtual   ~ABridge() {}
  
public:
  virtual void    inputRead(input_buffer &, std::size_t);
  virtual void    inputWrite(const input_buffer &);
  virtual bool    inputEmpty() const;
  virtual void    inputReady() = 0;

  virtual void    outputRead(output_buffer &, std::size_t);
  virtual void    outputWrite(const output_buffer &);
  virtual bool    outputEmpty() const;
  virtual void    outputReady() = 0;

private:
  input_buffer      _input;
  output_buffer      _output;
};

template <typename T, typename U>
void  ABridge<T, U>::inputRead(input_buffer &buff, std::size_t size)
{
  std::size_t realSize = size > _input.size() ? _input.size() : size;

  buff.assign(_input.begin(), _input.begin() + realSize);
  _input.erase(_input.begin(), _input.begin() + realSize);
}

template <typename T, typename U>
void  ABridge<T, U>::inputWrite(const input_buffer &buff)
{
  _input.insert(_input.end(), buff.begin(), buff.end());
}

template <typename T, typename U>
bool  ABridge<T, U>::inputEmpty() const
{
  return (_input.empty());
}

template <typename T, typename U>
void  ABridge<T, U>::outputRead(output_buffer &buff, std::size_t size)
{
  std::size_t realSize = size > _output.size() ? _output.size() : size;

  buff.assign(_output.begin(), _output.begin() + realSize);
  _output.erase(_output.begin(), _output.begin() + realSize);
}

template <typename T, typename U>
void  ABridge<T, U>::outputWrite(const output_buffer &buff)
{
  _output.insert(_output.end(), buff.begin(), buff.end());
}

template <typename T, typename U>
bool  ABridge<T, U>::outputEmpty() const
{
  return (_output.empty());
}

#endif // BRIDGE_HH
