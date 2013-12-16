#include <QtWidgets>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>

#include "servertester.h"
#include "ui_servertester.h"

#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"CallRequest.hh"
#include	"Protocol.hpp"

ServerTester::ServerTester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerTester)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    tcpSocket = new QTcpSocket(this);
    setWindowTitle(tr("Babel Tester"));
    ui->ButtonSend->setEnabled(false);
}

ServerTester::~ServerTester()
{
    delete ui;
}

void ServerTester::on_ButtonSend_clicked()
{
	QByteArray datagram = buff.append(ui->lineEditCmd->text());
    ui->lineEditCmd->clear();
    this->buff.clear();
    tcpSocket->write(datagram.data(), datagram.size());
}

void ServerTester::on_ButtonQuit_clicked()
{
    this->close();
}

void ServerTester::connection()
{
	bool	ok;
	QString	tmp;

	tcpSocket->connectToHost(ui->lineAdress->text(), ui->linePort->text().toInt(&ok));
    if (tcpSocket->waitForConnected(30) == true)
        {
            tmp.append("Connected to host");
            ui->ButtonSend->setEnabled(true);
        }
    else
        {
            tmp.append("Failed to connect to host");
            tcpSocket->close();
        }
	ui->connectStatus->setText(tmp);
}

void ServerTester::on_ButtonConnect_clicked()
{
	ui->connectStatus->setText("Connecting to host...");
	this->connection();
}
