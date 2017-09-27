#include "myclient.h"

MyClient::MyClient(const QString& strHost,int nPrt,QWidget *parent) : QWidget(parent), m_nNextBlockSize(0)
{
    m_pTcpSokcket = new QTcpSocket(this);
    m_pTcpSokcket->connectToHost(strHost,nPrt);
    connect(m_pTcpSokcket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(m_pTcpSokcket, SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(m_pTcpSokcket,SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));


    m_ptxtInfo = new QTextEdit;
    m_ptxtInput = new QLineEdit;
    connect(m_ptxtInput, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));
    m_ptxtInfo->setReadOnly(true);
    QPushButton* pcmd = new QPushButton("&Send");
    connect(pcmd,SIGNAL(clicked(bool)), this,SLOT(slotSendToServer()));
    //Layout setup
       QVBoxLayout* pvbxLayout = new QVBoxLayout;
       pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
       pvbxLayout->addWidget(m_ptxtInfo);
       pvbxLayout->addWidget(m_ptxtInput);
       pvbxLayout->addWidget(pcmd);
       setLayout(pvbxLayout);
}

void MyClient::slotReadyRead()
{
 QDataStream in(m_pTcpSokcket);
 in.setVersion(QDataStream::Qt_4_2);
 for(;;)
 {
     if(!m_nNextBlockSize)
     {
         if(m_pTcpSokcket->bytesAvailable()<sizeof(quint16))
         {
             break;
         }
     }
     if(m_pTcpSokcket->bytesAvailable()<m_nNextBlockSize){break;}
     QTime time;
     QString str;
     in >> time >>str;
     m_ptxtInfo->append(time.toString()+" "+str);
     m_nNextBlockSize=0;
 }
}
void MyClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                         "The host was not found." :
                         err == QAbstractSocket::RemoteHostClosedError ?
                         "The remote host is closed." :
                         err == QAbstractSocket::ConnectionRefusedError ?
                         "The connection was refused." :
                         QString()
                        );
        m_ptxtInfo->append(strError);
}

void MyClient::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out<<quint16(0)<<QTime::currentTime()<<m_ptxtInput->text();
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(quint16));
    m_pTcpSokcket->write(arrBlock);
    m_ptxtInput->setText("");
}

void MyClient::slotConnected()
{
 m_ptxtInfo->append("AAAAAAAA!!!!!Go a way!!!!");
}
