#include <iostream>
#include <cstring>
#include "Categoria.h"

using namespace std;

Categoria::Categoria(){
    _id=-1;
    setNombre("");
}

Categoria::Categoria(int id,string nombre){
    setId(id);
    setNombre(nombre);
}

void Categoria::setNombre(string x)
{
    strcpy(_nombre, x.c_str());
}


string Categoria::getNombre()
{
    string nombre=_nombre;
    return nombre;

}

void Categoria::setId(int id){
    _id=id;
}

int Categoria::getId(){
    return _id;
}
