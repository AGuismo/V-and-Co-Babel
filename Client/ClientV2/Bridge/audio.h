#ifndef AUDIO_H
#define AUDIO_H

#include <QWidget>

namespace Ui {
  class Audio;
}

class Audio : public QWidget
{
  Q_OBJECT
  
public:
  explicit Audio(QWidget *parent = 0);
  ~Audio();
  
private:
  Ui::Audio *ui;
};

#endif // AUDIO_H
