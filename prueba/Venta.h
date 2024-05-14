#ifndef CLSVENTA_H_INCLUDED
#define CLSVENTA_H_INCLUDED
#include "Fecha.h"
#include "Horario.h"

class Venta{

    private:
        int _id;
        int _formaDePago;
        int _precio;
        Fecha _fecha;
        Horario _hora;

    public:
        Venta(int id,int formaDePago,int _precio);
        Venta();

        void setId(int x);
        void setFecha(Fecha x);
        void setFormaDePago(int x);
        void setHorario(Horario x);
        void setPrecio(int x);

        int getId();
        Fecha getFecha();
        int getFormaDePago();
        Horario getHora();
        int getPrecio();

};




#endif // CLSVENTA_H_INCLUDED
