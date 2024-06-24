#ifndef DETALLEVENTAARCHIVO_H_INCLUDED
#define DETALLEVENTAARCHIVO_H_INCLUDED
#include <string>
using namespace std;
#include "DetalleVenta.h"

class DetalleVentaArchivo{
    private:
        string _nombreArchivo;

    public:
        DetalleVentaArchivo(string nombreArchivo);
         DetalleVentaArchivo();

        bool guardar(DetalleVenta aux);
        DetalleVenta leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        void vaciarArchivo();



};


#endif // DETALLEVENTAARCHIVO_H_INCLUDED
