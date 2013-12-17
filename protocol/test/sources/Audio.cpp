#include	"FakeAudio.hh"
#include	<boost/bind.hpp>

Audio::Audio()
{

}

Audio::~Audio()
{

}

void	Audio::routine()
{
}

void	Audio::run()
{
  _th = boost::thread(boost::bind(&Audio::routine, this));
}
