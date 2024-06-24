#pragma once
#include <string>
using namespace std;
#include "Categoria.h"

class CategoriaArchivo{
    private:
        string _nombreArchivo;

    public:
        CategoriaArchivo(string nombreArchivo);
        CategoriaArchivo();

        bool guardar(Categoria categoria);
        bool modificar(Categoria categoria, int pos);
        Categoria leer(int posicion);
        int contarRegistros();
        int buscarPosicion(int id);
        int generarId();
        void vaciarArchivo();


};

