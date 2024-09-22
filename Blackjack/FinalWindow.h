#pragma once

#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <utility>
#include "StartWindow.h"

class FinalWindow:public QWidget{
private:
    QString message;
    QString informative_text;

    QPushButton* btn_restart = new QPushButton("Restart");
    QPushButton* btn_continue = new QPushButton("Continue");
    QPushButton* btn_quit = new QPushButton("Quit");

    QLabel* lbl_message = new QLabel;
    QLabel* lbl_informative_text = new QLabel;

    void init();
    void connect_signal();
public:
     FinalWindow(QString message, QString informative_text):message{std::move(message)},informative_text{std::move(informative_text)}{
        init();
        connect_signal();
    }
};