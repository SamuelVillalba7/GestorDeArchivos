#ifndef PRODUCTOARCHIVO_H_INCLUDED
#define PRODUCTOARCHIVO_H_INCLUDED
#include <string>
using namespace std;
#include "Producto.h"

class ProductoArchivo{
    private:
        string _nombreArchivo;

    public:
        ProductoArchivo(string nombreArchivo);
        ProductoArchivo();

        bool guardar(Producto producto);
        bool modificar(Producto producto, int pos);
        Producto leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        int generarId();



};

#endif // PRODUCTOARCHIVO_H_INCLUDED
