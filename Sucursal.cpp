#include <iostream>
#include <cstring>
#include "Sucursal.h"

using namespace std;

Sucursal::Sucursal(){
    _id=-1;
    setNombre("");
}

Sucursal::Sucursal(int id,string nombre){
    setId(id);
    setNombre(nombre);
}

void Sucursal::setNombre(string x)
{
    strcpy(_nombre, x.c_str());
}


string Sucursal::getNombre()
{
    string nombre=_nombre;
    return nombre;

}

void Sucursal::setId(int x){
    _id=x;
}

int Sucursal::getId(){
    return _id;
}


void Sucursal::setEstado(bool x){
    _estado=x;
}

bool Sucursal::getEstado(){
    return _estado;
}
