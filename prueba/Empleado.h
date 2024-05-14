#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


class Usuario{

    private:
            char nombre[30],apellido[30];
            int sector,contraseña,dni;
    public:
            void setNombre(string x);
            void setApellido(string x);
            void setSector(int x);
            void setContraseña(int x);
            void setDni(int x);

            string getNombre();
            string getApellido();
            int getSector();
            int getContraseña();
            int getDni();
};





#endif // EMPLEADO_H_INCLUDED
