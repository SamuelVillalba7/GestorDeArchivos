#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED
#include "ProductoArchivo.h"
#include "Producto.h"


class ProductoManager{

    private:
        ProductoArchivo _archivo = ProductoArchivo("productos.dat");

    public:
        void menu();
        bool cargar();
        void mostrar(Producto producto);
        void listarTodos();
        void listarPorID();
        void listarStock0();
        void listarStockMenor();
        void listarStockMayor();
        void listarVectorDeId(int *vec,int tam);
        void ingresoStock();
        bool restarStock(int id);
        void bajaLogica();
        void modificarPrecio();
        int ingresarId();

};

#endif // PRODUCTOMANAGER_H_INCLUDED
