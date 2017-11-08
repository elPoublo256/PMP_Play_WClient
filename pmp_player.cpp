#include "pmp_player.h"
#include "ui_pmp_player.h"

PMP_PLayer::PMP_PLayer(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PMP_PLayer)
{
    options = new PMP_PLayer_options();
    isPlaing=false;
    ui->setupUi(this);
    mediaPlaylst=new QMediaPlaylist();
    mediaPlayer=new QMediaPlayer();
    mediaPlayer->setPlaylist(mediaPlaylst);
    connect(ui->FilepushButton,SIGNAL(clicked(bool)),this,SLOT(on_File_cliced()));
    connect(ui->OptionspushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_Options_cliced()));
    connect(ui->SearchpushButton_3,SIGNAL(clicked(bool)),this,SLOT(on_Serch_cliced()));
    connect(ui->BackpushButton_5,SIGNAL(clicked(bool)),this,SLOT(on_Back_cliced()));
    connect(ui->PausepushButton_6,SIGNAL(clicked(bool)),this,SLOT(on_PausePlay_cliced()));
    //connect(ui->OptionspushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_Options_cliced()));

}

PMP_PLayer::~PMP_PLayer()
{
    delete ui;
    delete mediaPlayer;
    delete mediaPlaylst;
    delete options;
}

void PMP_PLayer::on_File_cliced()
{

}
void PMP_PLayer::on_Options_cliced()
{

}

void PMP_PLayer::on_Serch_cliced()
{

}

void PMP_PLayer::on_exit_cliced()
{

}

void PMP_PLayer::on_Back_cliced()
{

}

void PMP_PLayer::on_PausePlay_cliced()
{

}

 PMP_PLayer_options::PMP_PLayer_options(QWidget* parent) : QWidget(parent)
{

}

 PMP_PLayer_options::~PMP_PLayer_options()
{

}
