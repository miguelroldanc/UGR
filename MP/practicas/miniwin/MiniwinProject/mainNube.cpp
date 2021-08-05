#include <iostream>
#include "particula.h"
#include "nubeparticulas.h"
#include <stdlib.h>
#include "definiciones.h"
using namespace miniwin;
using namespace std;

int main(){
	int ancho, alto;
	srand(time(0));
	ancho = 400;
	alto = 300;
	NubeParticulas nube(5);

//Constructor de copia
	NubeParticulas nuevanube(nube);
	nuevanube.Mover(ancho, alto);
//Constructor por defecto
	NubeParticulas otro;
//Sobrecarga de asignacion
	otro = nuevanube;
	otro.Mover(ancho, alto);
//mostrar
/*
cout << "\n Conjunto Inicial" << endl;
cout << nube;
cout << "\n Conjunto Movido 1" << endl;
cout << nuevanube;
cout << "\n Conjunto Movido 2" << endl;
cout << otro;
cout << endl;
*/
int N;
Particula p;
while (tecla() != ESCAPE){
	borra;
	otro.Mover(ancho, alto);
	for(int i = 0;i< otro.getUtiles(); i++){
		p = otro.ObtieneParticula(i);
		color(p.getColor());
		circulo_lleno(p.getX(), p.getY(), RADIO);
	}
	refresca();
	Particula nueva;
	otro.AgregaParticula(nueva);
	espera(10);
}

	vcierra();
	return 0;
}
