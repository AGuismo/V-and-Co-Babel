#ifndef		__BRIDGE_HH__
# define	__BRIDGE_HH__

# include	<boost/thread.hpp>
# include	<list>

class Bridge
{
public:
  typedef std::vector<char>	buffer;
public:
  Bridge(int readsize = 4096);
  Bridge(Bridge const&);
  virtual ~Bridge();

public:
  Bridge	&operator=(Bridge const&);

  void		inputFeed(const buffer &input); // From Serializer to Bridge
  void		outputFeed(buffer &input); // From Bridge to Audio
  bool		emptyFeed();

  void		inputDispatch(const buffer &input); // From Audio to Bridge
  void		outputDispatch(buffer &input); // From Bridge to Serializer
  bool		emptyDispatch();


private:
  buffer	_input;
  buffer	_output;
  unsigned int	_readsize;
  boost::mutex	_inputLock;
  boost::mutex	_outputLock;
};

#endif	/* !__BRIDGE_HH__ */
