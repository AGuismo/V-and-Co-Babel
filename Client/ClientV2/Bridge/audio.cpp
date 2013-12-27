#include "audio.h"
#include "ui_audio.h"

Audio::Audio(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Audio)
{
  ui->setupUi(this);
}

Audio::~Audio()
{
  delete ui;
}
