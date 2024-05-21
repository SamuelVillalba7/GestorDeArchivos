#ifndef DETALLEVENTAMANAGER_H_INCLUDED
#define DETALLEVENTAMANAGER_H_INCLUDED

#include "DetalleVentaArchivo.h"
#include "DetalleVenta.h"
#include "ProductoManager.h"

class DetalleVentaManager{

    private:
        DetalleVentaArchivo _archivo = DetalleVentaArchivo("detalleVentas.dat");

    public:
        void menu();
        bool cargar();
        void mostrar(DetalleVenta aux);
        void listarTodos();
        void listarPorID(int idVenta);
        int contarRegistrosPorId(int idVenta);
        int* cargarVector(int* vec,int idVenta);
        void listarDetallesVenta(int idVenta);



};

#endif // DETALLEVENTAMANAGER_H_INCLUDED
