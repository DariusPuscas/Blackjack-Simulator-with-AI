#include <QApplication>
#include "gui.h"
#include "StartWindow.h"
#include "FinalWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
   // AI ai{};
  //  DeckManager deckManager{ai};
 //   a.setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 10px; }"
 //                   "QLabel { font-family: Arial; font-size: 16px; color: #2c3e50; }"
  //                  "QMainWindow { background-color: #ecf0f1; }");
 //   GUI gui{};
   // gui.show();
   StartWindow window{};
   window.show();
   // deckManager.playGame(); // test game

    return QApplication::exec();
}
