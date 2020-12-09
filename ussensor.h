#ifndef USSENSOR_H
#define USSENSOR_H

#include <string>

enum typeSensor{
    HC_SR04,
};

class USSensor
{
    float value; // текущее показание датчика
    typeSensor type = HC_SR04; // тип датчика (могут стоять разные датчики)
    std::string sensorID; // имя датчика, лучше через стринг, чтобы не запутаться

    unsigned int rangeMax; //макс. дальность датчика, мм
    unsigned int rangeMin; //мин дальность датчика, мм

    unsigned int angleRange; // ширина диаграммы ннаправленности датчика, град.

    bool isON = false;
    bool isInicialised = false;

    int positionX;
    int positionY;
    int facinngRAD; // в радианах!!11

    unsigned int sensorUsIndication = 0;

public:
    USSensor();

    float getValue() const;

    typeSensor getType() const;
    void setType(const typeSensor &value);

    std::string getSensorID() const;
    void setSensorID(const std::string &value);

    unsigned int getRangeMax() const;
    void setRangeMax(unsigned int value);

    unsigned int getRangeMin() const;
    void setRangeMin(unsigned int value);

    unsigned int getAngleRange() const;
    void setAngleRange(unsigned int value);

    bool getIsON() const;
    void setIsON(bool value);

    void inicialise(int _x, int _y, int _fr);

    int getX() const;
    int getY() const;
    int getFRad() const;

    bool getIsInicialised() const;
    void setIsInicialised(bool value);

    int getRange();
    void updateRange(unsigned int value);
};

#endif // USSENSOR_H
