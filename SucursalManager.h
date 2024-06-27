#ifndef SUCURSALMANAGER_H_INCLUDED
#define SUCURSALMANAGER_H_INCLUDED

#include "Sucursal.h"
#include "SucursalArchivo.h"
class SucursalManager{

    private:
        SucursalArchivo _archivo = SucursalArchivo("sucursal.dat");

    public:
        void menu();
        bool cargar();
        void mostrar(Sucursal sucursal);
        void listarTodos();
        void listarPorID();
        bool IdDisponible(int id);
        string nombrePorId(int id);
        void bajaLogica();
        int ingresarId();

        void cargarGanancias(int *vec,int tam);
        void gananciasPorSucursal();
        void gananciaPorId();
        void noSuperoGanancia();
        void superoGanancia();
        void generoMasGanancias();
        void generoMenosGanancias();

};


#endif // SUCURSALMANAGER_H_INCLUDED
