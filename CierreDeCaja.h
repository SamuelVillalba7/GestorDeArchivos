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
        int _facturacion;
        bool _verificado;
        int _diferencia;



    public:

        CierreDeCaja();
        CierreDeCaja(int id,int idSucursal, int dniEmplado , int facturacion);

        int getId();
        void setId(int x);
        int getIdSucursal();
        void setIdSucursal(int x);
        int getDniEmpleado();
        void setDniEmpleado(int x);
        int getFacturacion();
        void setFacturacion(int x);
        int getDiferencia();
        void setDiferencia(int x);
        Fecha getFecha();
        void setFecha(Fecha x);
        Horario getHora();
        void setHora(Horario x);
        bool getVerificado();
        void setVerificado(bool x);




};






