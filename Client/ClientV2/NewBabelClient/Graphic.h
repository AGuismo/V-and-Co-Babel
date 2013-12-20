#ifndef GRAPHIC_H
#define GRAPHIC_H

#include		<QtWidgets/QMainWindow>
#include		"ui_Graphic.h"
#include		"AGraphic.hh"

class Graphic : public QMainWindow//, public AGraphic
{
	Q_OBJECT

public:
	Graphic(QWidget *parent = 0);
	~Graphic();

private:
	Ui::GraphicClass ui;
};

#endif // GRAPHIC_H
