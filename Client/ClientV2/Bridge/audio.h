#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include  "QTBridge.h"

class Audio : public QObject
{
  Q_OBJECT
  
public:
  explicit Audio(Bridge &);
  ~Audio();

public slots:
  void  run();

private:
  void  routine();

private:
  Bridge    &_bridge;
  // Seb Object
};

#endif // AUDIO_H
