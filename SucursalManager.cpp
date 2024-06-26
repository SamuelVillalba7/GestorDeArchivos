#include <iostream>
using namespace std;
#include <cstdlib>
#include "SucursalManager.h"


bool SucursalManager::cargar(){
    cout<<"----------"<<endl;
    cout<<"Sucursal"<<endl;
    cout<<"----------"<<endl;
    Sucursal aux;
    int id;
    string n;
    id=_archivo.generarId();
    cout<<"El id es: "<<id<<endl;

    aux.setId(id);

    fflush(stdin);
    cout<<"Ingrese nombre"<<endl;

    getline(cin,n);

    aux.setNombre(n);
    aux.setEstado(true);


    if(_archivo.guardar(aux)){
        cout<<endl<<"Se guardo correctamente"<<endl;
        return true;
    }
    else{
        cout<<"No se pudo cargar"<<endl;
        return false;
    }


}

void SucursalManager::mostrar(Sucursal sucursal){

    bool estado =sucursal.getEstado();
    if(estado){
    cout<<"El id es : "<<sucursal.getId()<<endl;
    cout<<"El Nombre es : "<<sucursal.getNombre()<<endl;

    }
}

void SucursalManager::listarPorID(){
    int id;
    cout << "ID de Sucursal a buscar: ";
    cin >> id;

    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0){
        Sucursal aux = _archivo.leer(pos);

         bool estado=aux.getEstado();

    if(!estado){
    cout<<"--------------------------"<<endl;
    cout<<"Registro dado de baja"<<endl;
    cout<<"--------------------------"<<endl;
    return;
    }


        mostrar(aux);
    }
    else{
        cout << "No existe tal ID Sucursal." << endl;
    }

}


int SucursalManager::ingresarId(){

    int id, pos;
    cout <<"Ingrese el ID de la sucursal"<<endl;
    cin>> id;


    pos=_archivo.buscarPosicion(id);
    while(pos<0){
        cout<<"ID no registrado"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Ingrese otro id"<<endl;
        cout <<"(Si ingresa -1 saldra de la carga)"<<endl;
        cin>> id;

        if(id == -1){
            return -1;

        }

        pos=_archivo.buscarPosicion(id);

    }

    return pos;

}


void SucursalManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
       cout<<endl<<endl;
    }
}


 bool SucursalManager::IdDisponible(int id){
   if( _archivo.buscarPosicion(id)==-1){
    return false;
   }else{
    return true;
   }

}

string SucursalManager::nombrePorId(int id){
    int pos;
    pos=_archivo.buscarPosicion(id);
    Sucursal sucursal=_archivo.leer(pos);
    return sucursal.getNombre();
}

void SucursalManager::bajaLogica(){

    int pos;
    pos= ingresarId();
    Sucursal aux;
    aux=_archivo.leer(pos);
    if (pos == -1){
         cout<<"Salir de la operacion"<<endl;
        return;
    }


     bool estado=aux.getEstado();

    if(!estado){
    cout<<"--------------------------"<<endl;
    cout<<"Registro dado de baja"<<endl;
    cout<<"--------------------------"<<endl;
    return;
    }

    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    mostrar(aux);
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;

    int opc;
    cout<<"Este producto quiere dar de baja? (1.Si 2.No)"<<endl;
    cin>>opc;

    if(opc==1){

        aux.setEstado(false);
        if(_archivo.modificar(aux,pos)){

            cout<<"Se elimino el registro"<<endl;
        }
        else{
                cout<<"No se pudo eliminar el registro"<<endl;
            }
    }
    else{
        cout<<"No se elimino el registro"<<endl;
    }

}



void SucursalManager::menu(){

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU SUCURSALES" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVA SUCURSAL" << endl;
        cout << "2) LISTAR SUCURSALES" << endl;
        cout << "3) LISTAR SUCURSAL POR ID" << endl;
        cout << "4) ELIMINAR SUCURSAL" <<endl;
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
                   listarPorID();
                }
                break;
            case 4:
                {
                    bajaLogica();
                }
                break;
            case 99:
                cout << _archivo.contarRegistros();
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


