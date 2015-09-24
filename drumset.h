#ifndef DRUMSET_H
#define DRUMSET_H

#include <QWidget>
#include <QVBoxLayout>
#include "drumbar.h"

class DrumSet : public QWidget
{
    Q_OBJECT
public:
    explicit DrumSet(DrumBar *list[], size_t length, QWidget *parent = 0);
    void copyList(DrumBar *list[]);
    void setBar(QString fileName, int index);
    void setBarVisible(QString fileName, int index);
    void setNewBar(QString fileName, QString key, int index);
    DrumBar *getBar(int index);
    size_t getSize();
    void remove(int index);
    ~DrumSet();

private:
    DrumBar **bars;
    QVBoxLayout *vbox;
    size_t size;
    
signals:
    
public slots:
    
};

#endif // DRUMSET_H
