#include "pianokey.h"

PianoKey::PianoKey(QString type, QString key, QString file, QWidget *parent) :
    QPushButton(parent)
{
    fileName = file;
    shortcut = new QShortcut(key, this);
    shortcut->setAutoRepeat(false);
    sound = new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(fileName));
    connect(this, SIGNAL(clicked()), this, SLOT(play()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(play()));
    if(type.compare("black") == 0){
        setStyleSheet("background-image: url(:/new/prefix1/blackkey.png); min-height: 135; max-width: 50");
    }
    else if(type.compare("white") == 0)
        setStyleSheet("background-image: url(:/new/prefix1/whitekey.png); min-height: 200; min-width: 50");
}

void PianoKey::setKey(int key){
    shortcut->setKey(key);
}

void PianoKey::setFile(QString file){
    fileName = file;
    sound->setSource(QUrl::fromLocalFile(fileName));
}

QShortcut *PianoKey::getShortcut(){
    return shortcut;
}

void PianoKey::play(){
    sound->play();
}

PianoKey::~PianoKey(){
    delete sound;
    delete shortcut;
}
