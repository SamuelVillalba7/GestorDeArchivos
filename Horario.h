#ifndef CLSHORARIO_H_INCLUDED
#define CLSHORARIO_H_INCLUDED


#include <string>
using namespace std;

class Horario{

    private:
        int _hora, _minuto;

    public:
        Horario(int hora, int minuto);
        Horario();

        void mostrar();

        int getHora();
        int getMinuto();

        void setHora(int hora);
        void setMinuto(int minuto);

        string toString();


};





#endif // CLSHORARIO_H_INCLUDED
