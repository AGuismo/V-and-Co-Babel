#ifndef AUDIO_H
#define AUDIO_H

#include  <QObject>
#include  <QThread>
#include  "QTBridge.h"

class Worker;

class Audio : public QObject
{
  Q_OBJECT

public:
  explicit	Audio(Bridge &);
  virtual	~Audio();

public slots:
  void  run();
  void	stop();

signals:
  void	stopWork();

private:
  Bridge	&_bridge;
  QThread	*_th;
  Worker	*_work;
};

#endif // AUDIO_H
