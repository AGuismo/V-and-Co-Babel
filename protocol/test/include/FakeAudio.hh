//
// FakeAudio.hh for  in /home/brigno/GIT/V-and-Co-Babel/protocol/test
//
// Made by brigno
// Login   <brigno@epitech.net>
//
// Started on  Mon Dec 16 21:27:33 2013 brigno
// Last update Mon Dec 16 22:06:21 2013 brigno
//

#ifndef		__FAKEAUDIO_HH__
# define	__FAKEAUDIO_HH__

# include	<boost/thread.hpp>
# include	"Bridge.hh"

class	Bridge;

class	FakeAudio
{
public:
  FakeAudio(Bridge &bridge);
  virtual ~FakeAudio();

  const Bridge::buffer	randomData() const;
  void	routine();
  void	run();

private:
  FakeAudio(FakeAudio const&);
  FakeAudio& operator=(FakeAudio const&);

private:
  boost::thread	_th;
  Bridge	&_bridge;
};

#endif	/* !__FAKEAUDIO_HH__ */
