#include <iostream>
using namespace std;
#include <cstdlib>
#include "ProductoManager.h"
#include "SucursalManager.h"
#include "FuncionesExtras.h"
#include "CategoriaManager.h"


bool ProductoManager::cargar(){
    Producto aux;
    int id,b,categoria;
    float c,d;
    string n, nombre;
    SucursalManager sm;
    CategoriaManager cm;

    bool repetido = true;
    //si es igual a -1 se termina la carga;

    system("CLS");

    id=_archivo.generarId();
    //cout<<"El id es: "<<id<<endl;

    aux.setId(id);

    mostrar(aux);

    ///verificacion nombre repetido

    cout<<"Ingrese NOMBRE del producto:" << endl << "(o '-1' para salir de la opcion de carga)" << endl;
    while(repetido){
    fflush(stdin);

    ///
    getline(cin,n);
    nombre = fraseMayus(n); //convierte el nombre en mayus;

    if (n == "-1") { //en TODO momento; en caso de ingresar un valor menor igual a -1, se cancela la operacion
        cout << "Operacion de carga cancelada" << endl;
        return false;
    }

    if (_archivo.existeNombre(nombre)) {
        system("CLS");
        mostrar(aux);
        cout << "El nombre del producto ya existe." << endl << "Por favor, ingrese un nombre diferente:" << endl << "(o '-1' para salir de la opcion de carga)" << endl;
    }
    else{
        repetido = false;
    }
    }
    aux.setNombre(nombre);

    system("CLS");
    mostrar(aux);
    cout << endl;

    //categoria
    cout << "Ingrese la Categoria"<<endl;
    cout<<"Si ingresa 0 se listaran las categorias cargadas"<<endl;
   cin>>categoria;

    if(categoria==0){


        cout<<"---------------------"<<endl;
        cm.listarTodos();
        cout<<"---------------------"<<endl;
        cin>>categoria;
    }
    bool flag=cm.IdDisponible(categoria);
    while(!flag){
        cout<<"reingrese categoria"<<endl;
        cin>>categoria;
        if(cm.IdDisponible(categoria)){
            flag=true;
        }
    }





    aux.setCategoria(categoria);
    if(exitCarga(categoria)) return false;



    system("CLS");
    mostrar(aux);
    cout << endl;

    cout<<"Ingrese Stock"<<endl;
    cin>>b;
    if(exitCarga(b)) return false;
    aux.setStock(b);

    system("CLS");
    mostrar(aux);
    cout << endl;

    cout<<"Ingrese precio de compra"<<endl;
    cout<<"$";
    cin>>c;

    if(exitCarga(c)) return false;
    aux.setPrecioCompra(c);

    system("CLS");
    mostrar(aux);
    cout << endl;

    cout<<"Ingrese precio de venta"<<endl;
    cout<<"Si ingresa un 0 el precio de venta sera un 75% mas que el de la compra"<<endl;
    cout<<"$";
    cin>>d;
    if(exitCarga(d)) return false;

    //*al poner 0 se guarda el valor de compra mas el 75%*/

    if (d==0){
        d=aux.getPrecioCompra()*1.75;
        aux.setPrecioVenta(d);
    }else{
        aux.setPrecioVenta(d);
    }

    system("CLS");
    mostrar(aux);
    cout << endl;

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


    cout<<"El id es : ";
    guionCero(producto.getId()); //GUIONCERO ES UNA FUNCION ESTETICA QUE REEMPLAZA 0 por '-'
    cout << endl;

    cout << "El Nombre es : " << producto.getNombre() << endl;

    cout << "La categoria es : ";
    guionCero(producto.getCategoria());
    ///aca meter un switch de categoria para cout
    cout << endl;

    cout<<"La cantidad stock es : ";
    guionCero(producto.getStock());
    cout << endl;

    cout<<"El Precio de Compra es : $";
    guionCero(producto.getPrecioCompra());
    cout << endl;

    cout<<"El Precio de Venta es : $";
    guionCero(producto.getPrecioVenta());
    cout << endl << "---------------------------" << endl;


}

void ProductoManager::listarPorID(){

    int pos = ingresarId();
    if (pos >= 0){
        Producto aux = _archivo.leer(pos);
        mostrar(aux);
    }
    else{
         cout<<"Salir de la operacion"<<endl;
    }

}

 void ProductoManager::listarVectorDeId(int *vec,int tam){

    Producto aux;
    int posicion,x,cantidad;

    cout<<"Id" << '\t' << "Nombre" << '\t' << "Precio" <<endl; //agregue los tabs

    for(x=0;x<tam;x++){
        posicion=_archivo.buscarPosicion(vec[x]);
        aux= _archivo.leer(posicion);

        cout<< aux.getId()<< '\t' <<aux.getNombre()<< '\t' << "$" <<aux.getPrecioVenta() <<endl;
    }

 }

void ProductoManager::listarStock0(){
    Producto aux;
    for(int i=0; i<_archivo.contarRegistros(); i++){
        aux = _archivo.leer(i);
        if(aux.getStock() == 0){
            mostrar(aux);
            cout<<endl<<endl;
        }
    }
}

void ProductoManager::listarStockMenor(){
    Producto aux;
    bool coinc;
    int stockM;
    cout << "Listar productos con stock menor a: ";
    cin >> stockM;
    cout << endl;
    for(int i=0; i<_archivo.contarRegistros(); i++){
        aux = _archivo.leer(i);
        if(aux.getStock() < stockM){
            cout << "---------------------------" << endl;
            mostrar(aux);
            cout<<endl;
            coinc = true;
        }
    }
    coincidencia(coinc);
}

void ProductoManager::listarStockMayor(){
    Producto aux;
    bool coinc = false;
    int stockM;
    cout << "Listar productos con stock mayor a: ";
    cin >> stockM;
    cout << endl;
    for(int i=0; i<_archivo.contarRegistros(); i++){
        aux = _archivo.leer(i);
        if(aux.getStock() > stockM){
            cout << "---------------------------" << endl;
            mostrar(aux);
            cout<<endl;
            coinc = true;
        }
    }
    coincidencia(coinc);
}

void ProductoManager::listarTodos(){
    for(int i=0; i<_archivo.contarRegistros(); i++){
       mostrar(_archivo.leer(i));
       cout<<endl<<endl;
    }
}


void ProductoManager::ingresoStock(){

    int stock,stockActual,pos;
    float precioCompra,precioVenta;
    Producto aux;

    pos= ingresarId();

    if(pos == -1){
        cout<<"Salir de la operacion"<<endl;
        return;
    }
    aux=_archivo.leer(pos);

    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    mostrar(aux);
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;


    cout<<"Ingrese la cantidad de stock que ingreso "<<endl;
    cin>>stock;

    if(stock<=0){
        cout<<"Cantidad no valida"<<endl;
        return;
    }

    stockActual=aux.getStock();
        aux.setStock(stock+stockActual);


    cout<<"Ingrese el precio por unidad que ingreso "<<endl;
        cin>> precioCompra ;

        if(precioCompra<=0){
        cout<<"Precio no valido"<<endl;
        }

        aux.setPrecioCompra(precioCompra);

    cout<<"Ingrese el precio de venta por unidad que ingreso "<<endl;
    cout<<"Si ingresa un 0 el precio de venta sera un 75% mas que el de la compra"<<endl;
        cin>> precioVenta;

        if(precioVenta<=-1){
        cout<<"Precio no valido"<<endl;
        }

        if (precioVenta==0){
        precioVenta=aux.getPrecioCompra()*1.75;
        aux.setPrecioVenta(precioVenta);
        }else{
        aux.setPrecioVenta(precioVenta);
        }





      if(_archivo.modificar(aux,pos)){
        cout<<"se aumento correctamente"<<endl;
      }
      else{
            cout<<"no se aumento correctamente"<<endl;


      }


}





    bool ProductoManager::restarStock(int id){

        Producto aux;
        int pos;
        pos=_archivo.buscarPosicion(id);


        aux=_archivo.leer(pos);
        int stock=aux.getStock();

        if(stock>0){
            stock--;

            aux.setStock(stock);
            _archivo.modificar(aux,pos);

            return true;

        }
        else{
            cout<<"No hay stock disponible"<<endl;
            return false;
        }





    }


int ProductoManager::ingresarId(){

    int id, pos;
    cout <<"Ingrese el ID del producto"<<endl;
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



void ProductoManager::bajaLogica(){

    int pos;
    pos= ingresarId();
    Producto aux;
    aux=_archivo.leer(pos);
    if (pos == -1){
         cout<<"Salir de la operacion"<<endl;
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


void ProductoManager::modificarPrecio(){

    int pos;
    pos= ingresarId();

    if (pos == -1){
         cout<<"Salir de la operacion"<<endl;
        return;
    }

    Producto aux;

    aux= _archivo.leer(pos);


    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    mostrar(aux);
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;


    float precioNuevo;
    cout<<"Ingrese el precio nuevo : $"<<endl;
    cin>>precioNuevo;

    if(precioNuevo<=0){
        cout<<"Precio invalido"<<endl;
        return;
    }

    aux.setPrecioVenta(precioNuevo);

    _archivo.modificar(aux,pos);







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
        cout << "4) INGRESA STOCK DE PRODUCTO REGISTRADO" <<endl;
        cout << "5) CAMBIAR PRECIO" <<endl;
        cout << "6) ELIMINAR PRODUCTO" <<endl;
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
            case 4:
                {
                   ingresoStock();
                }
                break;

            case 6:
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



