#ifndef _PARTICULA_H_
#define _PARTICULA_H_
#include "miniwin.h"
#include <iostream>
using namespace std;
using namespace miniwin;

class Particula{
	private:
		float x, y;
		float dx, dy;
		Color c;
	public:
		Particula();
		Particula(float _x, float _y);
		Particula(const Particula &p);
		void setX(float _x);
		void setY(float _y);
		void setdX(float _dx);
		void setdY(float _dy);
		void setColor(Color _c);
		float getX() const;
		float getY() const;
		float getdX() const;
		float getdY() const;
		Color getColor() const;
		void Mover(int ancho, int alto);
		bool Parado();
};
ostream& operator<<(ostream &flujo, const Particula &n);

#endif
