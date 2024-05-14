#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED


class Fecha{
    private:
        int _dia,_mes,_anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        int getDia();
        int getMes();
        int getAnio();

        void mostrar();
        void cargar();

        bool validarFecha(Fecha aux);
        bool validar();

        bool bisiesto(int anio);

        void agregarDia();
        void restarDia();

        string toString();
};






#endif // CLASSFECHA_H_INCLUDED
