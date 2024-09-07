#pragma once

#include <QWidget>
#include <QVector>
#include "Paint.h"

class Game_snake : public QWidget
{
protected:
    void keyPressEvent(QKeyEvent *e) override;; //нажатие клавиши
    void timerEvent(QTimerEvent *e) override;;  //сработал таймер
    void paintEvent(QPaintEvent*) override; // слот для отрисовки

   

  
private:

    Paint  head;
    Paint apple;  //яблоко
    QVector<Paint> dots; //змейка

    const int FIELD_WIDHT = 20; // ширина ячейки
    const int FIELD_HIGHT = 20; // длина ячейки
    const int N_WIDHT = 30;     // количество ячеек по горизонтали
    const int N_HIGHT = 30;     // количество ячеек по вертикали

    bool in_game = true; // флаг нахождения в игре
    

    static const int DELAY = 200; // интервал времени для прорисовки

     enum Directions{   //направление движения
        left, right, up, down
    };

    Directions dir;

    int timer_ID; //таймер

    void game_init(); // инициализация

    void move(); // движение змейки

    void checkCollision(); // проверка на коллизию    

    void loadImages(); // прорисовка яблока 

    void check_apple(); // проверка достигла ли змейка яблока
   
    void game_over(); //oокончание игры  
    
    void doDrawing();  // перерисовка

public:

    Game_snake(QWidget *parent = 0); // конструктор

    
};