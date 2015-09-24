#ifndef LOOPBAR_H
#define LOOPBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include "spot.h"

class LoopBar : public QWidget
{
    Q_OBJECT
public:
    explicit LoopBar(QString fileName, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setName(QString text);
    ~LoopBar();

private:
    QPushButton *fileOpen;
    QLabel *name;
    QSlider *volume;
    Spot **spots;
    
signals:
    
public slots:
    
};

#endif // LOOPBAR_H
