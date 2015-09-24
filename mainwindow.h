#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drumset.h"
#include "loopset.h"
#include "controlpanel.h"
#include "keyboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    DrumSet *set;
    LoopSet *loops;
    ControlPanel *panel;
    Keyboard *board;
    QString keys;

public slots:
    void setDrumSet(int index);
    void setFirst(int octave);
    void setSecond(int octave);
};

#endif // MAINWINDOW_H
