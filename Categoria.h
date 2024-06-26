#pragma once

#include <string>
using namespace std;

class Categoria{

    private:
        int _id;
        char _nombre[30];
        bool _estado;
    public:

        Categoria();

        Categoria(int id,string nombre);

        int getId();
        string getNombre();

        void setId(int x);
        void setNombre(string x);
        void setEstado(bool x);
        bool getEstado();


};







