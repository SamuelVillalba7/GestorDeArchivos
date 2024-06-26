#include <iostream>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto(){
    _id=0;
    strcpy(_nombre, "");
    _precioCompra = 0;
    _stock = 0;
    _precioVenta = 0;
    _categoria = 0;
    _estado = true ;

}

Producto::Producto(int id,string nombre, float precioC,float precioV, int stock, int categoria)
{
    setId(id);
    setNombre(nombre);
    setPrecioCompra(precioC);
    setPrecioVenta(precioV);
    setStock(stock);
    setCategoria(categoria);
    setEstado(true);

}

void  Producto::setStock(int x)
{
    if (x < 0)
    {
        _stock = 0;
    }
    else
    {
        _stock = x;
    }
}

void Producto::setNombre(string x)
{
    strcpy(_nombre, x.c_str());
}


void Producto::setPrecioCompra(float x)
{
    if (x < 0)
    {
        _precioCompra = 0;
    }
    else
    {
        _precioCompra = x;
    }

}

void Producto::setPrecioVenta(float x)
{
    if (x < 0)
    {
        _precioVenta = 0;
    }
    else
    {
        _precioVenta = x;
    }

}

void Producto::setEstado(bool x){
    _estado=x;
}



void Producto::setCategoria(int x)
{
    _categoria = x;
}



void Producto::setId(int x){
    _id = x;
}


string Producto::getNombre(){
    string nombre = _nombre;
    return nombre;
}
int Producto::getId(){
    return _id;
}

int Producto::getStock(){
    return _stock;
}

int Producto::getCategoria()
{
    return _categoria;
}

float Producto::getPrecioCompra(){
    return _precioCompra;
}
float Producto::getPrecioVenta(){
    return _precioVenta;
}

bool Producto::getEstado(){
    return _estado;
}

/*Producto Producto::cargarProductos()
{



}
   */
