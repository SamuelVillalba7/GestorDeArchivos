#ifndef CLSDETALLEVENTA_H_INCLUDED
#define CLSDETALLEVENTA_H_INCLUDED

#include "Horario.h"
#include "Producto.h"
class DetalleVenta{

    private:
        int _idVenta;
        int _idProducto;

    public:

        DetalleVenta(int idVenta,int idProducto);
        DetalleVenta();

        void setIdVenta(int x);
        void setIdProducto(int x);

        int getIdVenta();
        int getIdProducto();


};


#endif // CLSDETALLEVENTA_H_INCLUDED
