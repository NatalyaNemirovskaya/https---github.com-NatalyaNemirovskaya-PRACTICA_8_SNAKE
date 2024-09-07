#include "Game_snake.h"
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QTime>
#include <QPalette>
#include <QMessageBox>
#include <QPainter>


void Game_snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if (key == Qt::Key_Left && dir != Directions::right) {dir = Directions::left;}
    if (key == Qt::Key_Right && dir != Directions::left) {dir = Directions::right;}
    if (key == Qt::Key_Up && dir != Directions::down) {dir = Directions::up;}
    if (key == Qt::Key_Down && dir != Directions::up) {dir = Directions::down;}
}

void Game_snake::timerEvent(QTimerEvent *e)
{
     Q_UNUSED(e);
    if (in_game)
    {
        check_apple();
        move();
        checkCollision();
    }

    this->repaint();
}

void Game_snake::paintEvent(QPaintEvent* e)
 {
    Q_UNUSED(e);
    doDrawing();
 }


Game_snake::Game_snake(QWidget *parent)
:QWidget(parent)
{
    this->resize(FIELD_WIDHT * N_WIDHT, FIELD_HIGHT * N_HIGHT); // установка размера игрового поля
    this->setWindowTitle("SNAKE");
    QPalette pal1;
    pal1.setColor(this->backgroundRole(), Qt::black);
    this->setPalette(pal1);    

    this->game_init();

    
}

void Game_snake::game_init()
{
    dir = right; //двигаемся вправо
    in_game = true;               // в игре
   
    head.set_x(3);                // голова змейки
    head.set_y(0);
    dots.resize(2);             // начальный размер змейки
    for (int i = 0; i < 2; i++) // установка начального положения змейки

    {
        dots[i].set_x(i + 1);
        dots[i].set_y(0);
        
    }

    loadImages(); //  появление яблока
    
    timer_ID = startTimer(DELAY); //запуск таймера  

    
}

void Game_snake::move() //
{
    int j = 0;

    for (int i = dots.size() - 1; i > 0; i--)
    {
        dots[i] = dots[i - 1];
    }

    dots[0] = head;

    switch (dir)
    {
    case left:
        j = head.get_x() - 1;
        head.set_x(j);
        break;

    case right:
        j = head.get_x() + 1;
        head.set_x(j);
        break;

    case up:
        j = head.get_y() - 1;
        head.set_y(j);
        break;

    case down:
        j = head.get_y() + 1;
        head.set_y(j);
        break;

    default:
        break;
    }
}

void Game_snake::doDrawing()      // прорисовка
{
    QPainter qp(this); // класс на котором прорисовка
    if (Game_snake::in_game)
    {
        qp.setBrush(Qt::red);
        qp.drawEllipse(apple.get_x() * FIELD_WIDHT, apple.get_y() * FIELD_HIGHT, FIELD_WIDHT, FIELD_HIGHT);

        qp.setBrush(Qt::white);
        qp.drawEllipse(head.get_x() * FIELD_WIDHT, head.get_y() * FIELD_HIGHT, FIELD_WIDHT, FIELD_HIGHT);

        for (int i = 0; i < dots.size(); i++)

        {
            qp.setBrush(Qt::green);
            qp.drawEllipse(dots[i].get_x() * FIELD_WIDHT, dots[i].get_y() * FIELD_HIGHT, FIELD_WIDHT, FIELD_HIGHT);
        }
    }
    else
    {
         game_over();
    }
}

void Game_snake::checkCollision()     // проверка не столкнулась ли змейка
{
  if (dots.size() > 3)  // проверка столкновения с собой
    {
        for (int i = 0; i < dots.size(); i++)
        {
            if (head == dots[i])
            {
                in_game = false;
            }
        }
    }
    
    //проверки выхода за границы поля
    if (head.get_x() >= N_WIDHT| head.get_x() < 0)
    {
        in_game = false;
    } 

    if (head.get_y() >= N_WIDHT| head.get_y() < 0)
    {
        in_game = false;
    } 
   

    if (!in_game) //не в игре
    {      
        killTimer(timer_ID);      // jcnfyjdrf nfqvthf 
    }
} 

void Game_snake::loadImages()      // рандомная позиция яблока
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    apple.set_xy(qrand() % N_WIDHT, qrand() % N_HIGHT);
}

void Game_snake::check_apple() // если змейка съела яблока, вектор увеличивается
{
     if (apple ==head)
    {
        dots.push_back(Paint(0,0));
        loadImages() ;
    }
}

void Game_snake::game_over() // игра закончилась
{
    QMessageBox msgb;   //сообщение об окончании игры
    msgb.setText("GAME OVER");
    msgb.exec();
    game_init();  // запуск с начала
}
