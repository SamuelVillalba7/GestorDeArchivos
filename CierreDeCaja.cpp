#include <iostream>
#include "CierreDeCaja.h"

using namespace std;

CierreDeCaja::CierreDeCaja(){
    _id=-1;

}

CierreDeCaja::CierreDeCaja(int id,int idSucursal, int dniEmplado , float facturacion , float ganancia){
    setId(id);
    setDniEmpleado(dniEmplado);
    setFacturacion(facturacion);
    setIdSucursal(idSucursal);
    setDiferencia(0);
    setVerificado(false);
    setFecha(Fecha());
    setHora(Horario());
    setGanancia(ganancia);

}


void CierreDeCaja::setId(int x){
    _id=x;
}

void CierreDeCaja::setIdSucursal(int x){
    _idSucursal=x;
}
void CierreDeCaja::setDniEmpleado(int x){
    _dniEmpleado=x;
}
void CierreDeCaja::setDiferencia(float x){
    _diferencia=x;
}
void CierreDeCaja::setGanancia(float x){
    _ganancia=x;
}
void CierreDeCaja::setFacturacion(float x){
    _facturacion=x;
}
void CierreDeCaja::setFecha(Fecha x){
    _fecha=x;
}
void CierreDeCaja::setHora(Horario x){
    _hora=x;
}
void CierreDeCaja::setVerificado(bool x){
    _verificado=x;
}





int CierreDeCaja::getId(){
    return _id;
}

int CierreDeCaja::getIdSucursal(){
    return _idSucursal;
}

float CierreDeCaja::getFacturacion(){
    return _facturacion;
}
float CierreDeCaja::getGanancia(){
    return _ganancia;
}

float CierreDeCaja::getDiferencia(){
    return _diferencia;
}

int CierreDeCaja::getDniEmpleado(){
    return _dniEmpleado;
}

Fecha CierreDeCaja::getFecha(){
    return _fecha;
}

Horario CierreDeCaja::getHora(){
    return _hora;
}
bool CierreDeCaja::getVerificado(){
    return _verificado;
}
