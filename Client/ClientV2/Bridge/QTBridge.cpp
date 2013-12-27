#include  <QDebug>
#include  "QTBridge.h"

Bridge::Bridge()
{

}

Bridge::~Bridge()
{

}

void  Bridge::inputReady()
{
  qDebug() << __PRETTY_FUNCTION__;
  emit(inputReadReady());
}

void  Bridge::outputReady()
{
  qDebug() << __PRETTY_FUNCTION__;
  emit(outputReadReady());
}

void  Bridge::inputRead(input_buffer &buff, std::size_t size)
{
//  QMutexLocker  lock(&_inputLock);

  AudioBridge::inputRead(buff, size);
}

void  Bridge::inputWrite(const input_buffer &buff)
{
//  QMutexLocker  lock(&_inputLock);

  AudioBridge::inputWrite(buff);
}

void  Bridge::outputRead(output_buffer &buff, std::size_t size)
{
//  QMutexLocker  lock(&_outputLock);

  AudioBridge::outputRead(buff, size);
}

void  Bridge::outputWrite(const output_buffer &buff)
{
 // QMutexLocker  lock(&_outputLock);

  AudioBridge::outputWrite(buff);
}
