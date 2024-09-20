#include "StartWindow.h"

void StartWindow::init_start() {

        auto background = new QLabel(this);
        background->setPixmap(QPixmap(R"(D:\OOP\Blackjack\cards\casino2.png)"));
        background->setGeometry(0, 0, this->width(), this->height());
        background->setScaledContents(true); // auto dimension
        background->lower();


        lbl->setStyleSheet("QLabel {"
                             "color: black;"
                             "font-size: 28px;"
                             "font-weight: bold;"
                             "text-align: center;"
                             "font-family: 'Verdana';"
                             "}");

        btn_start->setStyleSheet("QPushButton {"
                                 "background-color: #4CAF50;"
                                 "color: white;"
                                 "border: 2px solid #4CAF50;"
                                 "border-radius: 10px;"
                                 "font-size: 16px;"
                                 "padding: 10px 20px;"
                                 "}"
                                 "QPushButton:hover {"
                                 "background-color: #45a049;"
                                 "}");

        combo= new QComboBox;

        combo->setStyleSheet("QComboBox {"
                             "  background-color: #ffffff;"   // white background
                             "  border: 2px solid #555555;"   // grey border
                             "  border-radius: 5px;"
                             "  padding: 5px 10px;"
                             "  font-size: 14px;"
                             "  color: #333;"
                             "}"


                             "QComboBox QAbstractItemView {"
                             "  background-color: #f2f2f2;"   // background list
                             "  border: 1px solid #555555;"
                             "  selection-background-color: #45a049;"
                             "  selection-color: white;"     // text color when selected
                             "}"


                             "QComboBox::drop-down {"
                             "  border: none;"
                             "}"
                             "QComboBox::down-arrow {"
                             "  width: 0;"
                             "  height: 0;"
                             "  border-left: 5px solid none;"
                             "  border-right: 5px solid none;"
                             "  border-top: 7px solid #333;"
                             "  margin-right: 10px;"
                             "}");

    auto difficultyLabel = new QLabel("Choose Difficulty:");
    difficultyLabel->setStyleSheet("QLabel {"
                                   "  color: #333;"  // text
                                   "  font-size: 14px;"
                                   "  padding-right: 10px;"
                                   "}");

        combo->addItem("Easy");
        combo->addItem("Medium");
        combo->addItem("Hard");

        auto ly_start = new QVBoxLayout;
        setLayout(ly_start);
        ly_start->addWidget(lbl);

        auto ly_sec = new QHBoxLayout;
        ly_sec->addWidget(difficultyLabel);
        ly_sec->addWidget(combo);
        ly_sec->addWidget(btn_start);

        ly_start->addLayout(ly_sec);
}

void StartWindow::connect_signal() {
        QObject::connect(btn_start,&QPushButton::clicked,[this](){
            string choice = combo->currentText().toStdString();
            this->close();
            GUI* gui = new GUI{choice};
            gui->show();
        });
}
