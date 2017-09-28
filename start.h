#ifndef START_H
#define START_H

#include <QFrame>
#include <QTcpSocket>
#include <createuser.h>
#include <pmp_player.h>
namespace Ui {
class Start;
}

class Start : public QFrame
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();


private:
    Ui::Start *ui;
private slots:
    void send_LoginPosward();
    void send_NewUser();

};

#endif // START_H
