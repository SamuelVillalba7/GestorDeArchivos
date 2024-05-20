#pragma once

#include <string>
using namespace std;

class Categoria{

    private:
        int _id;
        char _nombre[30];
    public:

        Categoria();

        Categoria(int id,string nombre);

        int getId();
        string getNombre();

        void setId(int x);
        void setNombre(string x);


};







