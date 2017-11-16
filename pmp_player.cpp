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
    titleImage_Scene=new QGraphicsScene();
    time_of_play=QTime(0,0,0);
    mediaPlayer->setPlaylist(mediaPlaylst);
    currentMedCont_index=0;
    ui->graphicsView->setScene(titleImage_Scene);

    connect(ui->FilepushButton,SIGNAL(clicked(bool)),this,SLOT(on_File_cliced()));
    connect(ui->OptionspushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_Options_cliced()));
    connect(ui->SearchpushButton_3,SIGNAL(clicked(bool)),this,SLOT(on_Serch_cliced()));
    connect(ui->PausepushButton_6,SIGNAL(clicked(bool)),this,SLOT(on_PausePlay_cliced()));
    connect(ui->ValumeSlider,SIGNAL(valueChanged(int)),this,SLOT(on_valume_change()));
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timer_update()));
    connect(mediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(position_changed(qint64)));
    connect(mediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(duration_changed(qint64)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(on_position_changed()));


    connect(mediaPlayer,SIGNAL(metaDataChanged()),this,SLOT(metadata_change()));


    //connect controle playlist
    connect(this,SIGNAL(change_current_media(int)),this, SLOT(on_current_media_changed(int)));
    connect(ui->NextpushButton_8,SIGNAL(clicked(bool)),this,SLOT(on_Next_cliced()));
    connect(ui->BackpushButton_5,SIGNAL(clicked(bool)),this,SLOT(on_Back_cliced()));
    connect(ui->PlaylistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(on_listwidgetintem_cliced(QListWidgetItem*)));



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



    for( QString s : sl)
    {
        mediaPlaylst->addMedia(QUrl::fromLocalFile(s));
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
    emit change_current_media(--currentMedCont_index);
  //currentMedCont_index--;
//ui->PlaylistWidget->setCurrentRow(currentMedCont_index);

  //mediaPlaylst->previous();
}

void PMP_PLayer::on_PausePlay_cliced()
{
 if(isPlaing)
 {
     isPlaing=false;
     mediaPlayer->pause();
     ui->PausepushButton_6->setText("|>");




 }
 else
 {
     isPlaing=true;
     mediaPlayer->play();
     ui->PausepushButton_6->setText("||");
     ui->timeEdit->startTimer(1);

     //time_of_play->setHMS()
 }
}

void PMP_PLayer::on_Next_cliced()
{
    emit change_current_media(++currentMedCont_index);

  //currentMedCont_index--;
  //ui->PlaylistWidget->setCurrentRow(currentMedCont_index);
  //  mediaPlaylst->next();
}

void PMP_PLayer::on_current_media_changed(int i)
{
    emit ui->PlaylistWidget->itemPressed(ui->PlaylistWidget->item(i));

    mediaPlaylst->setCurrentIndex(i);
    ui->PlaylistWidget->setCurrentRow(i);
}

void PMP_PLayer::on_listwidgetintem_cliced(QListWidgetItem* item_point)
{
  emit change_current_media(currentMedCont_index=ui->PlaylistWidget->row(item_point));
}

void PMP_PLayer::on_valume_change()
{

    mediaPlayer->setVolume(ui->ValumeSlider->value());

}

void PMP_PLayer::on_position_changed()
{
    qint64 t=ui->horizontalSlider->value();
    mediaPlayer->setPosition(t);
    QTime tt;
    tt.setHMS(0,0,t);
    ui->timeEdit->setTime(tt);
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


void PMP_PLayer::metadata_change()
{
    //QVariant variant=mediaPlayer->metaData(QMediaMetaData::AlbumTitle);
    ui->Albom_Label->setText(mediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString());
    ui->Auther_label->setText( mediaPlayer->metaData(QMediaMetaData::Author).toString());
    ui->Treck_Label->setText(mediaPlayer->metaData(QMediaMetaData::Title).toString());


}
void PMP_PLayer::duration_changed(qint64 i)
{
 //QTime t(int(i));
 ui->horizontalSlider->setRange(0,i);
//using it colculete h, min,sec and print in label
}
void PMP_PLayer::position_changed(qint64 i)
{
    //ui->horizontalSlider->setTickPosition(i);
    ui->horizontalSlider->setValue(i);
}
