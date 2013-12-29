#include	<QDebug>
#include	"PAudioStream.hh"
#include	"AudioWorker.h"
#include	"QTBridge.h"

Worker::Worker(Bridge &bridge)
{
  qDebug() << "Audio::Worker::~Worker(): " << this << " Started(" << QThread::currentThreadId() << ")";
  _audio = new PAudioStream(bridge);
}

Worker::~Worker()
{
  qDebug() << "Audio::Worker::~Worker(): " << this << " Stopped(" << QThread::currentThreadId() << ")";
}

void	Worker::stop()
{
  _audio->stop();
  qDebug() << "Audio::Worker::stop()(" << QThread::currentThreadId() << ")";
}

void	Worker::routine()
{
  qDebug() << "Audio::Worker::routine(): " << "Started(" << QThread::currentThreadId() << ")" ;
  if (_audio->init())
    _audio->run();
  thread()->quit();
  qDebug() << "Audio::Worker::routine(): " << "Ended(" << QThread::currentThreadId() << ")" ;
}
