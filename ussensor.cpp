#include "ussensor.h"

float USSensor::getValue() const
{
    return value;
}

typeSensor USSensor::getType() const
{
    return type;
}

void USSensor::setType(const typeSensor &value)
{
    type = value;
}

std::string USSensor::getSensorID() const
{
    return sensorID;
}

void USSensor::setSensorID(const std::string &value)
{
    sensorID = value;
}

unsigned int USSensor::getRangeMax() const
{
    return rangeMax;
}

void USSensor::setRangeMax(unsigned int value)
{
    rangeMax = value;
}

unsigned int USSensor::getRangeMin() const
{
    return rangeMin;
}

void USSensor::setRangeMin(unsigned int value)
{
    rangeMin = value;
}

unsigned int USSensor::getAngleRange() const
{
    return angleRange;
}

void USSensor::setAngleRange(unsigned int value)
{
    angleRange = value;
}

bool USSensor::getIsON() const
{
    return isON;
}

void USSensor::setIsON(bool value)
{
    isON = value;
}

void USSensor::inicialise(int _x, int _y, int _fr)
{
    positionX = _x;
    positionY = _y;
    facinngRAD = _fr;
    setIsInicialised(true);
}

int USSensor::getX() const
{
    return positionX;
}
int USSensor::getY() const
{
    return positionY;
}
int USSensor::getFRad() const
{
    return facinngRAD;
}

bool USSensor::getIsInicialised() const
{
    return isInicialised;
}

void USSensor::setIsInicialised(bool value)
{
    isInicialised = value;
}

int  USSensor::getRange()
{
    return sensorUsIndication;
}

void USSensor::updateRange(unsigned int value)
{
    if ((rangeMin <= value) && (value <= rangeMax))
    {
        sensorUsIndication = 0;
    }
    else
    {
        sensorUsIndication = value;
    }
}

USSensor::USSensor()
{

}
