#include	"Bridge.hh"


Bridge::Bridge(int readsize):
  _readsize(readsize)
{
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

  output.assign(_input.begin(), _input.begin() + _readsize);
  _input.erase(_input.begin(), _input.begin() + _readsize);
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

  output.assign(_output.begin(), _output.begin() + _readsize);
  _output.erase(_output.begin(), _output.begin() + _readsize);
}

bool	Bridge::emptyDispatch()
{
  boost::lock_guard<boost::mutex>	guard(_outputLock);
  return (_output.empty());
}
