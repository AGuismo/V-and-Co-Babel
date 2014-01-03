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
  emit(inputReadReady());
}

void  Bridge::outputReady()
{
  emit(outputReadReady());
}

void  Bridge::inputRead(input_buffer &buff, std::size_t size, bool blocking)
{
  QMutexLocker  lock(&_inputLock);

  if (blocking && AudioBridge::inputEmpty())
    _inputReady.wait(&_inputLock);
  AudioBridge::inputRead(buff, size, blocking);
}

void  Bridge::inputWrite(const input_buffer &buff)
{
  QMutexLocker  lock(&_inputLock);

  AudioBridge::inputWrite(buff);
  if (!AudioBridge::inputEmpty())
    _inputReady.wakeAll();
}

void  Bridge::outputRead(output_buffer &buff, std::size_t size, bool blocking)
{
  QMutexLocker  lock(&_outputLock);

  if (blocking && AudioBridge::outputEmpty())
    _outputReady.wait(&_outputLock);
  AudioBridge::outputRead(buff, size, blocking);
}

void  Bridge::outputWrite(const output_buffer &buff)
{
 QMutexLocker  lock(&_outputLock);

  AudioBridge::outputWrite(buff);
  if (!AudioBridge::outputEmpty())
    _outputReady.wakeAll();
}
