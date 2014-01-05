#ifndef QTBRIDGE_H
#define QTBRIDGE_H

# include	<QObject>
# include	<QThread>
# include	<QMutex>
# include	<QWaitCondition>
# include	"AudioBridge.hh"

class Bridge : public QObject, public AudioBridge
{
  Q_OBJECT
public:
  Bridge(std::size_t capacity);
  virtual ~Bridge();

public:
  void			inputRead(input_buffer &, std::size_t, bool blocking = true);
  void			inputWrite(const input_buffer &);
  void			inputPush(input &);
  input			inputPop();
  void			inputReady();

  void			outputRead(output_buffer &, std::size_t size, bool blocking = true);
  void			outputWrite(const output_buffer &);
  void			outputPush(input &);
  output		outputPop();
  void			outputReady();

  void			pushUnused(AudioChunk *);
  AudioChunk	*popUnused();

signals:
  void			inputReadReady();
  void			outputReadReady();

private:
  QMutex		_inputLock;
  QMutex		_outputLock;
  QMutex		_unusedLock;
  QWaitCondition	_inputReady;
  QWaitCondition	_outputReady;
};

#endif // QTBRIDGE_H
