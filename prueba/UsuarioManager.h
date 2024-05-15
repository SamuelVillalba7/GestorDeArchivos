#ifndef USUARIOMANAGER_H_INCLUDED
#define USUARIOMANAGER_H_INCLUDED

#include "Usuario.h"
#include "UsuarioArchivo.h"

class UsuarioManager{

    private:
        UsuarioArchivo _archivo = UsuarioArchivo("usuarios.dat");

    public:
        void mostrar(Usuario usuario);
        bool cargar();
        void listarTodos();
        void listarPorDni();
        Usuario iniciarSesion();




};










#endif // USUARIOMANAGER_H_INCLUDED
