#include "particula.h"
#include "nubeparticulas.h"
#include "simulador.h"
#include "definiciones.h"
#include "miniwin.h"

Simulador::Simulador(int anc, int alt, int nro):mi_nube(nro), ancho(anc), alto(alt), nro_p(nro){
	vredimensiona(ancho, alto);
}
Simulador::~Simulador(){
	vcierra();
}
void Simulador::Mover(){
	this->mi_nube.Mover(this->ancho, this->alto);
}
void Simulador::Pintar(){
	borra();
	Particula p;
	for(int i = 0; i < mi_nube.getUtiles();i++){
		p = this->mi_nube.ObtieneParticula(i);
		color(p.getColor());
		circulo_lleno(p.getX(), p.getY(), RADIO);
	}
	refresca();
}

void Simulador::GestionColisiones(){
	mi_nube.Colisiones();
}
