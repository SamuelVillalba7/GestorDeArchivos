#ifndef USUARIOARCHIVO_H_INCLUDED
#define USUARIOARCHIVO_H_INCLUDED
#include <string>
using namespace std;
#include "Usuario.h"

class UsuarioArchivo{
    private:
        string _nombreArchivo;

    public:
        UsuarioArchivo(string nombreArchivo);
        UsuarioArchivo();

        bool guardar(Usuario usuario);
        Usuario leer(int posicion);
        bool modificar(Usuario usuario,int pos);
        int contarRegistros();
        int buscarPosicion(int dni);
        void vaciarArchivo();


};



#endif // USUARIOARCHIVO_H_INCLUDED
