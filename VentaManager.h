#ifndef VENTAMANAGER_H_INCLUDED
#define VENTAMANAGER_H_INCLUDED
#include "VentaArchivo.h"
#include "Venta.h"
#include "Usuario.h"


class VentaManager{

    private:
        VentaArchivo _archivo = VentaArchivo("ventas.dat");

    public:
        void menu();
        Venta cargar();
        void mostrar(Venta aux);
        void mostrar(int id);
        void listarTodos();
        void recaudacionPorDia();
        int listarPorID();
        int generarId();
        int contarVentasDelDia();
        void cargarVecVentaDelDia(int* vec);
        void cierreDeCaja(Usuario usuario);


};

#endif // VENTAMANAGER_H_INCLUDED
