#ifndef PMP_PLAYER_H
#define PMP_PLAYER_H

#include <QFrame>
#include <QtMultimedia>
#include <QMediaPlayer>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QBrush>
#include <QLabel>
#include <QLineEdit>
class Base_OpWg;
class PMP_PLayer_options;
namespace Ui {
class PMP_PLayer;
}

class PMP_PLayer : public QFrame
{
    Q_OBJECT
private:
    PMP_PLayer_options* options;
    bool isPlaing;
    QMediaPlaylist* mediaPlaylst;//http://doc.qt.io/qt-5/qmediaplaylist.html
    QMediaPlayer* mediaPlayer;

public:
    explicit PMP_PLayer(QWidget *parent = 0);
    ~PMP_PLayer();

private:
    Ui::PMP_PLayer *ui;
signals:

public slots:
    void on_File_cliced();
    void on_Options_cliced();
    void on_Serch_cliced();
    void on_exit_cliced();
    void on_Back_cliced();
    void on_PausePlay_cliced();

};

class Base_OpWg : public QWidget
{
    Q_OBJECT
private:
public:
    Base_OpWg(){}
Base_OpWg(QString battonString,QString lineEditString,
QString labelString,QString string_string);
~Base_OpWg();
    QPushButton* button;
    QLineEdit* line_edit;
    QLabel* label;
    QString* sstring;
    QHBoxLayout* hblayout;

};

class PMP_PLayer_options : public QWidget
{

    ///this class provide optins for PMP_Player
    /// like fomt
    ///
    Q_OBJECT
private:
//protected:
public:
    //QString Font_of_PMP_Player;
    ///there are mambers using for chois font of PMP_Player
   // Base_OpWg font_opt;
    QBrush* Brush_PMP_Player;

    ///there are member for chois a statr directory
    /// when user chois local file
    /// for adding in playlist
   // Base_OpWg directory_opt;






public:
    PMP_PLayer_options(QWidget* parent=NULL);
    ~PMP_PLayer_options();
public slots:
    void aplay_font();
    void aplay_directory();



};

#endif // PMP_PLAYER_H
