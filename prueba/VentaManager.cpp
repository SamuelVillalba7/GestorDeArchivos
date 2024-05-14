#include <iostream>
using namespace std;


#include "VentaManager.h"
int VentaManager::generarId(){
    int id;
    id=_archivo.contarRegistros();
    return id+1;

}


Venta VentaManager::cargar(){
    Venta aux;
    int id, formaDePago;
    Fecha fecha;

    id=_archivo.contarRegistros();
    aux.setId(id+1);

    cout<<"El id es :"<< id <<endl;

    cout<<"Ingrese la forma de pago"<<endl;
    cout<<"1. Efectivo   "<< "2.Tarjeta"<<endl;
    cin>>formaDePago;
    aux.setFormaDePago(formaDePago);

     cout<<"Fecha: ";
     fecha.mostrar();
     cout<<endl;
    aux.setFecha(fecha);



    return aux;


}





void VentaManager::mostrar(Venta aux){


    cout<<"El id es : "<<aux.getId()<<endl;
    cout<<"La precio es : $"<<aux.getPrecio()<<endl;

    cout<<"La forma de pago es : ";
    if(aux.getFormaDePago()==1){
        cout<<"Efectivo"<<endl;
    }else{
        cout<<"Tarjeta"<<endl;
    }
    cout<<"La fecha es : " ;
    aux.getFecha().mostrar();

     cout<<"El horario es : " ;
    aux.getHora().mostrar();




    cout<<endl;


}

int VentaManager::listarPorID(){

    int id;
    cout << "ID de Venta a buscar: ";
    cin >> id;
     cout<<endl<<endl;


    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0){
        Venta aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
        cout << "No existe tal ID producto." << endl;
    }
    return id;

}

void VentaManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
    }
}

void VentaManager::menu(){

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU VENTAS" << endl;
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
