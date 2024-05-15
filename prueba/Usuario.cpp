#include <iostream>
#include <cstring>
#include "Usuario.h"

using namespace std;




Usuario::Usuario(string nombre,string apellido, int sector,int contrasenia ,int dni){
    strcpy(_nombre,nombre.c_str());
    strcpy(_apellido,apellido.c_str());
    _sector=0;
    _contrasenia=0;
    _dni=0;
}




Usuario::Usuario(){
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    _sector=0;
    _contrasenia=0;
    _dni=0;
}

void Usuario::setNombre(string x){
    strcpy(_nombre,x.c_str());
}
void Usuario::setApellido(string x){
    strcpy(_apellido,x.c_str());
}
void Usuario::setSector(int x){
    _sector=x;
}
void Usuario::setContrasenia(int x){
    _contrasenia=x;
}
void Usuario::setDni(int x){
    _dni=x;
}

string Usuario::getNombre(){
    string x=_nombre;
    return x;
}
string Usuario::getApellido(){
    string x=_apellido;
    return x;
}
int Usuario::getSector(){
    return _sector;
}
int Usuario::getContrasenia(){
    return _contrasenia;
}
int Usuario::getDni(){
    return _dni;
}
