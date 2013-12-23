

#include <QtWidgets>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QDebug>

#include "servertester.h"
#include "ui_servertester.h"

/************** SERVER CODES **************\
			OK = 1000 
			BAD_REQ = 1001
			FORBIDDEN = 1002
			NOT_IMPLEMENTED = 1003
			NO_CONTENT = 1004
			PARTIAL_CONTENT = 1005
			NO_SLOTS = 1006
			HANDSHAKE = 1100
			MISSED_CALLS = 1200
			STREAM_DATA = 1201
			GET_MISSED = 1202
			AUTO_ANSWER = 1203
			PING = 1204
			UPDATE = 1300
			TIMEOUT = 1400
\************** SERVER CODES **************/

void		ok(ARequest *req)
{
	req = req;
	qDebug() << "FONCTION OK !";
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

	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(read()));
	connect(ui->ButtonConnect, SIGNAL(clicked()), this, SLOT(connection()));
	connect(this, SIGNAL(read()), this, SLOT(RequestParser()));
	init_map();
}

ServerTester::~ServerTester()
{
    delete ui;
}

void		ServerTester::init_map()
{
	m.insert(std::make_pair(1000, &ok));
	/*m.insert(std::make_pair(1001, &bad_req));
	m.insert(std::make_pair(1002, &ko));
	m.insert(std::make_pair(1003, &not_implemented));
	m.insert(std::make_pair(1004, &no_content));
	m.insert(std::make_pair(1005, &partial_content));
	m.insert(std::make_pair(1006, &no_slots));
	m.insert(std::make_pair(1100, &handshake));
	m.insert(std::make_pair(1200, &missed_calls));
	m.insert(std::make_pair(1201, &stream_dada));
	m.insert(std::make_pair(1202, &get_missed));
	m.insert(std::make_pair(1203, &auto_answer));
	m.insert(std::make_pair(1204, &ping));
	m.insert(std::make_pair(1300, &update));
	m.insert(std::make_pair(1400, &timeout));*/
}

void		ServerTester::send_req(ARequest *req)
{
    std::vector<Protocol::Byte>	bytes;
	std::vector<Protocol::Byte>::const_iterator	it;

    std::cout << "Send request code: " << req->code() << std::endl;
    bytes = Protocol::product(*req);
	QByteArray datagram;
	for (it = bytes.begin(); it != bytes.end(); ++it)
		datagram.push_back(*it);
    tcpSocket->write(datagram.data(), datagram.size());
}

void	ServerTester::RequestParser(std::vector<Protocol::Byte>	bytes)
{
	int							count;
    ARequest					*req;

	req = Protocol::consume(bytes, count);
	buffer += QString::number(req->code());
	qDebug() << QString(buffer);
	ui->ServerBrowser->append(buffer);
	buffer.clear();

	RequestMap::const_iterator it = m.find(req->code());
	if (it == m.end())
        qDebug() << "function not found in the map !";
	else
		it->second(req);
}

void	ServerTester::read()
{
	std::vector<Protocol::Byte>	bytes;
	QByteArray					buff;

    if (tcpSocket->bytesAvailable() != 0)
		buff += tcpSocket->readAll();
	bytes.assign(buff.data(), buff.data() + buff.size());

	RequestParser(bytes);
}

void	ServerTester::appel()
{
	QByteArray datagram = "J'APPEL !";
	udpSocket->writeDatagram(datagram.data(), datagram.size(), addr, this->udpSocket_int);
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
	buffer = "Creation d'un client toto : ";
	send_req(new request::auth::client::NewClient("toto", md5("poil"), false));
}

void ServerTester::on_bButton_clicked()
{
	buffer = "Creation d'un client tata : ";
	send_req(new request::auth::client::NewClient("tata", md5("poil"), false));
}

void ServerTester::on_cButton_clicked()
{
	buffer = "Connection sur le compte toto : ";
	send_req(new request::auth::client::ConnectClient("toto", md5("poil")));
}

void ServerTester::on_dButton_clicked()
{	
	buffer = "Connection sur le compte tata : ";
	send_req(new request::auth::client::ConnectClient("tata", md5("poil")));
}

void ServerTester::on_eButton_clicked()
{
	buffer = "Appel de toto vers tata : ";
	send_req(new request::call::client::CallClient("toto", "tata", 1, 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_fButton_clicked()
{
	buffer = "Appel de tata vers toto : ";
	send_req(new request::call::client::CallClient("tata", "toto", 1, 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_gButton_clicked()
{
	buffer = "Reponse de toto : ";
	send_req(new request::call::client::AcceptClient("toto", "tata", 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_hButton_clicked()
{
	buffer = "Reponse de tata : ";
	send_req(new request::call::client::AcceptClient("tata", "toto", 0x7F000001, (short)udpSocket_int));
}

void ServerTester::on_iButton_clicked()
{
	buffer = "Refus de toto : ";
	send_req(new request::call::client::RefuseClient("toto", "tata"));
}

void ServerTester::on_jButton_clicked()
{
	buffer = "Refus de tata : ";
	send_req(new request::call::client::RefuseClient("tata", "toto"));
}

void ServerTester::on_kButton_clicked()
{
	buffer = "Deconnection du client : ";
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
	QString	tmp;

	udpSocket_int = ui->linePortUDP->text().toInt();
	tcpSocket->connectToHost(ui->lineAdress->text(), ui->linePortTCP->text().toInt());
    if (tcpSocket->waitForConnected(300) == true)
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
	addr.setAddress(ui->lineAdress->text());
	buffer = "Connection au serveur : ";
}
