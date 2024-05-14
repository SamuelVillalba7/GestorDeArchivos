#ifndef VENTAMANAGER_H_INCLUDED
#define VENTAMANAGER_H_INCLUDED
#include "VentaArchivo.h"
#include "Venta.h"


class VentaManager{

    private:
        VentaArchivo _archivo = VentaArchivo("ventas.dat");

    public:
        void menu();
        Venta cargar();
        void mostrar(Venta aux);
        void listarTodos();
        int listarPorID();
        int generarId();

};

#endif // VENTAMANAGER_H_INCLUDED
