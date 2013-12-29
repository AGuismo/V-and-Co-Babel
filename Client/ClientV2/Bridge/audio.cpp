#include	<limits>
#include	<iostream>
#include	<QDebug>
#include	"audio.h"
#include	"PAudioStream.hh"
#include	"AudioWorker.h"

Audio::Audio(Bridge &bridge) :
  _bridge(bridge), _th(0), _work(0)
{
  //QObject::connect();
}

Audio::~Audio()
{
  if (_th != 0 && _th->isRunning())
    _th->wait();
}

void  Audio::run()
{
  _th = new QThread;
  _work = new Worker(_bridge);
  _work->moveToThread(_th);
  QObject::connect(_th, SIGNAL(started()), _work, SLOT(routine()));
  _th->start();
  qDebug() << "Audio::run(): "<< "Thread Started(" << QThread::currentThreadId() << ")" ;
}

void	Audio::stop()
{
  if (_work != 0)
    {
      _work->stop();
      qDebug() << "Audio::stop(): " << "Thread Stopped (" << QThread::currentThreadId() << ")";
	  _th->wait();
	  delete _th;
	  delete _work;
      _work = 0;
	  _th = 0;
    }
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
