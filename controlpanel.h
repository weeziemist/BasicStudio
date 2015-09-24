#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setKitName(QString text);
    QString getKit();
    QComboBox *getKits();
    QSpinBox *getOctave1();
    QSpinBox *getOctave2();
    ~ControlPanel();

private:
    QComboBox *kits;
    QLabel *kitName;
    QPushButton *recorder;
    QPushButton *player;
    QPushButton *looper;
    QSpinBox *octave1;
    QSpinBox *octave2;
    QComboBox *instruments;
    
signals:
    
public slots:
    
};

#endif // CONTROLPANEL_H
