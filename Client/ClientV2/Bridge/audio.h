#ifndef AUDIO_H
#define AUDIO_H

#include  <QObject>
#include  <QThread>
#include  "QTBridge.h"

class IAudioStream;

class Audio : public QObject
{
  Q_OBJECT
  
public:
  explicit Audio(Bridge &);
  ~Audio();

public:
  void  run();

private slots:
  void  routine();

private:
  Bridge        &_bridge;
  QThread       _th;
  IAudioStream  *_audio;// Seb Object
};

#endif // AUDIO_H
