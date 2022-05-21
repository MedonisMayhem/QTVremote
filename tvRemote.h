#ifndef QTVREMOTE_TVREMOTE_H
#define QTVREMOTE_TVREMOTE_H

#include <QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>
#include <QTime>
#include "./ui_tvRemote.h"
#include <iostream>

class TVRemote : public QMainWindow
{
    Q_OBJECT
public:
    QProgressBar *progressBar = nullptr;
    QLabel *label = nullptr;
    TVRemote (QWidget *parent) : QMainWindow(parent){}
public slots:
    //channel input buttons
    //if the inputChannel function is active it cannot be called again
    void add0(){ channelPTR += "0";if(!timeOut)inputChennel();};
    void add1(){ channelPTR += "1";if(!timeOut)inputChennel();};
    void add2(){ channelPTR += "2";if(!timeOut)inputChennel();};
    void add3(){ channelPTR += "3";if(!timeOut)inputChennel();};
    void add4(){ channelPTR += "4";if(!timeOut)inputChennel();};
    void add5(){ channelPTR += "5";if(!timeOut)inputChennel();};
    void add6(){ channelPTR += "6";if(!timeOut)inputChennel();};
    void add7(){ channelPTR += "7";if(!timeOut)inputChennel();};
    void add8(){ channelPTR += "8";if(!timeOut)inputChennel();};
    void add9(){ channelPTR += "9";if(!timeOut)inputChennel();};

    //channel switching functions by one position
    void upToChannel(){
        int channelTemp = label->text().toInt();
        if(channelTemp == channelMax)
        {
            label->setText(QString::number(channelMin));
        }
        else
        {
            label->setText(QString::number(channelTemp + 1));
        }
    }

    void downToChannel(){
        int channelTemp = label->text().toInt();
        if(channelTemp  == channelMin)
        {
            label->setText(QString::number(channelMax));
        }
        else
        {
            label->setText(QString::number(channelTemp - 1));
        }

    }

    //functions of increasing the progressBar by 10%
    void upToVolume(){ progressBar->setValue(progressBar->value() + 10);}
    void downToVolume(){ progressBar->setValue(progressBar->value() - 10);}
signals:

private:

    QString channelPTR;
    bool timeOut = false;
    int channelMin = 0;
    int channelMax = 99;

    //inputChannel creates a delay of one seconds for entering the second number
    void inputChennel()
    {
        timeOut = true;
        QTime time = QTime::currentTime().addMSecs(500);
        while(QTime::currentTime() < time && channelPTR.size() < 2)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        label->setText(channelPTR);
        channelPTR = nullptr;
        timeOut = false;
    }

};
#endif //QTVREMOTE_TVREMOTE_H
