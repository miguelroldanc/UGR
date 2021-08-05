#include "particula.h"
#include <iostream>
using namespace std;
#ifndef _NUBEDEPARTICULAS_H_
#define _NUBEDEPARTICULAS_H_

class NubeParticulas{
	private:
		Particula* nube;
		int capacidad;
		int utiles;
	public:
		NubeParticulas(int cap);
		NubeParticulas();
		NubeParticulas(const NubeParticulas &n);
		~NubeParticulas();
		NubeParticulas& operator=(const NubeParticulas &n);
		int getCapacidad() const;
		int getUtiles() const;
		void AgregaParticula(Particula &nueva);
		void BorraParticula(int pos);
		Particula ObtieneParticula(int pos) const;
		void Mover(int ancho, int alto);
		float Distancia(int a,int b);
		void Colisiones();
};

ostream& operator<<(ostream &flujo, const NubeParticulas &n);
#endif
