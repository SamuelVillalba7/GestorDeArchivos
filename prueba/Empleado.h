#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


class Usuario{

    private:
            char nombre[30],apellido[30];
            int sector,contrase�a,dni;
    public:
            void setNombre(string x);
            void setApellido(string x);
            void setSector(int x);
            void setContrase�a(int x);
            void setDni(int x);

            string getNombre();
            string getApellido();
            int getSector();
            int getContrase�a();
            int getDni();
};





#endif // EMPLEADO_H_INCLUDED
