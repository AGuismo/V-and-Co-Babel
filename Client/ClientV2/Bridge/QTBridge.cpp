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
	qDebug() << QThread::currentThreadId() << "InputReady()";
  _inputReady.wakeAll();
  emit(inputReadReady());
}

void  Bridge::outputReady()
{
	qDebug() << QThread::currentThreadId() << "OutputReady()";
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
