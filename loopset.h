#ifndef LOOPSET_H
#define LOOPSET_H

#include <QWidget>
#include "loopbar.h"

class LoopSet : public QWidget
{
    Q_OBJECT
public:
    explicit LoopSet(QWidget *parent = 0);
    ~LoopSet();

private:
    LoopBar **bars;

signals:
    
public slots:
    
};

#endif // LOOPSET_H
