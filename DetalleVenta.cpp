#include <iostream>
#include <cstring>
#include "DetalleVenta.h"

using namespace std;

DetalleVenta::DetalleVenta(int idVenta,int idProducto){

    _idVenta=idVenta;
    _idProducto=idProducto;

}

DetalleVenta::DetalleVenta(){

    _idVenta=0;
    _idProducto=0;

}

void DetalleVenta::setIdVenta(int x){
    _idVenta=x;
}

void DetalleVenta::setIdProducto(int x){
    _idProducto=x;
}


int DetalleVenta::getIdVenta(){
    return _idVenta;
}

int DetalleVenta::getIdProducto(){
    return _idProducto;
}

