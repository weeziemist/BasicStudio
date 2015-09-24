#ifndef DRUMBAR_H
#define DRUMBAR_H

#include <QWidget>
#include <QSoundEffect>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QShortcut>
#include <QFileDialog>

class DrumBar : public QWidget
{
    Q_OBJECT
public:
    explicit DrumBar(QString fileName, QString key, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setFile(QString fileName);
    QString getName();
    ~DrumBar();

private:
    QLabel *name;
    QSlider *volume;
    QPushButton *fileOpen;
    QPushButton *player;
    QSoundEffect *sound;
    QString type;
    QShortcut *shortcut;
    
signals:
    

public slots:
    void setVolume(int);
    void openDialog();
    void click();
    void play();
};

#endif // DRUMBAR_H
