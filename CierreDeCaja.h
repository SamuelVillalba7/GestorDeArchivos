#pragma once
using namespace std;

#include "Fecha.h"
#include "Horario.h"

class CierreDeCaja{

    private:
        int _id;
        Fecha _fecha;
        Horario _hora;
        int _idSucursal;
        int _dniEmpleado;
        float _facturacion;
        bool _verificado;
        float _diferencia;
        float _ganancia;



    public:

        CierreDeCaja();
        CierreDeCaja(int id,int idSucursal, int dniEmplado , float facturacion , float ganancia);

        int getId();
        void setId(int x);
        int getIdSucursal();
        void setIdSucursal(int x);
        int getDniEmpleado();
        void setDniEmpleado(int x);
        float getFacturacion();
        void setFacturacion(float x);
        float getGanancia();
        void setGanancia(float x);
        float getDiferencia();
        void setDiferencia(float x);
        Fecha getFecha();
        void setFecha(Fecha x);
        Horario getHora();
        void setHora(Horario x);
        bool getVerificado();
        void setVerificado(bool x);




};






