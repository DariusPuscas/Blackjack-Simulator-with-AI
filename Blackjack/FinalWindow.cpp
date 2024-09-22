#include "FinalWindow.h"

void FinalWindow::init() {

    setStyleSheet("background-color: #1C1C1C;");

    auto ly_main = new QVBoxLayout;
    setLayout(ly_main);

    QString continueStyle = R"(
        QPushButton {
            background-color: #28A745; /* green */
            color: white;
            border-radius: 10px;
            padding: 10px;
            font-size: 16px;
            border: 2px solid #218838;
        }
        QPushButton:hover {
            background-color: #218838;
        }
        QPushButton:pressed {
            background-color: #1E7E34;
        }
    )";


    QString restartStyle = R"(
        QPushButton {
            background-color: #FFC107; /* yellow */
            color: black;
            border-radius: 10px;
            padding: 10px;
            font-size: 16px;
            border: 2px solid #E0A800;
        }
        QPushButton:hover {
            background-color: #E0A800;
        }
        QPushButton:pressed {
            background-color: #C69500;
        }
    )";

    QString quitStyle = R"(
        QPushButton {
            background-color: #DC3545; /* red */
            color: white;
            border-radius: 10px;
            padding: 10px;
            font-size: 16px;
            border: 2px solid #C82333;
        }
        QPushButton:hover {
            background-color: #C82333;
        }
        QPushButton:pressed {
            background-color: #BD2130;
        }
    )";

    btn_continue->setStyleSheet(continueStyle);
    btn_restart->setStyleSheet(restartStyle);
    btn_quit->setStyleSheet(quitStyle);

    auto ly_btn = new QHBoxLayout;
    ly_btn->addWidget(btn_continue);
    ly_btn->addWidget(btn_restart);
    ly_btn->addWidget(btn_quit);

    QString lblStyle = R"(
        QLabel {
            color: #DAF7A6;
            font-size: 20px;
            font-weight: bold;
            background-color: #1C1C1C;
            padding: 10px;
            border-radius: 10px;
        }
    )";

    lbl_message->setStyleSheet(lblStyle);
    lbl_informative_text->setStyleSheet(lblStyle);

    lbl_message->setText(message);
    lbl_informative_text->setText(informative_text);

    ly_main->addWidget(lbl_message);
    ly_main->addWidget(lbl_informative_text);
    ly_main->addLayout(ly_btn);

}

void FinalWindow::connect_signal() {
    QObject::connect(btn_quit,&QPushButton::clicked,[this](){
        this->close();

    });
    QObject::connect(btn_restart,&QPushButton::clicked,[&](){
        auto startWindow = new StartWindow{};
        startWindow->show();
        this->close();
    });
    QObject::connect(btn_continue,&QPushButton::clicked,[&](){
        auto gui = new GUI{"Medium"};
        gui->show();
        this->close();
    });
}

