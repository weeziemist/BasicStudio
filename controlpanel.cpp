#include "controlpanel.h"
#include <QHBoxLayout>
#include <QPainter>

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("ControlPanel {border-image: url(:/new/prefix1/panel.jpg);}");
    kits = new QComboBox(this);
    kits->addItem("Default");
    kits->addItem("Whoa Daddy");
    kits->addItem("Spiccoli");
    kits->addItem("Sounds Like Drums");
    kits->addItem("Sonic");
    kits->addItem("No Offense");
    kits->addItem("Ninja");
    kits->addItem("House of Mod");
    kits->addItem("Goldbaby MPC");
    kits->addItem("Super Space 1");
    kits->addItem("Super Space 2");
    kits->addItem("Distorted 1");
    kits->addItem("Distorted 2");
    kitName = new QLabel("Default Kit", this);
    recorder = new QPushButton(this);
    recorder->setStyleSheet("background-image: url(:/new/prefix1/record.png); background-repeat: no-repeat; background-position: center center; min-height: 50; min-width: 50");
    recorder->setFlat(true);
    player = new QPushButton(this);
    player->setStyleSheet("background-image: url(:/new/prefix1/play.png); background-repeat: no-repeat; background-position: center center; min-height: 100; min-width: 100");
    player->setFlat(true);
    looper = new QPushButton(this);
    looper->setStyleSheet("background-image: url(:/new/prefix1/loop.png); background-repeat: no-repeat; background-position: center center; min-height: 50; min-width: 50");
    looper->setFlat(true);
    octave1 = new QSpinBox(this);
    octave1->setRange(1, 5);
    octave1->setValue(4);
    octave1->setFocusPolicy(Qt::NoFocus);
    octave2 = new QSpinBox(this);
    octave2->setRange(2, 6);
    octave2->setValue(5);
    octave2->setFocusPolicy(Qt::NoFocus);
    instruments = new QComboBox(this);
    instruments->addItem("Grand Piano");
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(kits);
    hbox->addWidget(kitName);
    hbox->addWidget(recorder);
    hbox->addWidget(player);
    hbox->addWidget(looper);
    hbox->addWidget(instruments);
    hbox->addWidget(octave1);
    hbox->addWidget(octave2);
    setLayout(hbox);
}

void ControlPanel::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ControlPanel::setKitName(QString text){
    kitName->setText(text);
}

QString ControlPanel::getKit(){
    return kits->currentText();
}

QComboBox *ControlPanel::getKits(){
    return kits;
}

QSpinBox *ControlPanel::getOctave1(){
    return octave1;
}

QSpinBox *ControlPanel::getOctave2(){
    return octave2;
}

ControlPanel::~ControlPanel(){
    delete kits;
    delete kitName;
    delete recorder;
    delete player;
    delete looper;
    delete octave1;
    delete octave2;
    delete instruments;
}
