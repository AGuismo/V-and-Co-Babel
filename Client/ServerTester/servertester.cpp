#include <QtWidgets>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

#include "servertester.h"
#include "ui_servertester.h"

void		ServerTester::send_req(ARequest *req)
  {
    std::vector<Protocol::Byte>	bytes;
	std::vector<Protocol::Byte>::const_iterator	it;

    std::cout << "Send request code: " << req->code()
	      << std::endl;
    bytes = Protocol::product(*req);
	QByteArray datagram;
	for (it = bytes.begin(); it != bytes.end(); ++it)
		datagram.push_back(*it);
    tcpSocket->write(datagram.data(), datagram.size());
    //_client->writeTCP(bytes);
  }

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

void	ServerTester::appel()
{
	QByteArray datagram = "J'APPEL !";
	//QHostAdress(ui->lineAdress->text());

/*	while (1)
	{
		//udpSocket->writeDatagram(datagram.data(), datagram.size(), (ui->lineAdress->text()), this->udpSocket_int());
	}*/
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

void ServerTester::on_aButton_clicked()
{
	send_req(new request::auth::client::NewClient("toto", md5("poil"), false));
}

void ServerTester::on_bButton_clicked()
{
	send_req(new request::auth::client::NewClient("tata", md5("poil"), false));
}

void ServerTester::on_cButton_clicked()
{
	send_req(new request::auth::client::ConnectClient("toto", md5("poil")));
}

void ServerTester::on_dButton_clicked()
{	
	send_req(new request::auth::client::ConnectClient("tata", md5("poil")));
}

void ServerTester::on_eButton_clicked()
{
	send_req(new request::call::client::CallClient("toto", "tata", 1, 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_fButton_clicked()
{
	send_req(new request::call::client::CallClient("tata", "toto", 1, 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_gButton_clicked()
{
	send_req(new request::call::client::AcceptClient("toto", "tata", 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_hButton_clicked()
{
	send_req(new request::call::client::AcceptClient("tata", "toto", 0x7F000001, (short)udpSocket_int));
	appel();
}

void ServerTester::on_iButton_clicked()
{
	send_req(new request::call::client::RefuseClient("toto", "tata"));
}

void ServerTester::on_jButton_clicked()
{
	send_req(new request::call::client::RefuseClient("tata", "toto"));
}

void ServerTester::on_kButton_clicked()
{
	send_req(new request::auth::client::DisconnectClient());
}

void ServerTester::on_lButton_clicked()
{}

void ServerTester::on_mButton_clicked()
{}

void ServerTester::on_nButton_clicked()
{}

void ServerTester::on_oButton_clicked()
{}

void ServerTester::on_pButton_clicked()
{}

void ServerTester::on_qButton_clicked()
{}

void ServerTester::connection()
{
	bool	ok;
	bool	ok2;
	QString	tmp;

	udpSocket_int = ui->linePortUDP->text().toInt(&ok2);
	tcpSocket->connectToHost(ui->lineAdress->text(), ui->linePortTCP->text().toInt(&ok));
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
