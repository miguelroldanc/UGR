#include <stdlib.h>
#include "miniwin.h"
#include "definiciones.h"
#include <cmath>
#include "particula.h"
#include <iostream>
using namespace std;
using namespace miniwin;
Color C1[4]={BLANCO, VERDE, ROJO, AMARILLO};

Particula::Particula(){
	x = rand()%MAX_X + 1.0;
	y = rand()%MAX_Y + 1.0;
	dx = rand()%MAX_VEL;
	dy = rand()%MAX_VEL;
	c = C1[rand()%4];
}

Particula::Particula(float _x, float _y){
	x = _x;
	y = _y;
	dx = 1.0;
	dy = 1.0;
	c = ROJO;
}

Particula::Particula(const Particula &p){
	x = p.getX();
	y = p.getY();
	dx = p.getdX();
	dy = p.getdY();
	c = p.getColor();
}

float Particula::getX() const{return x;}

float Particula::getY() const{return y;}

float Particula::getdX() const{return dx;}

float Particula::getdY() const{return dy;}

Color Particula::getColor() const{return c;}

void Particula::setX(float _x){
	x = _x;
}
void Particula::setY(float _y){
	y = _y;
}
void Particula::setdX(float _dx){
	dx = _dx;
}
void Particula::setdY(float _dy){
	dy = _dy;
}
void Particula::setColor(Color _c){
	c = _c;
}

void Particula::Mover(int ancho, int alto){
	this->setX(this->getX()+this->getdX());
	this->setY(this->getY()+this->getdY());
	if (this->getX() > (ancho - RADIO)){
		this->setdX((-1)*FACTOR*this->getdX());
		this->setX(ancho - RADIO);
	} 
	else if (this->getX() < RADIO) {
		this->setdX(this->getdX()*(-1)*FACTOR);
		this->setX(RADIO);
	} 
	else if (this->getY() > (alto - RADIO)){
		this->setdY(this->getdY()*(-1)*FACTOR);
		this->setY(alto - RADIO);
	} 
	else if (this->getY() < RADIO) {
		this->setdY(this->getdY()*(-1)*FACTOR);
		this->setY(RADIO);
	
	}
}

bool Particula::Parado(){
	return((this->getdY() == 0)&&(this->getdX() == 0));
}
