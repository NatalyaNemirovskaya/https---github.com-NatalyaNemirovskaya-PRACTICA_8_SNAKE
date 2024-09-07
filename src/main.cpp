#include "Game_snake.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game_snake game;  

    game.show();

    return app.exec();
}