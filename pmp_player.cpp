#include "pmp_player.h"
#include "ui_pmp_player.h"

PMP_PLayer::PMP_PLayer(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PMP_PLayer)
{
    ui->setupUi(this);
}

PMP_PLayer::~PMP_PLayer()
{
    delete ui;
}
