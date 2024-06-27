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
        void masVendida();
        void menosVendida();
        void ventasPorCategoria();
        string devolverNombre(int pos);
        void cargarCantVentas(int *vecCategorias,int tam);
        void cargarGanancias(int *vecCategorias,int tam);
        void recaudadoPorCategoria();
        void superoVentas();
        void noSuperoVentas();
        void generoMasGanancias();
        void generoMenosGanancias();
        void superoGanancias();
        void noSuperoGanancias();
        void gananciaPorId();
        void ventaPorId();


};


