#include	<boost/bind.hpp>
#include	<iostream>
#include	<iomanip>
#include	"FakeAudio.hh"

FakeAudio::FakeAudio(Bridge &bridge) :
  _bridge(bridge)
{

}

FakeAudio::~FakeAudio()
{

}

const Bridge::buffer	FakeAudio::randomData() const
{
  std::size_t		it;
  std::size_t		end = std::rand() % 20;
  Bridge::buffer	lst;

  std::cout << "Bridge::inputDispatch() data: " << std::endl;
  for (it = 0; it < end; ++it)
    {
      unsigned char	c;

      c = std::rand() % 255;
      std::cout << std::setprecision(2) << std::hex << (int)c;
      if (it != 0 && it % 16 == 0)
	std::cout << std::endl;
      else if (it != 0 && it % 4 == 0)
	std::cout << " ";
      lst.push_back(c);
    }
  std::cout << std::dec << std::endl;
  return (lst);
}

void	FakeAudio::routine()
{
  Bridge::buffer	buff;

  while (true)
    {
      boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
      if (!_bridge.emptyFeed())
	{
	  _bridge.outputFeed(buff);

	  std::cout << "Bridge::outputFeed() data: " << std::endl;
	  for (std::size_t it = 0; it < buff.size(); ++it)
	    {
	      std::cout << std::setprecision(2) << std::hex << (int)(buff[it]);
	      if (it != 0 && it % 16 == 0)
		std::cout << std::endl;
	      else if (it != 0 && it % 4 == 0)
		std::cout << " ";
	    }
	}
      _bridge.inputDispatch(randomData());
    }
}

void	FakeAudio::run()
{
  _th = boost::thread(boost::bind(&FakeAudio::routine, this));
}
