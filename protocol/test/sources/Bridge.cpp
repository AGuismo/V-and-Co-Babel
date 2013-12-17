#include	<sys/time.h> // Not cross platform
#include	"Bridge.hh"

Bridge::Bridge(int readsize):
  _readsize(readsize)
{
  std::srand(time(0));
}

Bridge::Bridge(const Bridge &other)
{
}

Bridge::~Bridge()
{
}

Bridge	&Bridge::operator=(const Bridge &other)
{
  return (*this);
}

void	Bridge::inputFeed(const buffer &input) // From Serializer to Bridge
{
  boost::lock_guard<boost::mutex>	guard(_inputLock);

  _input.insert(_input.end(), input.begin(), input.end());
}

void	Bridge::outputFeed(buffer &output) // From Bridge to Audio
{
  boost::lock_guard<boost::mutex>	guard(_inputLock);
  std::size_t				size;

  if (_readsize > _input.size())
    size = _input.size();
  else
    size = _readsize;
  output.assign(_input.begin(), _input.begin() + size);
  _input.erase(_input.begin(), _input.begin() + size);
}

bool	Bridge::emptyFeed()
{
  boost::lock_guard<boost::mutex>	guard(_inputLock);
  return (_input.empty());
}

void	Bridge::inputDispatch(const buffer &input) // From Audio to Bridge
{
  boost::lock_guard<boost::mutex>	guard(_outputLock);

  _output.insert(_output.end(), input.begin(), input.end());
}

void	Bridge::outputDispatch(buffer &output) // From Bridge to Serializer
{
  boost::lock_guard<boost::mutex>	guard(_outputLock);
  std::size_t				size;

  if (_readsize > _output.size())
    size = _output.size();
  else
    size = _readsize;
  output.assign(_output.begin(), _output.begin() + size);
  _output.erase(_output.begin(), _output.begin() + size);
}

bool	Bridge::emptyDispatch()
{
  boost::lock_guard<boost::mutex>	guard(_outputLock);
  return (_output.empty());
}
