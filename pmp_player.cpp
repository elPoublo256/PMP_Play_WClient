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
    QString dirr=*(options->directory_opt->sstring);
    QStringList sl = QFileDialog::getOpenFileNames(this,"What you'd like hear?",dirr);
    for( QString s : sl)
    {
        QStringList ssl=s.split("/");
         QString sss=ssl[ssl.size()-1];
        ui->PlaylistWidget->addItem(sss);

    }


}
void PMP_PLayer::on_Options_cliced()
{
    options->show();

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



Base_OpWg::Base_OpWg(QString battonString, QString lineEditString,
  QString labelString, QString string_string) : QWidget(0)
{
 button=new QPushButton(battonString);
 line_edit=new QLineEdit(lineEditString);
 label=new QLabel(labelString);
 sstring=new QString(string_string);
 hblayout=new QHBoxLayout;
 hblayout->addWidget(label);
 hblayout->addWidget(line_edit);
 hblayout->addWidget(button);
 this->setLayout(hblayout); ///
}


Base_OpWg::~Base_OpWg()
{
    delete button;
    delete line_edit;
    delete label;
    delete sstring;
}



 PMP_PLayer_options::PMP_PLayer_options(QWidget* parent) : QWidget(parent)
{
     directory_opt=new Base_OpWg("applay","/home/","start directory","/home/");

}

 PMP_PLayer_options::~PMP_PLayer_options()
{

}
 void PMP_PLayer_options::aplay_font()
 {

 }
void PMP_PLayer_options::aplay_directory()
{

}
