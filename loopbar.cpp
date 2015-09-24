#include "loopbar.h"
#include <QPainter>
#include <QStyleOption>
#include <QVBoxLayout>

LoopBar::LoopBar(QString fileName, QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("LoopBar {border-image: url(:/new/prefix1/loopbar.jpg);}");
    fileOpen = new QPushButton(this);
    fileOpen->setIcon(QIcon(":/new/prefix1/folder.jpg"));
    name = new QLabel(fileName, this);
    volume = new QSlider(Qt::Horizontal, this);
    QLabel *volumeUp = new QLabel(this);
    volumeUp->setStyleSheet("image: url(:/new/prefix1/volumeup.png)");
    spots = new Spot*[16];
    QHBoxLayout *hbox1 = new QHBoxLayout();
    hbox1->addWidget(fileOpen);
    hbox1->addWidget(name, 3);
    QHBoxLayout *hbox2 = new QHBoxLayout();
    hbox2->addWidget(volume, 4);
    hbox2->addWidget(volumeUp, 1);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    QHBoxLayout *hbox3 = new QHBoxLayout();
    hbox3->addLayout(vbox);
    hbox3->setSpacing(0);
    for(int i = 0; i < 16; i++){
        spots[i] = new Spot(this);
        spots[i]->setEnabled(false);
        hbox3->addWidget(spots[i]);
    }
    setLayout(hbox3);
}

void LoopBar::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void LoopBar::setName(QString text){
    name->setText(text);
}

LoopBar::~LoopBar(){
    delete name;
    delete fileOpen;
    delete[] spots;
}
