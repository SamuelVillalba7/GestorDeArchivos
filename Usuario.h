#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>
using namespace std;

class Usuario{

    private:
            char _nombre[30],_apellido[30];
            int _sector,_contrasenia,_dni,_sucursal;
    public:
            Usuario(string nombre,string apellido, int sector,int contrasenia ,int dni);
            Usuario();

            void setNombre(string x);
            void setApellido(string x);
            void setSector(int x);
            void setContrasenia(int x);
            void setDni(int x);
            void setSucursal(int x);

            int getSucursal();
            string getNombre();
            string getApellido();
            int getSector();
            int getContrasenia();
            int getDni();
};





#endif // USUARIO_H_INCLUDED
