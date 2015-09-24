#include "spot.h"

Spot::Spot(QWidget *parent) :
    QPushButton(parent)
{
    setStyleSheet("background-image: url(:/new/prefix1/spot.png); min-height: 25; min-width: 25");
    autoFillBackground();
    setFlat(true);
}

Spot::~Spot(){
}
