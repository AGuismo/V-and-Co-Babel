#ifndef BRIDGE_HH
#define BRIDGE_HH

# include	<deque>
# include	<iostream>

template <typename T, typename U>
class ABridge
{
public:
  typedef std::deque<T>  input_buffer;
  typedef std::deque<U>  output_buffer;

public:
	ABridge(std::size_t capacity = 0);
  virtual   ~ABridge() {}

public:
  virtual void    inputRead(input_buffer &, std::size_t, bool blocking = true);
  virtual void    inputWrite(const input_buffer &);
  virtual void    inputPush(T &);
  virtual T		  inputPop();
  virtual bool    inputEmpty() const;
  virtual void    inputReady() = 0;

  virtual void    outputRead(output_buffer &, std::size_t, bool blocking = true);
  virtual void    outputWrite(const output_buffer &);
  virtual void    outputPush(U &);
  virtual U		  outputPop();
  virtual bool    outputEmpty() const;
  virtual void    outputReady() = 0;

private:
  input_buffer      _input;
  output_buffer      _output;
};

template <typename T, typename U>
ABridge<T, U>::ABridge(std::size_t capacity)
{
	(void)(capacity);
/*
	if (capacity != 0)
	{
		_input.resize(capacity);
		_output.resize(capacity);
	}
	*/
}

template <typename T, typename U>
void  ABridge<T, U>::inputRead(input_buffer &buff, std::size_t size, bool blocking)
{
  std::size_t realSize = size > _input.size() ? _input.size() : size;

  (void)blocking;
  buff.assign(_input.begin(), _input.begin() + realSize);
  _input.erase(_input.begin(), _input.begin() + realSize);
}

template <typename T, typename U>
void  ABridge<T, U>::inputWrite(const input_buffer &buff)
{
  _input.insert(_input.end(), buff.begin(), buff.end());
  if (!inputEmpty())
    inputReady();
}

template <typename T, typename U>
void  ABridge<T, U>::inputPush(T &buff)
{
  _input.push_back(buff);
  if (!inputEmpty())
    inputReady();
}

template <typename T, typename U>
T  ABridge<T, U>::inputPop()
{
	if (_input.empty())
		return (0);

	U	&dat = _input.front();

	_input.pop_front();
	return (dat);
}

template <typename T, typename U>
bool  ABridge<T, U>::inputEmpty() const
{
  return (_input.empty());
}

template <typename T, typename U>
void  ABridge<T, U>::outputRead(output_buffer &buff, std::size_t size, bool blocking)
{
  std::size_t realSize = size > _output.size() ? _output.size() : size;

  (void)blocking;
  buff.assign(_output.begin(), _output.begin() + realSize);
  _output.erase(_output.begin(), _output.begin() + realSize);
}

template <typename T, typename U>
void  ABridge<T, U>::outputWrite(const output_buffer &buff)
{
  _output.insert(_output.end(), buff.begin(), buff.end());
  if (!outputEmpty())
    outputReady();
}

template <typename T, typename U>
void  ABridge<T, U>::outputPush(U &buff)
{
  _output.push_back(buff);
  if (!outputEmpty())
    outputReady();
}

template <typename T, typename U>
U  ABridge<T, U>::outputPop()
{
	if (_output.empty())
		return (0);

	U	&dat = _output.front();

	_output.pop_front();
	return (dat);
}

template <typename T, typename U>
bool  ABridge<T, U>::outputEmpty() const
{
  return (_output.empty());
}

#endif // BRIDGE_HH
