#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    connect(ui->CreateUserpushButton,SIGNAL(clicked(bool)),this,SLOT(send_NewUser()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(send_LoginPosward()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
}

Start::~Start()
{
    delete ui;
}
void Start::send_LoginPosward()
{

}
void Start::send_NewUser()
{

}
