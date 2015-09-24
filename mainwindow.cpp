#include "mainwindow.h"
#include <QHBoxLayout>
#include <QScrollArea>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    keys = "zxcvbnm,./";
    DrumBar *bars[8];
    QDirIterator it(":/default/default/");
    int index = 0;
    while(it.hasNext()){
        bars[index] = new DrumBar(it.next(), QString(keys.at(index)));
        index++;
    }
    set = new DrumSet(bars, 8);
    QScrollArea *scroll = new QScrollArea(this);
    scroll->setWidgetResizable(true);
    scroll->setWidget(set);
    loops = new LoopSet();
    QScrollArea *scroll2 = new QScrollArea(this);
    scroll2->setWidgetResizable(true);
    scroll2->setWidget(loops);
    panel = new ControlPanel(this);
    board = new Keyboard(":/grand/grand/", 4, 5, this);
    connect(panel->getKits(), SIGNAL(activated(int)), this, SLOT(setDrumSet(int)));
    connect(panel->getOctave1(), SIGNAL(valueChanged(int)), this, SLOT(setFirst(int)));
    connect(panel->getOctave2(), SIGNAL(valueChanged(int)), this, SLOT(setSecond(int)));
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setSpacing(0);
    hbox->addWidget(scroll);
    hbox->addWidget(scroll2);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setSpacing(0);
    vbox->addLayout(hbox);
    vbox->addWidget(panel);
    vbox->addWidget(board);
    QWidget *central = new QWidget();
    central->setLayout(vbox);
    setCentralWidget(central);
}

void MainWindow::setDrumSet(int index){
    QString paths[] = {":/default/default/", ":/whoadaddy/whoadaddy/", ":/spiccoli/spiccoli/", ":/soundslikedrums/soundslikedrums/", ":/sonic/sonic/", ":/nooffense/nooffense/", ":/ninja/ninja/", ":/house/house/", ":/mpc/mpc/", ":/space1/space1/", ":/space2/space2/", ":/distorted1/distorted1", ":/distorted2/distorted2"};
    QDirIterator it(paths[index]);
    int i = 0;
    panel->setKitName(panel->getKits()->currentText() + " Kit");
    while(it.hasNext()){
        if(set->getBar(i) == NULL)
            set->setNewBar(it.next(), QString(keys.at(i)), i);
        else if(set->getBar(i)->isVisible() == false)
            set->setBarVisible(it.next(), i);
        else
            set->setBar(it.next(), i);
        i++;
    }
    size_t length = set->getSize();
    if(i < length)
        while(length-1 >= i){
            set->remove(length-1);
            length--;
        }
}

void MainWindow::setFirst(int octave){
    for(int i = 0; i < 7; i++)
        board->setWhiteKey(i, octave);
    int index = 0;
    for(int i = 0; i < 5; i++){
        board->setBlackKey(i, index, octave);
        index += 2;
    }
}

void MainWindow::setSecond(int octave){
    for(int i = 7; i < 14; i++)
        board->setWhiteKey(i, octave);
    int index = 0;
    for(int i = 5; i < 10; i++){
        board->setBlackKey(i, index, octave);
        index += 2;
    }
}

MainWindow::~MainWindow()
{
    delete set;
    delete loops;
    delete panel;
    delete board;
}
