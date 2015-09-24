#include "drumset.h"
#include <QVBoxLayout>
#include <QDebug>

DrumSet::DrumSet(DrumBar *list[], size_t length, QWidget *parent) :
    QWidget(parent)
{
    vbox = new QVBoxLayout();
    vbox->setSpacing(0);
    size = length;
    bars = new DrumBar*[10];
    copyList(list);
    setLayout(vbox);
}

void DrumSet::copyList(DrumBar *list[]){
    for(unsigned i = 0; i < size; i++){
        bars[i] = list[i];
        bars[i]->setParent(this);
        vbox->addWidget(bars[i]);
    }
}

void DrumSet::setBar(QString fileName, int index){
    bars[index]->setFile(fileName);
}

void DrumSet::setBarVisible(QString fileName, int index){
    bars[index]->setVisible(true);
    bars[index]->setFile(fileName);
    size++;
}

void DrumSet::setNewBar(QString fileName, QString key, int index){
    bars[index] = new DrumBar(fileName, key, this);
    vbox->addWidget(bars[index]);
    size++;
}

DrumBar *DrumSet::getBar(int index){
    return bars[index];
}

size_t DrumSet::getSize(){
    return size;
}

void DrumSet::remove(int index){
    bars[index]->setVisible(false);
    size--;
}

DrumSet::~DrumSet(){
    delete[] bars;
    delete vbox;
}
