#include "drumbar.h"
#include <QHBoxLayout>
#include <QStyleOption>
#include <QFileInfo>
#include <QPainter>
#include <QFileDialog>

DrumBar::DrumBar(QString fileName, QString key, QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("DrumBar {border-image: url(:/new/prefix1/loopbar.jpg);}");
    type = key;
    fileOpen = new QPushButton(this);
    fileOpen->setIcon(QIcon(":/new/prefix1/folder.jpg"));
    player = new QPushButton(type, this);
    volume = new QSlider(Qt::Horizontal, this);
    volume->setRange(0, 1);
    volume->setSliderPosition(1);
    QLabel *volumeUp = new QLabel(this);
    volumeUp->setStyleSheet("image: url(:/new/prefix1/volumeup.png)");
    name = new QLabel(QFileInfo(fileName).baseName(), this);
    name->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sound = new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(fileName));
    sound->setVolume(1);
    shortcut = new QShortcut(type, this);
    connect(fileOpen, SIGNAL(clicked()), this, SLOT(openDialog()));
    connect(volume, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));
    connect(shortcut, SIGNAL(activated()), this, SLOT(click()));
    connect(player, SIGNAL(clicked()), this, SLOT(play()));
    QHBoxLayout *hbox1 = new QHBoxLayout();
    hbox1->addWidget(fileOpen);
    hbox1->addWidget(name);
    QHBoxLayout *hbox2 = new QHBoxLayout();
    hbox2->addWidget(player, 0);
    hbox2->addWidget(volume, 3);
    hbox2->addWidget(volumeUp, 1);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    setLayout(vbox);
}

void DrumBar::setVolume(int){
    sound->setVolume(volume->sliderPosition());
}

void DrumBar::openDialog(){
    setFile(QFileDialog::getOpenFileName(this, "Select Drum File"));
}

void DrumBar::click(){
    emit player->clicked();
}

void DrumBar::play(){
    sound->play();
}

void DrumBar::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void DrumBar::setFile(QString fileName){
    name->setText(QFileInfo(fileName).baseName());
    sound->setSource(QUrl::fromLocalFile(fileName));
}

QString DrumBar::getName(){
    return name->text();
}

DrumBar::~DrumBar(){
    delete name;
    delete fileOpen;
    delete volume;
    delete player;
    delete sound;
    delete shortcut;
}
