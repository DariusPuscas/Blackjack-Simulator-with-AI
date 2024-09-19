//
// Created by User on 9/17/2024.
//

#include "gui.h"

void GUI::init() {

    //this->setStyleSheet("QWidget { background-color: #ffd700; }");
    //btn_hit->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; padding: 15px; border-radius: 10px; font-size: 18px; }");
    //btn_stand->setStyleSheet("QPushButton { background-color: #F44336; color: white; padding: 15px; border-radius: 10px; font-size: 18px; }");

   // lbl_player_score->setStyleSheet("QLabel { font-size: 20px; color: black; }");
   // lbl_ai_score->setStyleSheet("QLabel { font-size: 20px; color: black; }");

    deck = deckManager.create_deck();
    aiHand.push_back(deck.back());
    deck.pop_back();

    playerHand.push_back(deck.back());
    deck.pop_back();

    auto label = new QLabel;
    auto image_Path = get_card_image(playerHand[0]);
    QPixmap pix(image_Path);
    label->setPixmap(pix.scaled(80,120));

    auto lbl1 = new QLabel;
    auto image_path = get_card_image(aiHand[0]);
    QPixmap pixmap(image_path);
    lbl1->setPixmap(pixmap.scaled(80,120));

    auto lbl2 = new QLabel;
    auto image_path2 = R"(D:\OOP\Blackjack\cards\back.png.png)";
    QPixmap qPixmap(image_path2);
    lbl2->setPixmap(qPixmap.scaled(80,120));

    labels_ai.push_back(lbl1);
    labels_ai.push_back(lbl2);


    auto ly_main = new QVBoxLayout;
    setLayout(ly_main);

    ly_ai = new QHBoxLayout;
    ly_ai->addWidget(lbl_ai_score);
    for(auto l : labels_ai)
        ly_ai->addWidget(l);
    //ly_ai->addWidget(lbl_ai_cards);
    labels_ai.pop_back();

    ly_player = new QHBoxLayout;
   // ly_player->addWidget(lbl_player_cards);
    ly_player->addWidget(lbl_player_score);

    labels_player.push_back(label);
    ly_player->addWidget(label);

    auto ly_btn = new QHBoxLayout;
    ly_btn->addWidget(btn_hit);
    ly_btn->addWidget(btn_stand);

    ly_main->addLayout(ly_ai);
    ly_main->addLayout(ly_player);
    ly_main->addLayout(ly_btn);


   /* QLabel* cardLabel = new QLabel;
    QString imagePath = R"(D:\OOP\Blackjack\cards\2_clubs.png.png)";
    QPixmap pixmap(imagePath);
    cardLabel->setPixmap(pixmap.scaled(80, 120));
    ly_ai->addWidget(cardLabel); */
}

void GUI::connect_signal() {
    QObject::connect(btn_hit,&QPushButton::clicked,[this](){
        auto lbl = new QLabel;
        auto image_path = get_card_image(deck.back());
        QPixmap pixmap(image_path);
        lbl->setPixmap(pixmap.scaled(80,120));

        labels_player.push_back(lbl);
        playerHand.push_back(deck.back());
        deck.pop_back();

        int playerTotal = ai.calculateHandTotal(playerHand);
        if (playerTotal > 21) {
            // if player loses update ui
            updateUI();
            auto msg = new QMessageBox;
            msg->setText("You lost");
            msg->show();
        } else {
            //continue
            updateUI();
        }
    });
    QObject::connect(btn_stand,&QPushButton::clicked,[this](){
        while (ai.aiDecide(aiHand,ai.calculateHandTotal(playerHand))) {
            auto lbl = new QLabel;
            auto image_path = get_card_image(deck.back());
            QPixmap pixmap(image_path);
            lbl->setPixmap(pixmap.scaled(80,120));
            labels_ai.push_back(lbl);
            updateUI();
            aiHand.push_back(deck.back());
            deck.pop_back();
        }

        updateUI();
        // Compare results
        int playerTotal =ai.calculateHandTotal(playerHand);
        int aiTotal = ai.calculateHandTotal(aiHand);

        if (aiTotal > 21 || playerTotal > aiTotal) {
            auto msg = new QMessageBox;
            msg->setText("You won");
            msg->show();
        } else if (playerTotal < aiTotal) {
            auto msg = new QMessageBox;
            msg->setText("AI won");
            msg->show();
        } else {
            auto msg = new QMessageBox;
            msg->setText("Draw");
            msg->show();
        }



    });
}

void GUI::updateUI() {

    ly_player->addWidget(labels_player.back());
    ly_ai->addWidget(labels_ai.back());
   // lbl_player_cards->setText(handToString(playerHand));
   // lbl_ai_cards->setText(handToString(aiHand));

    // print results
    lbl_player_score->setText("Your score: "+QString::number(ai.calculateHandTotal(playerHand)));
    lbl_ai_score->setText("AI score: "+QString::number(ai.calculateHandTotal(aiHand)));
}

QString GUI::handToString(const std::vector<Card> &hand) {
    QString handString;
    for (const Card& card : hand) {
        handString += card.getSymbol().c_str();
        handString += card.get_suit();
        handString += " ";
    }
    return handString;
}

QString GUI::get_card_image(const Card& card) {
    QString value;
    if (card.get_value() == 1) value = "ace";
    else if (card.get_value()== 11) value = "jack";
    else if (card.get_value() == 12) value = "queen";
    else if (card.get_value() == 13) value = "king";
    else value = QString::number(card.get_value());

    QString suit;
    if (card.get_suit() == "spades") suit = "spades";
    else if (card.get_suit() == "clubs") suit = "clubs";
    else if (card.get_suit() == "hearts") suit = "hearts";
    else if (card.get_suit() == "diamonds") suit = "diamonds";

    QString path = "D:\\OOP\\Blackjack\\cards\\";

    return path + value + "_" + suit + ".png.png";
}

void GUI::updateHandImages(const std::vector<Card>& hand, QLayout *layout) {

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (const Card& card : hand) {
        QLabel* cardLabel = new QLabel();
        QString imagePath = "D:\\OOP\\Blackjack\\cards\\" + get_card_image(card);  // path
        QPixmap pixmap(imagePath);
        cardLabel->setPixmap(pixmap.scaled(80, 120));  // adjust size
        layout->addWidget(cardLabel);
    }

}
