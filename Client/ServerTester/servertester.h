#ifndef SERVERTESTER_H
#define SERVERTESTER_H

#include <QMainWindow>
#include <QtWidgets>
#include <QHostAddress>

#include				<map>

#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"CallRequest.hh"
#include	"Protocol.hpp"

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

typedef void (*f_ptr)(ARequest *req);
//typedef	std::map<int, void (*)(ARequest *req)>	RequestMap;
typedef	std::map<int, f_ptr>	RequestMap;

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

	void on_aButton_clicked();
	void on_bButton_clicked();
	void on_cButton_clicked();
	void on_dButton_clicked();
	void on_eButton_clicked();
	void on_fButton_clicked();
	void on_gButton_clicked();
	void on_hButton_clicked();
	void on_iButton_clicked();
	void on_jButton_clicked();
	void on_kButton_clicked();
	void on_lButton_clicked();
	void on_mButton_clicked();
	void on_nButton_clicked();
	void on_oButton_clicked();
	void on_pButton_clicked();
	void on_qButton_clicked();

	void	connection();
	void	appel();
	void	read();
	void	send_req(ARequest *req);
	void	RequestParser(std::vector<Protocol::Byte>	bytes);
	void	init_map();

private:
    Ui::ServerTester	*ui;
    QUdpSocket          *udpSocket;
    QTcpSocket          *tcpSocket;
	QHostAddress		addr;
    QByteArray          buff;
	QString				buffer;

	RequestMap				m;

	int					udpSocket_int;
};

#endif // SERVERTESTER_H
