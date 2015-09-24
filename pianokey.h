#ifndef PIANOKEY_H
#define PIANOKEY_H

#include <QPushButton>
#include <QSoundEffect>
#include <QShortcut>

class PianoKey : public QPushButton
{
    Q_OBJECT
public:
    explicit PianoKey(QString type, QString key, QString file, QWidget *parent = 0);
    void setKey(int key);
    void setFile(QString file);
    QShortcut *getShortcut();
    ~PianoKey();

private:
    QString fileName;
    QShortcut *shortcut;
    QSoundEffect *sound;

signals:
    
public slots:
    void play();
    
};

#endif // PIANOKEY_H
