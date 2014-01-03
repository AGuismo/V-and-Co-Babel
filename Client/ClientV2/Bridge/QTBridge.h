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
  Bridge();
  virtual ~Bridge();

public:
  void    inputRead(input_buffer &, std::size_t, bool blocking = true);
  void    inputWrite(const input_buffer &);
  void    inputReady();

  void    outputRead(output_buffer &, std::size_t size, bool blocking = true);
  void    outputWrite(const output_buffer &);
  void    outputReady();

signals:
  void    inputReadReady();
  void    outputReadReady();

private:
  QMutex		_inputLock;
  QMutex		_outputLock;
  QWaitCondition	_inputReady;
  QWaitCondition	_outputReady;
};

#endif // QTBRIDGE_H
