#pragma once
#include <string>
using namespace std;
#include "CierreDeCaja.h"

class CierreDeCajaArchivo{
    private:
        string _nombreArchivo;

    public:
        CierreDeCajaArchivo(string nombreArchivo);
        CierreDeCajaArchivo();

        bool guardar(CierreDeCaja cierreDeCaja);
        bool modificar(CierreDeCaja cierreDeCaja, int pos);
        CierreDeCaja leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        int generarId();
        void vaciarArchivo();


};

