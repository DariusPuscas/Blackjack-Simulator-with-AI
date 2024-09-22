#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <utility>
#include "blackjack.h"
#include "FinalWindow.h"


class GUI:public QWidget{
private:

    string difficulty;

    AI ai;
    DeckManager deckManager{ai};

    std::vector<Card> playerHand;
    std::vector<Card> aiHand;
    std::vector<Card> deck;

    QPushButton* btn_hit = new QPushButton{"HIT"};
    QPushButton* btn_stand = new QPushButton{"Stand"};

   // QLabel* lbl_player_cards = new QLabel{"1"};
  //  QLabel* lbl_ai_cards = new QLabel{"1"};
    QLabel* lbl_player_score = new QLabel{"2"};
    QLabel* lbl_ai_score = new QLabel{"2"};

    QHBoxLayout* ly_ai{};
    QHBoxLayout* ly_player{};

    std::vector<QLabel*> labels_player;
    std::vector<QLabel*> labels_ai;

    QString handToString(const std::vector<Card>& hand);
    void init();
    void connect_signal();
    void updateUI();

    void animateCard(QLabel* cardLabel);

    QString get_card_image(const Card& card);
    void updateHandImages(const std::vector<Card>& hand, QLayout* layout);

public:
    explicit GUI(string difficulty):difficulty{std::move(difficulty)}{
        init();
        updateUI();
        connect_signal();
    }
};