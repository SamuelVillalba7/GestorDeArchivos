#include <iostream>
using namespace std;


#include "DetalleVentaManager.h"





void DetalleVentaManager::mostrar(DetalleVenta aux){

    cout<<"El id de venta es: "<<aux.getIdVenta()<<endl;
    cout<<"El id de producto es : "<<aux.getIdProducto()<<endl;
    cout<<" Horario es : " ;
    cout<<endl;


}

void DetalleVentaManager::listarPorID(){

    int id;
    cout << "ID de Venta a buscar: ";
    cin >> id;

    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0){
        DetalleVenta aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
        cout << "No existe tal ID producto." << endl;
    }

}



int DetalleVentaManager::contarRegistrosPorId(int idVenta){

    int x,cont=0,cant=_archivo.contarRegistros();
    DetalleVenta aux;
    for(x=0;x<cant;x++){

        aux=_archivo.leer(x);
        if(aux.getIdVenta()==idVenta){

            cont++;
        }

    }

    return cont;

}

int* DetalleVentaManager::cargarVector(int* vec,int idVenta){

    int  x,cont=0, registros= _archivo.contarRegistros();
    DetalleVenta aux;

    for(x=0;x<registros;x++){

        aux=_archivo.leer(x);
        int id=aux.getIdVenta();

        if(id==idVenta){
            vec[cont]=aux.getIdProducto();
            cont++;
        }
    }

    return vec;
}



void DetalleVentaManager::mostrarRegistrosPorId(int idVenta){

    int x,cant=_archivo.contarRegistros();
    DetalleVenta aux;

    for(x=0;x<cant;x++){

        aux=_archivo.leer(x);
        if(aux.getIdVenta()==idVenta){

            ;
        }

    }


}


/*

int cargarVectorDinamico(int idVenta){


    int *vec;
    int cant;

    cant=contarRegistrosPorId(idVenta);
    vec= new int(cant);


    cargarDinamico(*vec,cant,idVenta);

    delete vec;


}

 void cargarDinamico(int *vec,int cant, int idVenta){

    int  x,cont=0;registros= contarRegistros;
    DetalleVenta aux;


    for(x=0;x<registros;x++){

        aux=leer(x);
        int id=aux.getIdVenta();

        if(id==idVenta){

            vec[cont]=aux;

            if(cont==cant){
                break;
            }

            cont++;

        }

    }

 }




 */






void DetalleVentaManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
    }
}





void DetalleVentaManager::menu(){

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU DETALLEVENTAS" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVA VENTA" << endl;
        cout << "2) LISTAR VENTAS" << endl;
        cout << "3) LISTAR VENTAS x ID" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {

                }
                break;
            case 2:
                {
                   listarTodos();
                }
                break;
            case 3:
                {
                    int id;
                    cout<<"ingrese id"<<endl;
                    cin>>id;
                   mostrarRegistrosPorId(id);
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
