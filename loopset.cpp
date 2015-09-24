#include "loopset.h"
#include <QVBoxLayout>

LoopSet::LoopSet(QWidget *parent) :
    QWidget(parent)
{
    bars = new LoopBar*[16];
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setSpacing(0);
    for(int i = 0; i < 16; i++){
        bars[i] = new LoopBar("No file loaded", this);
        vbox->addWidget(bars[i]);
    }
    setLayout(vbox);
}

LoopSet::~LoopSet(){
    delete[] bars;
}
