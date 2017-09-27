#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QWidget>
#include<QTcpSocket>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDataStream>
#include <QTime>
#include <QVBoxLayout>
#include <QLabel>
class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSokcket;
    QTextEdit* m_ptxtInfo;
    QLineEdit* m_ptxtInput;
    quint16 m_nNextBlockSize;

public:
     MyClient(const QString& strHost, int nPrt, QWidget *parent = 0);

signals:

public slots:
     void slotReadyRead();
     void slotError(QAbstractSocket::SocketError err);
     void slotSendToServer();
     void slotConnected();
};

#endif // MYCLIENT_H
