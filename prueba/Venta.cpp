#include <iostream>
#include <cstring>
using namespace std;
#include "Venta.h"

Venta::Venta(int id,int formaDePago,int precio){

     _id=id;
     _fecha=Fecha();
     _formaDePago=formaDePago;
     _precio=precio;
     _hora=Horario();


}

 Venta::Venta(){

     _id=0;
     _fecha=Fecha();
     _hora=Horario();
     _formaDePago=0;
     _precio=0;
     }

void Venta::setId(int x){
    _id=x;
}
void Venta::setPrecio(int x){
    _precio=x;
}

void Venta::setFecha(Fecha x){
    _fecha=x;
}

void Venta::setFormaDePago(int x){
    _formaDePago=x;
}

void Venta::setHorario(Horario x){
    _hora=x;
}
Horario Venta::getHora(){
    return _hora;
}

int Venta::getId(){
    return _id;
}

Fecha Venta::getFecha(){
    return _fecha;
}

int Venta::getFormaDePago(){
    return _formaDePago;
}

int Venta::getPrecio(){
    return _precio;
}
