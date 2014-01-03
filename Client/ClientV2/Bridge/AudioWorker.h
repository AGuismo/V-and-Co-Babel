#ifndef AUDIOWORKER_H_
# define AUDIOWORKER_H_

#include  <QObject>
#include  <QThread>

class IAudioStream;
class Bridge;

struct	Worker : public QObject
{
  Q_OBJECT

public:
  explicit		Worker(Bridge &);
  virtual		~Worker();

public slots:
  void		routine();

public:
  void		stop();

signals:
  void		workFinished();

private:
  IAudioStream	*_audio;// Seb Object
};



#endif /* AUDIOWORKER_H_ */
