#ifndef QTBRIDGE_H
#define QTBRIDGE_H

# include   <QObject>
# include   <QThread>
# include   <QMutex>
# include  "AudioBridge.hh"

class Bridge : public QObject, public AudioBridge
{
  Q_OBJECT
public:
  Bridge();
  virtual ~Bridge();

public:
  void    inputRead(input_buffer &, std::size_t);
  void    inputWrite(const input_buffer &);
  void    inputReady();

  void    outputRead(output_buffer &, std::size_t size);
  void    outputWrite(const output_buffer &);
  void    outputReady();

signals:
  void    inputReadReady();
  void    outputReadReady();

private:
  QMutex  _inputLock;
  QMutex  _outputLock;
};

#endif // QTBRIDGE_H
