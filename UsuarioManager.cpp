#include <iostream>
using namespace std;
#include <cstdlib>
#include "UsuarioManager.h"
#include "SucursalManager.h"
#include "ProductoManager.h"
#include "VentaManager.h"
#include "DetalleVentaManager.h"
#include "CierreDeCajaManager.h"

void comprar(Usuario usuario);



void UsuarioManager::mostrar(Usuario usuario){
    SucursalManager sm;
    cout<<"Nombre: "<<usuario.getNombre()<<endl;
    cout<<"Apellido: "<<usuario.getApellido()<<endl;
    cout<<"Dni: "<<usuario.getDni()<<endl;
    cout<<"Sucursal: "<<sm.nombrePorId(usuario.getSucursal())<<endl;
    cout<<"Sector: "<<usuario.getSector()<<endl;
    cout<<"Contrase�a: "<<usuario.getContrasenia()<<endl;


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




    cout<<"Sector: (1.Cajero 2.Deposito 3.Encargado)";
    cin>>sector;
    usuario.setSector(sector);


    cout<<"Contrase�a: ";
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

     cout<<"Ingrese su contrase�a"<<endl;
    cin>>contrasenia;


    if(contrasenia==aux.getContrasenia()){
        cout<<"Contrase�a correcta"<<endl;
        return aux;
    }else{
        cout<<"Contrase�a incorrecta"<<endl;
    }


    }
 }






void UsuarioManager::menuInicio(){

    Usuario usuario;
    int opc;

    while(true){
        system("cls");
        cout<<"--------------------------------------"<<endl;
        cout<<"1)INICIAR SESION"<<endl;
        cout<<"2)REGISTRARSE"<<endl;
        cout<<"0)SALIR"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"INGRESE OPCION"<<endl;
        cin>>opc;


        system("cls");

        switch(opc){

        case 1:
            usuario=iniciarSesion();
            menuSegunSector(usuario);
        break;

        case 2:
            cargar();
        break;

        case 0:
            return;
        break;

        }
    system("pause");
    }

}



 void UsuarioManager::menuSegunSector(Usuario usuario){

    int sector=usuario.getSector();

    switch(sector){
        case 1:
            menuCajero(usuario);
        break;

        case 2:

            menuDeposito(usuario);
        break;

        case 3:
            menuEncargado(usuario);
        break;


    }


 }





 void UsuarioManager::menuEncargado(Usuario usuario){
    CierreDeCajaManager cm;
    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU ENCARGADO" << endl;
        cout << "----------------" << endl;
        cout << "1) VERIFICAR CIERRES DE CAJA" << endl;
        cout << "2) INFORMES" << endl;
        cout << "3) " << endl;
        cout << "4) PRODUCTIVIDAD DE EMPLEADOS DE CAJA" << endl;
        cout << "3) PRODUCTIVIDAD DE EMPLEADOS DE STOCK" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                  cm.VerificarCierres();
                }
                break;
            case 2:
                {
                   cm.listarTodos();
                }
                break;
            case 3:
                {

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



void UsuarioManager::menuCajero(Usuario usuario){


int x;
VentaManager vm;
DetalleVentaManager dm;

while(true){
    system("cls");
    cout<<"USUARIO: "<< usuario.getNombre()<<" " << usuario.getApellido()<<endl;
    cout<<"MENU CAJERO "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)REGISTRAR UNA VENTA"<<endl;
    cout<<"2)LISTAR VENTA POR ID"<<endl;
    cout<<"3)LISTAR VENTA CON DETALLE POR ID"<<endl;
    cout<<"4)LISTAR TODAS LAS VENTAS"<<endl;
    cout<<"5)CANTIDAD DE VENTAS"<<endl;

    cout<<"0)SALIR"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){

        case 1:
            comprar(usuario);
        break;

        case 2:
        vm.listarPorID();
        break;

        case 3:
            int id;
            id=vm.listarPorID();
            dm.listarDetallesVenta(id);

        break;

        case 4:
            vm.listarTodos();
        break;

        case 5:
            vm.contarVentasDelDia();
        break;

        case 6:
            vm.cierreDeCaja(usuario);
        break;

        case 0:
        return;
        break;
        }
        system("pause");
    }
}





 void UsuarioManager::menuDeposito(Usuario usuario){

    ProductoManager pm;
    int opcion;
    while (true){
        system("cls");
        cout<<"USUARIO: "<< usuario.getNombre()<<" " << usuario.getApellido()<<endl;
        cout << "MENU PRODUCTOS" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVO PRODUCTO" << endl;
        cout << "2) LISTAR PRODUCTOS" << endl;
        cout << "3) LISTAR PRODUCTO x ID" << endl;
        cout << "4) INGRESA STOCK DE PRODUCTO REGISTRADO" <<endl;
        cout << "5) CAMBIAR PRECIO" <<endl;
        cout << "6 )ELIMINAR PRODUCTO" <<endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    pm.cargar();
                }
                break;
            case 2:
                {
                   pm.listarTodos();
                }
                break;
            case 3:
                {
                   pm.listarPorID();
                }
                break;
            case 4:
                {
                   pm.ingresoStock();
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

