#include "miniwin.h"
#include <iostream>
#include "particula.h"
#include "nubeparticulas.h"
#include "simulador.h"
#include <stdlib.h>
#include "definiciones.h"
using namespace miniwin;
using namespace std;

int main(){
int ancho = 800, alto = 600, particulas = 100;
srand(time(0));
Simulador gestor(ancho, alto, particulas);

while(tecla() != ESCAPE){
	gestor.GestionColisiones();
	gestor.Mover();
	gestor.Pintar();
	espera(15);
}

return 0;
}
