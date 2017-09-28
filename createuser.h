#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QFrame>

namespace Ui {
class CreateUser;
}

class CreateUser : public QFrame
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = 0);
    ~CreateUser();

private:
    Ui::CreateUser *ui;
};

#endif // CREATEUSER_H
