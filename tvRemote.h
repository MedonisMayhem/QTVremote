#ifndef QTVREMOTE_TVREMOTE_H
#define QTVREMOTE_TVREMOTE_H

#include <QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QTime>
#include "./ui_tvRemote.h"

class TVRemote : public QMainWindow
{
    Q_OBJECT
public:
    QProgressBar *progressBar = nullptr;
    QSpinBox *spinBox = nullptr;
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
        if(spinBox->maximum() == spinBox->value())
        {
            spinBox->setValue(spinBox->minimum());
        }
        else
        {
            spinBox->setValue(spinBox->value() + 1);
        }
    }

    void downToChannel(){
        if(spinBox->minimum() == spinBox->value())
        {
            spinBox->setValue(spinBox->maximum());
        }
        else
        {
            spinBox->setValue(spinBox->value() - 1);
        }

    }

    //functions of increasing the progressBar by 10%
    void upToVolume(){progressBar->setValue(progressBar->value() + 10);}
    void downToVolume(){progressBar->setValue(progressBar->value() - 10);}
signals:

private:

    QString channelPTR;
    bool timeOut = false;

    //inputChannel creates a delay of two seconds for entering the second number
    void inputChennel()
    {
        timeOut = true;
        QTime time = QTime::currentTime().addSecs(2);
        while(QTime::currentTime() < time && channelPTR.size() < 2)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        spinBox->setValue(channelPTR.toInt());
        channelPTR = nullptr;
        timeOut = false;
    }

};
#endif //QTVREMOTE_TVREMOTE_H
