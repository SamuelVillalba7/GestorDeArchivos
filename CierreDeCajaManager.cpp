#include <iostream>
using namespace std;
#include "CierreDeCajaManager.h"
#include "SucursalManager.h"



void CierreDeCajaManager::listarDelDiaSinVerificar(){

    int x,cant;
    cant= _archivo.contarRegistros();
    CierreDeCaja aux;
    Fecha fecha;
    bool flag = false;

    for(x=0;x<cant;x++){
        aux= _archivo.leer(x);


        if(fecha.mismoDia(aux.getFecha())){

            if(flag==false){

            flag=true;
            cout <<aux.getId();


            }else{
                cout <<", "<<aux.getId();
            }



        }


        if(x==cant-1){
             cout <<"."<<endl;
        }


    }

    if(flag==false){
         cout <<"NO HAY INFORMES SIN VERIFICAR DE HOY"<<endl;
    }



}




void CierreDeCajaManager::listarNoVerificados(){

    cout<<"Los informes sin verificar son: "<<endl;
    int x,cant;

    cant=_archivo.contarRegistros();
    CierreDeCaja aux;

    for(x=0;x<cant;x++){
        aux= _archivo.leer(x);

        if(!aux.getVerificado()){
            cout<<"------------------------"<<endl;
            mostrar(aux);
            cout<<"------------------------"<<endl;

        }

    }
}
void CierreDeCajaManager::listarVerificados(){

    cout<<"Los informes sin verificar son: "<<endl;
    int x,cant;

    cant=_archivo.contarRegistros();
    CierreDeCaja aux;

    for(x=0;x<cant;x++){
        aux= _archivo.leer(x);

        if(aux.getVerificado()){
            cout<<"------------------------"<<endl;
            mostrar(aux);
            cout<<"------------------------"<<endl;

        }

    }

}

 int CierreDeCajaManager::cantidadPorMes(int mes){
     int x,cant,cont=0;
     cant=_archivo.contarRegistros();
      CierreDeCaja aux;
     for(x=0;x<cant;x++){

        aux=_archivo.leer(x);

        if(aux.getFecha().getMes()==mes){

            cont++;
        }


     }

     return cont;
 }

  void CierreDeCajaManager::cargarVecPorMes(int mes,CierreDeCaja *vec){

    int cant,x,cont=0;

    cant=_archivo.contarRegistros();
    CierreDeCaja aux;


    for(x=0;x<cant;x++){

        aux=_archivo.leer(x);

        if(aux.getFecha().getMes()==mes){
             vec[cont]=aux;
             cont++;

        }



     }

  }





void CierreDeCajaManager::facturadoPorMes(){
    cout<<"ingrese el mes (en numero) "<<endl;



    int cant,x;
    CierreDeCaja *vec;
    cant=cantidadPorMes(6);

    vec=new CierreDeCaja[cant];

    if(vec==NULL){
        return;
    }


    cargarVecPorMes(6,vec);

    int acum=0;
    for(x=0;x<cant;x++){

        acum+= vec[x].getFacturacion();


    }


    cout<<"Lo facturado este mes fue : $"<<acum<<endl;






    delete []vec;



}




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

    cout<<"Si ingresa 0 se listaran los cierres sin verificar"<<endl;

    cin>>id;

    if(id==0){


        cout<<"---------------------"<<endl;
        listarNoVerificados();
        cout<<"---------------------"<<endl;
        cin>>id;
    }
    bool flag=IdDisponible(id);
    while(!flag){
        cout<<"reingrese id"<<endl;
        cin>>id;
        if(IdDisponible(id)){
            flag=true;
        }
    }


    // si id es 0 que se muestren los cierres de ese dia sin verificar
    pos=_archivo.buscarPosicion(id);

    if(pos==-1){
        cout<<"Cierre de caja inexistente"<<endl;
        return ;
    }
    cierre=_archivo.leer(pos);

    system("cls");
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
        cout << "MENU CIERRE DE CAJA" << endl;
        cout << "----------------" << endl;
        cout << "1) LISTAR CIERRES DE CAJA" << endl;
        cout << "2) LISTAR CIERRES DE CAJA SIN VERIFICAR" << endl;
        cout << "3) LISTAR CIERRES DE CAJA VERIFICADOS" << endl;
        cout << "4) VERIFICAR CIERRES DE CAJA POR ID" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                    listarTodos();
                }
                break;
            case 2:
                {
                   listarNoVerificados();
                }
                break;
            case 3:
                {
                   listarVerificados();
                }
                break;
            case 4:
                {
                    VerificarCierres();
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


