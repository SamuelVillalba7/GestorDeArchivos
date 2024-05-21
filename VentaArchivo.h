#ifndef VENTAARCHIVO_H_INCLUDED
#define VENTAARCHIVO_H_INCLUDED
#include <string>
using namespace std;
#include "Venta.h"

class VentaArchivo{
    private:
        string _nombreArchivo;

    public:
        VentaArchivo(string nombreArchivo);
        VentaArchivo();
        bool guardar(Venta aux);
        Venta leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        int generarId();



};


#endif // VENTAARCHIVO_H_INCLUDED
