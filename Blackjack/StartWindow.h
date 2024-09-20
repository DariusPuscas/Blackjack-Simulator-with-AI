#pragma once

#include "gui.h"
#include <QComboBox>

class StartWindow:public QWidget{
private:
    QComboBox* combo;
    QPushButton* btn_start = new QPushButton{"START"};
    QLabel* lbl = new QLabel{"Blackjack vs. AI"};

    void init_start();
    void connect_signal();
public:
    StartWindow(){
        init_start();
        connect_signal();
    }

};