#include "audio.h"
#include "ui_audio.h"
#include  <limits>
#include  <QDebug>
#include  "PAudioStream.hh"

Audio::Audio(Bridge &bridge) :
  _bridge(bridge)
{
  _audio = new PAudioStream(bridge);
  moveToThread(&_th);
  QObject::connect(&_th, SIGNAL(started()), this, SLOT(routine()));
}

Audio::~Audio()
{
  _th.terminate();
  _th.wait();
}

void  Audio::routine()
{
  if (_audio->init())
    _audio->run();
// Call Seb object routine()
}

void  Audio::run()
{
  _th.start();
}

/*void  Audio::handleInputWrite(const std::string &str)
{
  AudioBridge::input_buffer buff;

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
      buff.push_back(*it);
    }
  _bridge.inputWrite(buff);
}

void  Audio::handleOutputRead()
{
  AudioBridge::input_buffer buff;
  QString               str;

  _bridge.outputRead(buff, std::numeric_limits<std::size_t>::max());
  for (AudioBridge::input_buffer::const_iterator it = buff.begin(); it != buff.end(); ++it)
    str += *it;
//  handleInputWrite(str.toStdString());
}
*/
