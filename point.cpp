#include "point.h"

int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    x = value;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    y = value;
}

bool Point::getIsRemove() const
{
    return isRemove;
}

void Point::setCoord(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setIsRemove(bool value)
{
    isRemove = value;
}

bool Point::getIsObstacle() const
{
    return isObstacle;
}

void Point::setIsObstacle(bool value)
{
    isObstacle = value;
}

unsigned int Point::getLevelTrust() const
{
    return levelTrust;
}

void Point::setLevelTrust(unsigned int value)
{
    levelTrust = value;
}

Point::Point()
{

}

Point::Point(int x, int y)
    : x(x), y(y)
{

}
