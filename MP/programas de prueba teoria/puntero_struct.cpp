//un struct o class puede contener campos de tipo puntero
#include<iostream>
#include<string>
using namespace std;

struct Persona{
    string nombre;
    int edad;
    double estatura;
    Persona * pareja;
};

int main(){
    Persona pepe={"Pepe",27,1.89,0},
    maria={"Maria",25,1.74,0},
    * ptr=&pepe;

    pepe.pareja=&maria;
    maria.pareja=&pepe;
    cout<<"La pareja de "<<ptr->nombre<<" es "
    <<ptr->pareja->nombre<<endl;

    return 0;
}
