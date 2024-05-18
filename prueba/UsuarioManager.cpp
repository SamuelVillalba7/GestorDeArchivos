#include <iostream>
using namespace std;
#include <cstdlib>
#include "UsuarioManager.h"
#include "SucursalManager.h"



void UsuarioManager::mostrar(Usuario usuario){
    SucursalManager sm;
    cout<<"Nombre: "<<usuario.getNombre()<<endl;
    cout<<"Apellido: "<<usuario.getApellido()<<endl;
    cout<<"Dni: "<<usuario.getDni()<<endl;
    cout<<"Sucursal: "<<sm.nombrePorId(usuario.getSucursal())<<endl;
    cout<<"Sector: "<<usuario.getSector()<<endl;
    cout<<"Contraseña: "<<usuario.getContrasenia()<<endl;


}
bool UsuarioManager::cargar(){
    Usuario usuario;
    string nombre,apellido;
    int dni,sector,contrasenia,sucursal;
    SucursalManager sm;

    cout<<"Ingrese:"<<endl;

    cout<<"Nombre: ";
    cin>>nombre;
    usuario.setNombre(nombre);

    cout<<"Apellido: ";
    cin>>apellido;
    usuario.setApellido(apellido);

    cout<<"Dni: ";
    cin>>dni;
    usuario.setDni(dni);

        cout<<"Ingrese la Sucursal"<<endl;
    cout<<"Si ingresa 0 se listaran las sucursales cargadas"<<endl;

    cin>>sucursal;

    if(sucursal==0){
        cout<<"---------------------"<<endl;
        sm.listarTodos();
        cout<<"---------------------"<<endl;
        cin>>sucursal;
    }
    bool flag=sm.IdDisponible(sucursal);
    while(!flag){
        cout<<"reingrese sucursal"<<endl;
        cin>>sucursal;
        if(sm.IdDisponible(sucursal)){
            flag=true;
        }
    }

    usuario.setSucursal(sucursal);




    cout<<"Sector: ";
    cin>>sector;
    usuario.setSector(sector);


    cout<<"Contraseña: ";
    cin>>contrasenia;
    usuario.setContrasenia(contrasenia);

    bool guardo=_archivo.guardar(usuario);

    if(guardo){

        cout<<"Se registro correctamente"<<endl;

    }
    else{
        cout<<"no se pudo realizar el registro "<<endl;
    }





}
void UsuarioManager::listarTodos(){

    int cant,x;
    cant=_archivo.contarRegistros();
    Usuario aux;
    cout<<"-------------------------"<<endl;
    cout<<"-------------------------"<<endl;
    for(x=0;x<cant;x++){
        aux=_archivo.leer(x);
        mostrar(aux);
    cout<<"-------------------------"<<endl;
    cout<<"-------------------------"<<endl;
    }


}
void UsuarioManager::listarPorDni(){
   int pos,dni;

   cout<<"Ingrese el dni"<<endl;
   cin>>dni;

   pos=_archivo.buscarPosicion(dni);

   if(pos>=0){
    Usuario aux;
    aux=_archivo.leer(pos);
    mostrar(aux);
   }else{

        cout<<"Dni no registrado"<<endl;

   }

}


 Usuario UsuarioManager::iniciarSesion(){

    int dni,pos;
    cout<<"Ingrese su dni"<<endl;
    cin>>dni;


    pos=_archivo.buscarPosicion(dni);

    if(pos<0){
        cout<<"Dni no registrado"<<endl;
        Usuario u;
        return u;
    }

    Usuario aux;

    aux=_archivo.leer(pos);
    system("cls");


    int contrasenia=1;
    cout<<"Hola "<<aux.getNombre()<<" "<<aux.getApellido()<<endl;

    while(contrasenia!=0){

     cout<<"Ingrese su contraseña"<<endl;
    cin>>contrasenia;


    if(contrasenia==aux.getContrasenia()){
        cout<<"Contraseña correcta"<<endl;
        return aux;
    }else{
        cout<<"Contraseña incorrecta"<<endl;
    }


    }
 }


 void UsuarioManager::menuEncargado(){

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU USUARIOS" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVO USUARIO" << endl;
        cout << "2) LISTAR USUARIOS" << endl;
        cout << "3) LISTAR USUARIOS POR DNI" << endl;
        cout << "4) PRODUCTIVIDAD DE EMPLEADOS DE CAJA" << endl;
        cout << "3) PRODUCTIVIDAD DE EMPLEADOS DE STOCK" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                   cargar();
                }
                break;
            case 2:
                {
                   listarTodos();
                }
                break;
            case 3:
                {
                   listarPorDni();
                }
                break;

            case 0:
                return;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
            break;
        }

        system("pause");

    }

}

