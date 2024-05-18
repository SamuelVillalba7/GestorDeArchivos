#ifndef SUCURSAL_H_INCLUDED
#define SUCURSAL_H_INCLUDED

#include <string>
using namespace std;

class Sucursal{

    private:
        int _id;
        char _nombre[30];
    public:

        Sucursal();

        Sucursal(int id,string nombre);

        int getId();
        string getNombre();

        void setId(int x);
        void setNombre(string x);


};







#endif // SUCURSAL_H_INCLUDED
