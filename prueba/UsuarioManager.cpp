#include <iostream>
using namespace std;
#include <cstdlib>
#include "UsuarioManager.h"



void UsuarioManager::mostrar(Usuario usuario){
    cout<<"Nombre: "<<usuario.getNombre()<<endl;
    cout<<"Apellido: "<<usuario.getApellido()<<endl;
    cout<<"Dni: "<<usuario.getDni()<<endl;
    cout<<"Sector: "<<usuario.getSector()<<endl;



}
bool UsuarioManager::cargar(){
    Usuario usuario;
    string nombre,apellido;
    int dni,sector,contrasenia;

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

    cout<<"Sector: ";
    cin>>sector;
    usuario.setSector(sector);


    cout<<"Contraseña";





}
void UsuarioManager::listarTodos(){

    int cant,x;
    cant=_archivo.contarRegistros();
    Usuario aux;
    for(x=0;x<cant;x++){
        aux=_archivo.leer(x);
        mostrar(aux);
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
        return;
    }

    Usuario aux;

    aux=_archivo.leer(pos);

    system("cls");
    int contrasenia;
    cout<<"Hola"<<aux.getNombre()<<" "<<aux.getApellido()<<endl;

    while(contrasenia!=0){

     cout<<"Ingrese su contraseña"<<endl;
    cin>>contrasenia;


    if(contrasenia==aux.getContrasenia()){
        return aux;
    }else{
        cout<<"Contraseña incorrecta"<<endl;
    }


    }




 }


