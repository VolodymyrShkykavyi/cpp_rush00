#ifndef BULLET_HPP
#define BULLET_HPP

#include "MovableObject.hpp"

class Bullet: public MovableObject
{
private:
    Bullet();
    int _visible;
	~Bullet();
    Bullet(Bullet const &src);
    Bullet & operator=(Bullet const &rhs);
public:
    Bullet(int y, int x, int direction, WINDOW *win);
    int getVisIble();
    void    setVisible(int val);
    void    move();
    void    draw();
};

#endif