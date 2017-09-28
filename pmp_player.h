#ifndef PMP_PLAYER_H
#define PMP_PLAYER_H

#include <QFrame>

namespace Ui {
class PMP_PLayer;
}

class PMP_PLayer : public QFrame
{
    Q_OBJECT
private:

public:
    explicit PMP_PLayer(QWidget *parent = 0);
    ~PMP_PLayer();

private:
    Ui::PMP_PLayer *ui;
};

#endif // PMP_PLAYER_H
