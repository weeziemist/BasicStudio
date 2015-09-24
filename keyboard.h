#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "pianokey.h"

class Keyboard : public QWidget
{
    Q_OBJECT
public:
    explicit Keyboard(QString directory, int oct1, int oct2, QWidget *parent = 0);
    void resizeEvent(QResizeEvent *);
    void setWhiteKey(int index, int octave);
    void setBlackKey(int index, int flatIndex, int octave);
    ~Keyboard();

private:
    int octave1;
    int octave2;
    QString keys;
    QString flats;
    QString qwerty;
    QString num;
    QString target;
    PianoKey **whiteKeys;
    PianoKey **blackKeys;

signals:
    
public slots:
    
};

#endif // KEYBOARD_H
