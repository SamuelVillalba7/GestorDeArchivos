#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED
#include "ProductoArchivo.h"
#include "Producto.h"
#include "DetalleVenta.h"

class ProductoManager{

    private:
        ProductoArchivo _archivo = ProductoArchivo("productos.dat");

    public:
        void menu();
        bool cargar();
        void mostrar(Producto producto);
        void listarTodos();
        void listarPorID();
        void listarVecDetalles(int *vec,int tam);
        int generarId();

};

#endif // PRODUCTOMANAGER_H_INCLUDED
