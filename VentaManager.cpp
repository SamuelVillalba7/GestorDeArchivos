#include <iostream>
#include <cstring>
using namespace std;


#include "VentaManager.h"
#include "SucursalManager.h"
#include "CierreDeCaja.h"
#include "CierreDeCajaArchivo.h"
#include "FuncionesExtras.h"



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

    SucursalManager sm;

    cout<<"El id es : "<<aux.getId()<<endl;
    cout<<"La precio es : $"<<aux.getPrecio()<<endl;
    cout<<"Sucursal : " <<sm.nombrePorId(aux.getSucursal())<<endl;

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

    mostrar(id);


    return id;

}


void VentaManager::mostrar(int id){

    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0){
        Venta aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
        cout << "No existe tal ID producto." << endl;
    }
}






void VentaManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
    }
}

int VentaManager::contarVentasDelDia(){
    Fecha hoy;
    int x,cont=0,cant=_archivo.contarRegistros();
    Venta aux;
    for(x=0;x<cant;x++){

        aux=_archivo.leer(x);
        if(aux.getFecha().mismoDia(hoy)){
            cont++;
        }


        }
    return cont;
}

void VentaManager::recaudacionPorDia(){
    Fecha aux;
    bool coinc;
    float recaudacion = 0;
    cout << "Ingrese una fecha para conocer la recaudacion total del dia." << endl << endl;
    aux.cargar();
    system("cls");
    for(int i=0; i<_archivo.contarRegistros(); i++){
        Venta auxV = _archivo.leer(i);
        if(aux.mismoDia(auxV.getFecha())){
            coinc = true;
            recaudacion += auxV.getPrecio();
        }
    }
    if(!coinc){
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "No hubieron ventas generadas en el dia de la fecha." << endl;
        cout << "-----------------------------" << endl;
    }
    else{
        cout << "----------------------------------------------------" << endl;
        cout << "La recaudacion total del dia ";
        aux.mostrar();
        cout << " fue de: $" << recaudacion << endl;
        cout << "----------------------------------------------------" << endl;
    }
}




void VentaManager::cargarVecVentaDelDia(int* vec){

    Fecha hoy;

    int x,cont=0,cant=_archivo.contarRegistros();

    Venta aux;
    for(x=0;x<cant;x++){

        aux=_archivo.leer(x);

        if(aux.getFecha().mismoDia(hoy)){
            vec[cont]=aux.getId();
            cont++;
        }
    }
}


void VentaManager::cierreDeCaja(Usuario usuario){

    int *vec,cant,x;
    int dni=usuario.getDni(), sucursal=usuario.getSucursal();

    cant=contarVentasDelDia();
    vec=new int[cant];

    if(vec==NULL){
        cout<<"error con memoria"<<endl;
        return;
    }
    cargarVecVentaDelDia(vec);
    Venta aux;

    int pos;
    float acum=0;
    float ganancia=0;
    for(x=0;x<cant;x++){

    pos=_archivo.buscarPosicion(vec[x]);
    aux=_archivo.leer(pos);

    if(aux.getDniEmpleado()==dni){

        acum+=aux.getPrecio();
        ganancia+=aux.getGanancia();
    }

    }

    cout<<"Lo facturado fue "<< acum <<endl;

    CierreDeCajaArchivo archivo;
    int id=archivo.generarId();
    CierreDeCaja cierre(id,sucursal,dni,acum,ganancia);
    bool guardo =archivo.guardar(cierre);

    if(guardo){
        cout<<"Guardado y enviado al encargado"<<endl;
    }
    else{
        cout<<"Hubo un error"<<endl;
    }




    delete []vec;


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
