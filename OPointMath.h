#include <map>
#include <vector>
#include <cmath>
#define PI 3.14159265
#include "point.h"
#include "Vector2.h"
#include "ussensor.h"
using namespace std;



class OPointMath
{
	map <Vector2, Point> pointsMap;// карта точек.
	map <Vector2, USSensor> sensorsMap; //карта ультразвуковых датчиков

	int exclusionRadius; // радиус, в котором точки не ставятся
	int pointNumber  = 5; //

	static int f2i(float f) //переводитм в инт округлением в БОЛЬШУЮ сторону
	{
		int i;
		f = ceil(f);
		i = (int) f;
		return i;
	}

	static float i2f(int i)
	{
		float f = (float)i;
		return f;
	}

	void iniussensor(USSensor _sens, Vector2 _uscoord, int _fRAD)
	{
		_sens.inicialise(_uscoord.getX(), _uscoord.getY(), _fRAD);
		sensorsMap[_uscoord] = _sens;
	}
	void iniussensor(USSensor _sens, int _x, int _y, int _fRAD)
	{
		_sens.inicialise(_x, _y, _fRAD);
		sensorsMap[Vector2(_x, _y)] = _sens;
	}

	void addPoint(int pX, int pY)
	{
		Point _point;
		_point.setX(pX);
		_point.setY(pY);
		_point.setIsObstacle(true);
		//TODO: добавить увеличение счетчика точек
		_point.setLevelTrust(0);

		pointsMap[Vector2 (pX, pY)] = _point;
	}
	void addPoint(Vector2 _pV2)
	{
		Point _point;
		_point.setX(_pV2.getX());
		_point.setY(_pV2.getY());
		_point.setIsObstacle(true);
		//TODO: добавить увеличение счетчика точек
		_point.setLevelTrust(0);
		pointsMap[_pV2] = _point;
	}

	float radNormaliser (float rad)
	{
		if (rad >= (2 * PI))
		{
			rad = rad - (2 * PI);
		}
		if (rad < 0)
		{
			rad = rad + (2 * PI);
		}
		return rad;
	}

 inline bool IsOddF(int num){ // true - Odd, false - Even
	 if((num % 2) == 1) return true;
	 if((num % 2) == 0) return false;
 }

	void pointCalcuator(Vector2 _sensorCoordKey)
	{
		 vector<Vector2> _points;
		 USSensor _sensor = this->sensorsMap[_sensorCoordKey];
		 float _pointDirRightRad = radNormaliser (_sensor.getFRad - (_sensor.getAngleRange / 2) * (PI / 180) + _robotdirRad);
		 float _pointDirLeftRad = radNormaliser (_sensor.getFRad + (_sensor.getAngleRange / 2) * (PI / 180) + _robotdirRad);

		 Vector2 _pointV2calc (float _dir)
		 {
			Vector2 _pV2 (( sensor.getValue() * cos(_dir) ),
			 							 (sensor.getValue() * sin(_dir))
										);
			_pV2 = Vector2::v2sum(_pV2, sensorCoordKey)
		 }

		 float _sensorConeDeltaRad;
            if (pointNumber>1)
            {
                _sensorConeDeltaRad = (_sensor.getAngleRange  * (PI / 180)) / (pointNumber - 1);
            }
            else
            {
                _sensorConeDeltaRad = 0;
            }

		 // step one: find points position in sensor coordinate system
		 //Vector2 pointLeftPosition(_pointV2calc(_pointDirLeftRad));
	   //Vector2 pointRightPosition(_pointV2calc(_pointDirRightRad));
		 //Создание новых точек
      int _pnh;
      if ((sensor.getValue() < sensor.getRangeMax) && (sensor.getValue() >= sensor.getRangeMin))
            {
                if (IsOdd(pointNumber))// если максимальное кол-во точек нечетное,
                {                            // то добавляет точку в центр, затем из центра направо и налево

                    if (pointNumber != 1)
                    {
                        _pnh = (pointNumber - 1) / 2;
                    }
                    else
                    {
                        _pnh = 0;
                    }
                    Vector2 _pv2w = _pointV2calc(_sensor.getFRad + _robotdirRad);
                    OPoint.OPointCheckAndCreation(_ptAddX, _ptAddY); // ставим точку в центр

                    for (int i = 1; i <= _pnh; i++)
                    {
                        Vector2 _pv2w = _pointV2calc(_sensor.getFRad + _robotdirRad - _sensorConeDeltaRad * i);
                        OPoint.OPointCheckAndCreation(_ptAddX, _ptAddY);
                    }

                    for (int i = 1; i <= _pnh; i++)
                    {
                        Vector2 _pv2w = _pointV2calc(_sensor.getFRad + _robotdirRad + _sensorConeDeltaRad * i, sensorPositionXWorld);
                        _ptAddY = PointCalculatorY(_sensor.getFRad + _robotdirRad + _sensorConeDeltaRad * i, sensorPositionYWorld);
                        OPoint.OPointCheckAndCreation(_ptAddX, _ptAddY);
                    }
                }
                else if (Util.IsEvenF(pointNumber))
                {
                    _pnh = pointNumber / 2;
                    for (int i = 1; i <= _pnh; i++)
                    {
                        Vector2 _pv2w = _pointV2calc(_sensor.getFRad + _robotdirRad - _sensorConeDeltaRad * i + _sensorConeDeltaRad * 0.5f, sensorPositionXWorld);
                        _ptAddY = PointCalculatorY(_sensor.getFRad + _robotdirRad - _sensorConeDeltaRad * i + _sensorConeDeltaRad * 0.5f, sensorPositionYWorld);
                        OPoint.OPointCheckAndCreation(_ptAddX, _ptAddY);
                    }

                    for (int i = 1; i <= _pnh; i++)
                    {
                        Vector2 _pv2w = _pointV2calc(_sensor.getFRad + _robotdirRad + _sensorConeDeltaRad * i - _sensorConeDeltaRad * 0.5f, sensorPositionXWorld);
                        _ptAddY = PointCalculatorY(_sensor.getFRad + _robotdirRad + _sensorConeDeltaRad * i - _sensorConeDeltaRad * 0.5f, sensorPositionYWorld);
                        OPoint.OPointCheckAndCreation(_ptAddX, _ptAddY);
                    }
                }
            }
		 return points;
	}

	void pointCheckAndCreation(int pX, int pY) // Функция проверяет наличие точки и если нет, ставит новую.
	{
		bool _isEmpty = true;
		float _pRadius;

		float pfX = i2f(pX);
		float pfY = i2f(pY);

		//шаг 1 проверка на раполжение внутри конуса другого датчика, против заикливания создал-удалил
		if (sensorsIs2DeleteCheck(pX, pY))
		{
			_isEmpty = false;
		}
		else
		{
			//шаг 2 проверка на расположение рядом с другой точкой
			for (auto _point : pointsMap)
			{

				_pRadius = sqrt((float)(pow((float)_point.second.getX() - pfX, 2) + pow((float)_point.second.getY() - pfY, 2)));
				if (f2i(_pRadius) >= exclusionRadius)
				{
					_isEmpty = false;
					break;
				}
				else // шаг 3 создание точки
				{
					addPoint(pX, pY);
				}
			}
		}

	}

	void pointDelete(int _pX, int _pY)
	{
		pointsMap.erase(pointsMap.find(Vector2(_pX, _pY)));
		//TODO: добавить уменьшение счетчика точек
	}

	bool sensorsIs2DeleteCheck(int _pX, int _pY) //функция проверки на удаление точки(Х,У) датчиками
	{
		int _sensFrW;
		float _angleBufferRAD = 2 * (PI / 180);
		for (auto _sens : sensorsMap)
		{
			_sensFrW = radNormaliser(_sens.second.getFRad() + robotdirRad); // Переменная направления датчика в МСК в радианах

			Vector2 _sensPW = Vector2::v2sum(_sens.first, robotVector2); // вектор положения датчика в МСК

			// если точка вне радиуса работы датчика, то и не проверяем.
			if (!(
				(_sens.second.getRangeMin() <= _sensPW.getMod())
				&&
				(_sensPW.getMod() <= (_sens.second.getRangeMax() - exclusionRadius))
				))
			{
				continue;
			}

			float _pDirection;

			if (_pX >= 0 && _pY >= 0) // расчет угла направления точки в МСК
			{
				_pDirection = atan(_pY / _pX);
			}
			else if (_pX > 0 && _pY < 0)
			{
				_pDirection = atan(_pY / _pX) + 2 * PI;
			}
			else if (_pX < 0)
			{
				_pDirection = atan(_pY / _pX) + PI;
			}
			else if (_pX == 0 && _pY > 0)
			{
				_pDirection = PI / 2;
			}
			else if (_pX == 0 && _pY < 0)
			{
				_pDirection = 3 * PI / 2;
			}
			else if (_pX == 0 && _pY == 0)
			{
				_pDirection = 0;
			}

			float _angleRangeRAD = _sens.second.getAngleRange() * (PI / 180);
			float _angleLeftRAD = _sensFrW + _angleRangeRAD;
			if (_angleLeftRAD >= (2 * PI))
			{
				_angleLeftRAD = _angleLeftRAD - (2 * PI);
			}

			float _angleRightRAD = _sensFrW + _angleRangeRAD;
			if (_angleRightRAD < 0)
			{
				_angleRightRAD = _angleRightRAD + (2 * PI);
			}



			// Если конус НЕ пересекает 0
			if (
				((_angleRangeRAD / 2) <= _sensFrW)
				&&
				(_sensFrW <= (2 * PI - (_angleRangeRAD / 2)))
				)
			{
				if (
					((_angleRightRAD + _angleBufferRAD) < _pDirection)
					&&
					(_pDirection < (_angleLeftRAD - _angleBufferRAD))
					)
				{
					return true;
				}
				else continue;
			}
			else if (_sensFrW < (_angleRangeRAD / 2)) // если конус датчика проходит через 0 и направление датчика больше 0
			{
				if (
					(0 < _pDirection)
					&&
					(_pDirection < (_angleLeftRAD - _angleBufferRAD))
					)
				{
					return true;
				}
				else if (
					((_angleRightRAD + _angleBufferRAD) < _pDirection)
					&&
					(_pDirection < (2 * PI))
					)
				{
					return true;
				}
				else continue;
			}
		}
		return false;
	}

	// функции-болванки Пока ут потом перенесем куда надо
	void robotPositionUpdate() // тут функция получения позиции робота Х,У, направления
	{

	}

	void sensorUpdatePosition()
	{

	}


	// переменные положения робота, пока тут
	Vector2 robotVector2; // в мм?
	int robotdirRad; // в радианах
};
