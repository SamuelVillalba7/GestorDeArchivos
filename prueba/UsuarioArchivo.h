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
        int contarRegistros();
        int buscarPosicion(int dni);



};



#endif // USUARIOARCHIVO_H_INCLUDED
