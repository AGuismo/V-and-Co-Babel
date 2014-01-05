#include  <QDebug>
#include  "QTBridge.h"

Bridge::Bridge(std::size_t capacity):
	AudioBridge(capacity)
{

}

Bridge::~Bridge()
{

}

void  Bridge::inputReady()
{
//	qDebug() << QThread::currentThreadId() << "InputReady()";
  _inputReady.wakeAll();
  emit(inputReadReady());
}

void  Bridge::outputReady()
{
//	qDebug() << QThread::currentThreadId() << "OutputReady()";
  _outputReady.wakeAll();
  emit(outputReadReady());
}

void  Bridge::inputRead(input_buffer &buff, std::size_t size, bool blocking)
{
  QMutexLocker  lock(&_inputLock);

  if (blocking && AudioBridge::inputEmpty())
  {
	  qDebug() << QThread::currentThreadId() << "InputRead IN";
	  _inputReady.wait(&_inputLock);
	  qDebug() << QThread::currentThreadId() << "InputRead OUT";
  }
  AudioBridge::inputRead(buff, size, blocking);
}

void  Bridge::inputWrite(const input_buffer &buff)
{
  QMutexLocker  lock(&_inputLock);

  AudioBridge::inputWrite(buff);
}

void  Bridge::inputPush(input &buff)
{
  QMutexLocker  lock(&_inputLock);

  AudioBridge::inputPush(buff);
}

Bridge::input	Bridge::inputPop()
{
  QMutexLocker  lock(&_inputLock);

  return (AudioBridge::inputPop());
}

void  Bridge::outputRead(output_buffer &buff, std::size_t size, bool blocking)
{
  QMutexLocker  lock(&_outputLock);

  if (blocking && AudioBridge::outputEmpty())
  {
	  qDebug() << QThread::currentThreadId() << "OutputRead IN";
	  _outputReady.wait(&_outputLock);
	  qDebug() << QThread::currentThreadId() << "OutputRead OUT";
  }
  AudioBridge::outputRead(buff, size, blocking);
}

void  Bridge::outputWrite(const output_buffer &buff)
{
 QMutexLocker  lock(&_outputLock);

  AudioBridge::outputWrite(buff);
}

Bridge::output	Bridge::outputPop()
{
  QMutexLocker  lock(&_outputLock);

  return (AudioBridge::outputPop());
}

void  Bridge::outputPush(output &buff)
{
 QMutexLocker  lock(&_outputLock);

  AudioBridge::outputPush(buff);
}

AudioChunk	*Bridge::popUnused()
{
	QMutexLocker  lock(&_unusedLock);

	return (AudioBridge::popUnused());
}

void	Bridge::pushUnused(AudioChunk *chunk)
{
	QMutexLocker  lock(&_unusedLock);

	AudioBridge::pushUnused(chunk);
}