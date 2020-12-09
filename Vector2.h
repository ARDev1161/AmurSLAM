#include <cmath>
using namespace std;

class Vector2
{
	int vX;
	int vY;
	float mod;

public:
	Vector2(int _vX, int _vY) 
	{
		vX = _vX;
		vX = _vY;
		mod = sqrt((float)(pow(_vX,2) + pow(_vY, 2)));
	}

	int getX() 
	{
		return vX;
	}
	int getY()
	{
		return vY;
	}
	float getMod()
	{
		return mod;
	}


	static Vector2 v2sum(Vector2 v1, Vector2 v2) //сумма веторов
	{
		return Vector2(v1.vX + v2.vX, v1.vY + v2.vY);
	}

	static Vector2 v2sub(Vector2 v1, Vector2 v2) //разность векторов
	{
		return Vector2(v1.vX - v2.vX, v1.vY - v2.vY);
	}

	static int v2scalar(Vector2 v1, Vector2 v2) // скалярное произведение векторов
	{
		return (v1.vX * v2.vX + v1.vY * v2.vY);
	}

	static float v2cos(Vector2 v1, Vector2 v2) // косинус между двумя векторами 
	{
		return ((v2scalar(v1, v2) / (v1.mod * v2.mod)));
	}

	static Vector2 v2rotation(Vector2 v1, int teta) // поворот вектора на угол тета в радинанах
	{
		float _x = v1.vX * cos(teta) - v1.vY * sin(teta);
		float _y = v1.vX * sin(teta) + v1.vY * cos(teta);
		return Vector2(ceil(_x), ceil(_y));
	}
};

