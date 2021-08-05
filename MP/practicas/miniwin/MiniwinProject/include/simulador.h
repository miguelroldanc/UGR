#include "particula.h"
#include "nubeparticulas.h"
#include "miniwin.h"
#ifndef _SIMULADOR_H_
#define _SIMULADOR_H_
class Simulador{
private:
	NubeParticulas mi_nube;
	int nro_p;
	int ancho, alto;
public:
	Simulador(int anc, int alt, int nro_p);
	~Simulador();
	void Mover();
	void Pintar();
	void GestionColisiones();
};

#endif
