#pragma once

#include "CierreDeCaja.h"
#include "CierreDeCajaArchivo.h"
#include "FuncionesExtras.h"

class CierreDeCajaManager{
    private:
        CierreDeCajaArchivo _archivo;

    public:
        void menu();
        void mostrar(CierreDeCaja cierreDeCaja);
        void listarTodos();
        void listarPorID();
        bool IdDisponible(int id);
        void VerificarCierres();
        void listarDelDiaSinVerificar();


        void listarNoVerificados();
        void listarVerificados();
        int cantidadPorMes(int mes);
        void cargarVecPorMes(int mes,CierreDeCaja *vec);
        void facturadoPorMes();

};

