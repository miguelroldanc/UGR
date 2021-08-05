#include "particula.h"
#include "definiciones.h"
#include "nubeparticulas.h"
#include <iostream>
#include <cmath>
using namespace std;
ostream& operator<<(ostream &flujo, const NubeParticulas &n){
	for(int f = 0;f <= n.getUtiles();f++){
		flujo << n.ObtieneParticula(f).getX() << n.ObtieneParticula(f).getY()
		<< n.ObtieneParticula(f).getdX()  << n.ObtieneParticula(f).getdY()
		<< n.ObtieneParticula(f).getColor();
	}
	return flujo;
}

NubeParticulas::NubeParticulas(int cap){
	nube = new Particula[cap];
	capacidad = cap;
	utiles = cap;
}

NubeParticulas::NubeParticulas(){
	capacidad = 10;
	utiles = 10;
	nube = new Particula[capacidad];
}
NubeParticulas::NubeParticulas(const NubeParticulas &n){
	capacidad = n.getCapacidad();
	utiles = n.getUtiles();
	nube = new Particula[capacidad];
	for(int i = 0; i <= capacidad;++i){
		nube[i] = n.ObtieneParticula(i);
	}
}

NubeParticulas& NubeParticulas::operator=(const NubeParticulas &n){
if(&n != this){
	delete []this->nube;
	this->capacidad = n.getCapacidad();
	this->utiles = n.getUtiles();
	this->nube = new Particula[capacidad];
	for(int i = 0; i <= capacidad;++i){
		nube[i] = n.ObtieneParticula(i);
	}
}
return *this;
}
NubeParticulas::~NubeParticulas(){
	if(nube != 0){
		delete []nube;
	}
}

int NubeParticulas::getCapacidad() const{return capacidad;}

int NubeParticulas::getUtiles() const{return utiles;}

void NubeParticulas::AgregaParticula(Particula &nueva){
	++utiles;
	if(utiles >= capacidad){
		Particula* ptr = nube;
		capacidad = capacidad+TAM_BLOQUE;
		nube = new Particula[capacidad];
		for(int a = 0; a<utiles; a++){
			nube[a] = ptr[a];
		}
		delete [] ptr;
		ptr = 0;
	}
	nube[utiles-1] = nueva;
}

void NubeParticulas::BorraParticula(int pos){
	for(int a = pos;a < utiles;a++){
		nube[a] = nube[a+1];
	}
	utiles--;
}

Particula NubeParticulas::ObtieneParticula(int pos) const{
	if((pos > -1) && (pos <= this->getUtiles())){return nube[pos];}
}

void NubeParticulas::Mover(int ancho, int alto){
	for(int i = 0;i < (this->utiles);++i){
		this->nube[i].Mover(ancho, alto);
	}
}

float NubeParticulas::Distancia(int a, int b){
	float distancia = 0.0;
	distancia = (this->nube[b].getX() - this->nube[a].getX())*(this->nube[b].getX() - this->nube[a].getX());
	distancia += (this->nube[b].getY() - this->nube[a].getY())*(this->nube[b].getY() - this->nube[a].getY());
	distancia = sqrt(distancia);
	return distancia;
}

void NubeParticulas::Colisiones(){
	for(int a=0;a < this->getUtiles();a++){
		for(int b= a + 1;b < this->getUtiles();b++){
			if(this->Distancia(a,b) < UMBRAL){
				if(this->nube[a].Parado()){
					this->BorraParticula(b);
				}else{
					if(this->nube[b].Parado()){
						this->BorraParticula(a);
					}else{
						this->BorraParticula(b);
					}
				}
			}
		}
	}
}
