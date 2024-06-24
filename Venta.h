#ifndef CLSVENTA_H_INCLUDED
#define CLSVENTA_H_INCLUDED
#include "Fecha.h"
#include "Horario.h"

class Venta{

    private:
        int _id;
        int _formaDePago;
        float _precio;
        float _ganancia;
        int _sucursal;
        int _dniEmpleado;
        Fecha _fecha;
        Horario _hora;

    public:
        Venta(int id,int formaDePago,float precio,int sucursal,int dni , float ganancia);
        Venta();

        void setId(int x);
        void setDniEmpleado(int x);
        void setSucursal(int x);
        void setFecha(Fecha x);
        void setFormaDePago(int x);
        void setHorario(Horario x);
        void setPrecio(float x);
        void setGanancia(float x);

        int getId();
        int getDniEmpleado();
        int getSucursal();
        Fecha getFecha();
        int getFormaDePago();
        Horario getHora();
        float getPrecio();
        float getGanancia();

};




#endif // CLSVENTA_H_INCLUDED
