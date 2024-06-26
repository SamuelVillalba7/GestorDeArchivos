#pragma once

#include "Categoria.h"
#include "CategoriaArchivo.h"
class CategoriaManager{

    private:
        CategoriaArchivo _archivo = CategoriaArchivo("categorias.dat");

    public:
        void menu();
        bool cargar();
        void mostrar(Categoria categoria);
        void listarTodos();
        void listarPorID();
        bool IdDisponible(int id);
        string nombrePorId(int id);
        void bajaLogica();
        int ingresarId();

};


