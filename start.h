#ifndef START_H
#define START_H

#include <QFrame>

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
};

#endif // START_H
