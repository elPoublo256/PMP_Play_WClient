#include "pmp_player.h"
#include "ui_pmp_player.h"

PMP_PLayer::PMP_PLayer(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PMP_PLayer)
{
    timer=new QTimer;
    options = new PMP_PLayer_options();
    isPlaing=false;
    ui->setupUi(this);
    mediaPlaylst=new QMediaPlaylist();
    mediaPlayer=new QMediaPlayer();

    time_of_play=QTime(0,0,0);
    mediaPlayer->setPlaylist(mediaPlaylst);
    connect(ui->FilepushButton,SIGNAL(clicked(bool)),this,SLOT(on_File_cliced()));
    connect(ui->OptionspushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_Options_cliced()));
    connect(ui->SearchpushButton_3,SIGNAL(clicked(bool)),this,SLOT(on_Serch_cliced()));
    connect(ui->BackpushButton_5,SIGNAL(clicked(bool)),this,SLOT(on_Back_cliced()));
    connect(ui->PausepushButton_6,SIGNAL(clicked(bool)),this,SLOT(on_PausePlay_cliced()));
    connect(ui->NextpushButton_8,SIGNAL(clicked(bool)),this,SLOT(on_Next_cliced()));
    connect(ui->ValumeSlider,SIGNAL(valueChanged(int)),this,SLOT(on_valume_change()));
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timer_update()));
    ui->ValumeSlider->setValue(50);

}

PMP_PLayer::~PMP_PLayer()
{
    delete ui;
    delete mediaPlayer;
    delete mediaPlaylst;
    delete options;
    delete timer;
}

void PMP_PLayer::on_File_cliced()
{
    QString dirr=*(options->directory_opt->sstring);
    QStringList sl = QFileDialog::getOpenFileNames(this,"What you'd like hear?",dirr);
    bool dog=false;
    if(ui->PlaylistWidget->count()==0)
    {
        dog=true;
    }

    for( QString s : sl)
    {
        mediaPlaylst->addMedia(QUrl::fromLocalFile(s));
        QStringList ssl=s.split("/");
         QString sss=ssl[ssl.size()-1];
        ui->PlaylistWidget->addItem(sss);

    }
    if(dog)
    {
        currentMedCont_index=0;
        ui->PlaylistWidget->setCurrentRow(0);

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
  mediaPlaylst->previous();
}

void PMP_PLayer::on_PausePlay_cliced()
{
 if(isPlaing)
 {
     isPlaing=false;
     mediaPlayer->pause();
     ui->PausepushButton_6->setText("|>");
     timer->stop();



 }
 else
 {
     isPlaing=true;
     mediaPlayer->play();
     ui->PausepushButton_6->setText("||");
     ui->timeEdit->startTimer(1);
     timer->start(1000);


     //time_of_play->setHMS()
 }
}

void PMP_PLayer::on_Next_cliced()
{
    mediaPlaylst->next();
}

void PMP_PLayer::on_valume_change()
{
    mediaPlayer->setVolume(ui->ValumeSlider->value());
}

void PMP_PLayer::timer_update()
{


    ui->timeEdit->setTime(time_of_play);
}

void PMP_PLayer::on_current_media_changed_from_back_but()
{

}
void PMP_PLayer::on_current_media_changed_from_next_but()
{

}
void PMP_PLayer::on_current_media_changed_from_listwidget()
{

}

void PMP_PLayer::on_current_media_changed()
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
QTime operator +(QTime a,QTime b)
{
    int hh=a.hour()+b.hour();
    int mm=a.minute()+b.minute();
    int ss=a.second()+b.second();
    if(mm>=60)
    {
        hh++;
        mm=mm-60;
    }
    if(mm>=60)
    {
        hh++;
        mm=mm-60;
    }
    if(ss>=60)
    {
        mm++;
        ss=ss-60;
        if(mm>=60)
        {
            hh++;
            mm=mm-60;
        }
    }

     QTime res;
     return res;
}
