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
        void listarPorNombre();
        void listarPorRol();
        Usuario iniciarSesion();

        void menuEncargado(Usuario usuario);
        void menuCajero(Usuario usuario);
        void menuDeposito(Usuario usuario);
        void menuSegunSector(Usuario usuario);
        void menuInicio();




};










#endif // USUARIOMANAGER_H_INCLUDED
