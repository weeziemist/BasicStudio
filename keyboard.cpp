#include "keyboard.h"
#include <QVBoxLayout>

Keyboard::Keyboard(QString directory, int oct1, int oct2, QWidget *parent) :
    QWidget(parent)
{
    octave1 = oct1;
    octave2 = oct2;
    keys = "CDEFGABCDEFGAB";
    flats = "DbEbGbAbBbDbEbGbAbBb";
    qwerty = " qwertyuiop[]";
    num = "1245689-=";
    target = directory;
    whiteKeys = new PianoKey*[14];
    QHBoxLayout *hbox = new QHBoxLayout();
    whiteKeys[0] = new PianoKey("white", "", target + "C" + QString::number(octave1) + ".wav", this);
    whiteKeys[0]->setKey(Qt::Key_Tab);
    hbox->addWidget(whiteKeys[0]);
    for(int i = 1; i < 7; i++){
        whiteKeys[i] = new PianoKey("white", QString(qwerty.at(i)), target + QString(keys.at(i)) + QString::number(octave1) + ".wav", this);
        hbox->addWidget(whiteKeys[i]);
    }
    for(int i = 7; i < 13; i++){
        whiteKeys[i] = new PianoKey("white", QString(qwerty.at(i)), target + QString(keys.at(i)) + QString::number(octave2) + ".wav", this);
        hbox->addWidget(whiteKeys[i]);
    }
    whiteKeys[13] = new PianoKey("white", "", target + "B" + QString::number(octave2) + ".wav", this);
    whiteKeys[13]->setKey(Qt::Key_Backslash);
    hbox->addWidget(whiteKeys[13]);
    blackKeys = new PianoKey*[10];
    int index = 0;
    for(int i = 0; i < 5; i++){
        blackKeys[i] = new PianoKey("black", QString(num.at(i)), target + QString(flats.at(index)) + QString(flats.at(index+1)) + QString::number(octave1) + ".wav", this);
        index += 2;
    }
    for(int i = 5; i < 9; i++){
        blackKeys[i] = new PianoKey("black", QString(num.at(i)), target + QString(flats.at(index)) + QString(flats.at(index+1)) + QString::number(octave2) + ".wav", this);
        index += 2;
    }
    blackKeys[9] = new PianoKey("black", "", directory + "Bb" + QString::number(octave2) + ".wav", this);
    blackKeys[9]->setKey(Qt::Key_Backspace);
    setLayout(hbox);
}

void Keyboard::setWhiteKey(int index, int octave){
    whiteKeys[index]->setFile(target + QString(keys.at(index)) + QString::number(octave) + ".wav");
}

void Keyboard::setBlackKey(int index, int flatIndex, int octave){
    blackKeys[index]->setFile(target + QString(flats.at(flatIndex)) + QString(flats.at(flatIndex+1)) + QString::number(octave) + ".wav");
}

void Keyboard::resizeEvent(QResizeEvent *){
    int w = whiteKeys[0]->width();
    blackKeys[0]->move(w-25, 8);
    blackKeys[1]->move(whiteKeys[1]->x()+w-25, 8);
    blackKeys[2]->move(whiteKeys[3]->x()+w-25, 8);
    blackKeys[3]->move(whiteKeys[4]->x()+w-25, 8);
    blackKeys[4]->move(whiteKeys[5]->x()+w-25, 8);
    blackKeys[5]->move(whiteKeys[7]->x()+w-25, 8);
    blackKeys[6]->move(whiteKeys[8]->x()+w-25, 8);
    blackKeys[7]->move(whiteKeys[10]->x()+w-25, 8);
    blackKeys[8]->move(whiteKeys[11]->x()+w-25, 8);
    blackKeys[9]->move(whiteKeys[12]->x()+w-25, 8);
}

Keyboard::~Keyboard(){
    delete[] whiteKeys;
    delete[] blackKeys;
}
