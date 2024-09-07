#pragma once

class Paint
{

private:
    int x;
    int y;

public:
    Paint();
    Paint(int , int );
    ~Paint();
    void set_x(int _x);
    void set_y(int _y);
    int get_x()  const;
    int get_y() const;
    void set_xy(int _x, int _y);
    friend  bool operator==(const Paint& a, const Paint &b);

};
