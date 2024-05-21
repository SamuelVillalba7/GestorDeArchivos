#pragma once

#include "CierreDeCaja.h"
#include "CierreDeCajaArchivo.h"
class CierreDeCajaManager{
    private:
        CierreDeCajaArchivo _archivo;

    public:
        void menu();
        void mostrar(CierreDeCaja cierreDeCaja);
        void listarTodos();
        void listarPorID();
        bool IdDisponible(int id);



};

