#include <iostream>
using namespace std;
#include <cstdlib>
#include "ProductoManager.h"


bool ProductoManager::cargar(){
    Producto aux;
    int a,b;
    float c,d;
    string n;

    cout<<"Ingrese id"<<endl;
    cin>>a;
    aux.setId(a);

    fflush(stdin);

    cout<<"Ingrese nombre"<<endl;
    getline(cin,n);
    aux.setNombre(n);



    cout<<"Ingrese cantidad"<<endl;
    cin>>b;
    aux.setStock(b);

    cout<<"Ingrese precio de compra"<<endl;
    cout<<"$";
    cin>>c;
    aux.setPrecioCompra(c);

    cout<<"Ingrese precio de venta"<<endl;
    cout<<"$";
    cin>>d;

    /*al poner 0 se guarda el valor de compra mas el 75%*/

    if (d==0){
        d=aux.getPrecioCompra()*1.75;
        aux.setPrecioVenta(d);
    }else{
        aux.setPrecioVenta(d);
    }



    if(_archivo.guardar(aux)){
        cout<<"Se guardo correctamente"<<endl;
        return true;
    }
    else{
        cout<<"No se pudo cargar"<<endl;
        return false;
    }


}

void ProductoManager::mostrar(Producto producto){
    cout<<"El id es : "<<producto.getId()<<endl;
    cout<<"El Nombre es : "<<producto.getNombre()<<endl;
    cout<<"La cantidad stock es : "<< producto.getStock() <<endl;
    cout<<"El Precio de Compra es : $"<<producto.getPrecioCompra() <<endl;
    cout<<"El Precio de Venta es : $"<< producto.getPrecioVenta()<<endl;


}

void ProductoManager::listarPorID(){
    int IDProducto;
    cout << "ID de Producto a buscar: ";
    cin >> IDProducto;

    int pos = _archivo.buscarPosicion(IDProducto);
    if (pos >= 0){
        Producto aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
        cout << "No existe tal ID producto." << endl;
    }

}

 void ProductoManager::listarVecDetalles(int *vec,int tam){

    Producto aux;
    int posicion,x,cantidad;

    cout<<"Id       Nombre        Precio" <<endl;

    for(x=0;x<tam;x++){
        posicion=_archivo.buscarPosicion(vec[x]);
        aux= _archivo.leer(posicion);

        cout<< aux.getId()<<"        "<<aux.getNombre()<<"        $" <<aux.getPrecioVenta() <<endl;
    }

 }





void ProductoManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
       cout<<endl<<endl;
    }
}

void ProductoManager::menu(){

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU PRODUCTOS" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVO PRODUCTO" << endl;
        cout << "2) LISTAR PRODUCTOS" << endl;
        cout << "3) LISTAR PRODUCTO x ID" << endl;
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
