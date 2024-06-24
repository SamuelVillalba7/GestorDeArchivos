#include <iostream>
#include <cstring>
using namespace std;
#include "Venta.h"

Venta::Venta(int id,int formaDePago,float precio, int sucursal,int dni,float ganancia){

     _id=id;
     _fecha=Fecha();
     _formaDePago=formaDePago;
     _precio=precio;
     _hora=Horario();
     _sucursal=sucursal;
     _dniEmpleado=dni;
     _ganancia=ganancia;


}

 Venta::Venta(){

     _id=0;
     _fecha=Fecha();
     _hora=Horario();
     _formaDePago=0;
     _precio=0;
     _ganancia=0;
}

void Venta::setId(int x){
    _id=x;
}
void Venta::setPrecio(float x){
    _precio=x;
}

void Venta::setGanancia(float x){
    _ganancia=x;
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
int Venta::getDniEmpleado(){
    return _dniEmpleado;
}

Fecha Venta::getFecha(){
    return _fecha;
}

int Venta::getFormaDePago(){
    return _formaDePago;
}

float Venta::getPrecio(){
    return _precio;
}
float Venta::getGanancia(){
    return _ganancia;
}

void Venta::setSucursal(int x)
{
    _sucursal = x;
}

void Venta::setDniEmpleado(int x)
{
    _dniEmpleado = x;
}



int Venta::getSucursal()
{
    return _sucursal;
}
