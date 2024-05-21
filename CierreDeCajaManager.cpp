#include <iostream>
using namespace std;
#include "CierreDeCajaManager.h"
#include "SucursalManager.h"



void CierreDeCajaManager::mostrar(CierreDeCaja cierreDeCaja){

    SucursalManager sm;

    cout<<"El id es : "<<cierreDeCaja.getId()<<endl;
    cout<<"La sucursal es : "<<sm.nombrePorId(cierreDeCaja.getIdSucursal())<<endl;
    cout<<"El dni del empleado es : "<<cierreDeCaja.getDniEmpleado()<<endl;
    cout<<"La facturacion fue : $"<<cierreDeCaja.getFacturacion()<<endl;
    cout<<"Fecha : "<<cierreDeCaja.getFecha().toString()<<endl;
    cout<<"Horario : "<<cierreDeCaja.getHora().toString()<<endl;

    if(cierreDeCaja.getVerificado()){

        cout<<"La diferencia fue : $"<<cierreDeCaja.getDiferencia()<<endl;
        cout<<"Fue verificado por el encargado"<<endl;

    }else{

        cout<<"Todavia no fue verificado por el encargado"<<endl;

    }



}

void CierreDeCajaManager::listarPorID(){
    int id;
    cout << "ID de Cierre De Caja a buscar: ";
    cin >> id;

    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0){
        CierreDeCaja aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
        cout << "No existe tal ID CierreDeCaja." << endl;
    }

}





void CierreDeCajaManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
       cout<<endl<<endl;
    }
}


 bool CierreDeCajaManager::IdDisponible(int id){
   if( _archivo.buscarPosicion(id)==-1){
    return false;
   }else{
    return true;
   }

}


void CierreDeCajaManager::VerificarCierres(){
    int id,pos;
    CierreDeCaja cierre;
    cout<<"Ingrese el id del cierre de caja para verificar"<<endl;
    cin>>id;

    // si id es 0 que se muestren los cierres de ese dia sin verificar
    pos=_archivo.buscarPosicion(id);

    if(pos==-1){
        cout<<"Cierre de caja inexistente"<<endl;
        return ;
    }
    cierre=_archivo.leer(pos);

    mostrar(cierre);
    cout<<endl<<endl;

    cout<<"La facturacion concuerda con el dinero en la caja? (1.si 2.no)"<<endl;
    int opc;
    cin>>opc;

    if(opc==1){

        cierre.setVerificado(true);
        _archivo.modificar(cierre,pos);
    }
    else{

        cout<<"Cuanta es la diferencia?"<<endl;
        int diferencia;
        cin>>diferencia;


        cierre.setDiferencia(diferencia);
         cierre.setVerificado(true);
         _archivo.modificar(cierre,pos);

    }



}


void CierreDeCajaManager::menu(){

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
                   //cargar();
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


