#ifndef SUCURSALARCHIVO_H_INCLUDED
#define SUCURSALARCHIVO_H_INCLUDED
#include <string>
using namespace std;
#include "Sucursal.h"

class SucursalArchivo{
    private:
        string _nombreArchivo;

    public:
        SucursalArchivo(string nombreArchivo);
        SucursalArchivo();

        bool guardar(Sucursal sucursal);
        bool modificar(Sucursal sucursal, int pos);
        Sucursal leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        int generarId();



};


#endif // SUCURSALARCHIVO_H_INCLUDED
