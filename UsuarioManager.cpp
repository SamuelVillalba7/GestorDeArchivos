#include <iostream>
using namespace std;
#include <cstdlib>
#include "UsuarioManager.h"
#include "SucursalManager.h"
#include "ProductoManager.h"
#include "VentaManager.h"
#include "DetalleVentaManager.h"
#include "CierreDeCajaManager.h"
#include "Informes.h"
#include "CategoriaManager.h"
#include "FuncionesExtras.h"
#include "Configuracion.h"
//#include "UsuarioArchivo.h"

void comprar(Usuario usuario);


void UsuarioManager::mostrar(Usuario usuario){
    SucursalManager sm;
    cout<<"Nombre: "<<usuario.getNombre()<<endl;
    cout<<"Apellido: "<<usuario.getApellido()<<endl;
    cout<<"Dni: "<<usuario.getDni()<<endl;
    cout<<"Sucursal: "<<sm.nombrePorId(usuario.getSucursal())<<endl;
    cout<<"Sector: "<<usuario.getSector()<<endl;
    cout<<"Contraseña: "<<usuario.getContrasenia()<<endl;


}
bool UsuarioManager::cargar(){
    Usuario usuario;
    string nombre,apellido;
    int dni,sector,contrasenia,sucursal;
    SucursalManager sm;
    bool repetido = true;

    cout<<"Ingrese:"<<endl;

    cout<<"Nombre: ";
    nombre= pedirFrase();
    usuario.setNombre(nombre);

    cout<<"Apellido: ";
    apellido= pedirFrase();
    usuario.setApellido(apellido);

    cout<<"Dni: ";
    while(repetido){
        fflush(stdin);

        dni= pedirNumero();

        ///dni repetido?
        if (_archivo.existeDNI(dni)) {
            cout << "ingrese nuevo dni: ";
        }
        else{
            repetido = false;
        }
    }

    usuario.setDni(dni);

        cout<<"Ingrese la Sucursal"<<endl;
    cout<<"Si ingresa 0 se listaran las sucursales cargadas"<<endl;

    sucursal= pedirNumero();

    if(sucursal==0){
        cout<<"---------------------"<<endl;
        sm.listarTodos();
        cout<<"---------------------"<<endl;
        sucursal = pedirNumero();
    }
    bool flag=sm.IdDisponible(sucursal);
    while(!flag){
        cout<<"reingrese sucursal"<<endl;
        sucursal= pedirNumero();
        if(sm.IdDisponible(sucursal)){
            flag=true;
        }
    }

    usuario.setSucursal(sucursal);




    cout<<"Sector: (1.Cajero 2.Deposito 3.Encargado)";
    sector = pedirNumero();
    usuario.setSector(sector);


    cout<<"Contraseña: ";
    contrasenia= pedirNumero();
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
   dni= pedirNumero();
   system("cls");
   pos=_archivo.buscarPosicion(dni);

   if(pos>=0){
    Usuario aux;
    aux=_archivo.leer(pos);
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    mostrar(aux);
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl << endl;
   }else{

        cout<<"Dni no registrado"<<endl;

   }

}

void UsuarioManager::listarPorNombre(){
    string nombre;
    int cant,x;
    bool coincidencia = false;

    cout << "Ingrese el nombre a consultar: ";
    nombre= pedirFrase();
    system("cls");
    cant=_archivo.contarRegistros();
    Usuario aux;
    cout<<"-------------------------"<<endl;
    cout<<"-------------------------"<<endl;
    for(x=0;x<cant;x++){
        aux=_archivo.leer(x);
        if(nombre == aux.getNombre()){
            mostrar(aux);
            coincidencia = true;
            cout<<"-------------------------"<<endl;
            cout<<"-------------------------"<<endl;
        }
    }
    if(!coincidencia){
        cout << endl << "Sin coincidencias encontradas." << endl << endl;
        cout<<"-------------------------"<<endl;
        cout<<"-------------------------"<<endl;
    }
}

void UsuarioManager::listarPorRol(){
    int rol;
    int cant,x;
    bool coinc = false;

    cout << "Ingrese el rol a consultar: " << endl;
    cout << "1) Cajero" << endl;
    cout << "2) Operario" << endl;
    cout << "3) Encargado" << endl;
    rol = pedirNumero();
    system("cls");
    if(rol <=0 || rol >3){
        cout << "ROL INVALIDO" << endl;
    }
    else{

        cant=_archivo.contarRegistros();
        Usuario aux;
        switch(rol){
        case 1:
            {
                cout << "Empleados del sector de compras: " << endl;
            }
        case 2:
            {
                cout << "Empleados del sector de deposito:" << endl;
            }
        case 3:
            {
                cout << "Encargados:" << endl;
            }
        }
        cout<<"-------------------------"<<endl;
        cout<<"-------------------------"<<endl;
        for(x=0;x<cant;x++){
            aux=_archivo.leer(x);
            if(rol == aux.getSector()){
                mostrar(aux);
                coinc = true;
                cout<<"-------------------------"<<endl;
                cout<<"-------------------------"<<endl;
            }
        }
        //coincidencia(coincidencia);
    }
}

 Usuario UsuarioManager::iniciarSesion(){

    int dni,pos;
    cout<<"Ingrese su dni"<<endl;
    dni = pedirNumero();


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

     cout<<"Ingrese su contraseña"<<endl;
    contrasenia = pedirNumero();


    if(contrasenia==aux.getContrasenia()){
        cout<<"Contraseña correcta"<<endl;
        return aux;
    }else{
        cout<<"Contraseña incorrecta"<<endl;
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
        opc  = pedirNumero();


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
    InformesManager im;
    SucursalManager sm;
    CategoriaManager cam;
    Configuracion c;
    ProductoManager p;

    int opcion, aux;
    while (true){
        system("cls");
        cout << "MENU ENCARGADO" << endl;
        cout << "----------------" << endl;
        cout << "1) MENU CIERRE DE CAJA" << endl;
        cout << "2) MENU CATEGORIAS" << endl;
        cout << "3) MENU SUCURSALES" << endl;
        cout << "4) MENU PRODUCTOS" << endl;
        cout << "5) LISTADO DE INFORMES Y CONSULTAS" << endl;
        cout << "6) PRODUCTIVIDAD DE EMPLEADOS DE CAJA" << endl;
        cout << "7) PRODUCTIVIDAD DE EMPLEADOS DE STOCK" << endl;
        cout << "8) MENU CONFIGURACION" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        opcion = pedirNumero();
        system("cls");

        switch(opcion){

            case 1:
                {
                   cm.menu();
                }
                break;
            case 2:
                {
                   cam.menu();
                }
                break;
            case 3:
                {
                   sm.menu();
                }
                break;

            case 4:
                {
                   p.menu();
                }
                break;


            case 5:
                {
                    im.menuInformes();
                }
                break;

                case 8:
                {
                    c.menuPrincipal();
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
    cout<<"6)REALIZAR CIERRE DE CAJA"<<endl;
    cout<<"0)SALIR"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    x = pedirNumero();
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
        cout << "6) ELIMINAR PRODUCTO" <<endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        opcion = pedirNumero();
        system("cls");

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

            case 5:
                {
                   pm.modificarPrecio();
                }
            break;


            case 6:
                {
                   pm.bajaLogica();
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


