#ifndef POINT_H
#define POINT_H


class Point
{
    // Координаты точки
    int x = 0;
    int y = 0;

    bool isRemove = false; // Пометка на удаление
    unsigned int levelTrust = 0; // Уровень доверия, 0 - наивысший

    bool isObstacle = true; // true - Препятствие, false - Пустая точка
    static unsigned int pointCounter; // Кол-во точек

public:
    Point();
    Point(int x, int y);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    void setCoord(int x, int y);

    bool getIsRemove() const;
    void setIsRemove(bool value);

    bool getIsObstacle() const;
    void setIsObstacle(bool value);

    unsigned int getLevelTrust() const;
    void setLevelTrust(unsigned int value);
};

#endif // POINT_H
