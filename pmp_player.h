#ifndef PMP_PLAYER_H
#define PMP_PLAYER_H

#include <QFrame>
#include <QtMultimedia>
#include <QMediaPlayer>

namespace Ui {
class PMP_PLayer;
}

class PMP_PLayer : public QFrame
{
    Q_OBJECT
private:
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

#endif // PMP_PLAYER_H
