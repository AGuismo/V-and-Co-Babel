#ifndef SERVERTESTER_H
#define SERVERTESTER_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QPushButton;
class QTimer;
class QUdpSocket;
class QTcpSocket;
QT_END_NAMESPACE

namespace Ui {
class ServerTester;
}

class ServerTester : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerTester(QWidget *parent = 0);
    ~ServerTester();

private slots:
    void on_ButtonQuit_clicked();
	void on_ButtonSend_clicked();
    void on_ButtonConnect_clicked();

private:
    Ui::ServerTester	*ui;
    QUdpSocket          *udpSocket;
    QTcpSocket          *tcpSocket;
    QByteArray          buff;
};

#endif // SERVERTESTER_H
