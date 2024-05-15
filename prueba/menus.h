#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "ProductoManager.h"
#include "VentaManager.h"
#include "DetalleVentaManager.h"

using namespace std;

void comprar();
void listarDetallesVenta(int idVenta);



void menuConfiguracion(){

int x;

while(true){
    system("cls");
    cout<<"MENU CONFIGURACION "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)REALIZAR COPIA DE SEGURIDAD"<<endl;
    cout<<"2)RESTAURAR COPIA DE SEGURIDAD"<<endl;
    cout<<"3)EXPORTAR DATOS"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
         //   ingresarProducto();
        break;

        case 2:
         //    ingresarStock();
        break;

        case 3:
        //     cambiarPrecio();
        break;

        case 4:
        //     listarProductos();
        break;

        case 0:
            return;
        break;
        }
    }
}





void menuUsuario(){

int x;


while(true){
    system("cls");
    cout<<"MENU USUARIO"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)CREAR USUARIO"<<endl;
    cout<<"2)LISTAR USUARIOS"<<endl;
    cout<<"2)LISTAR USUARIO POR DNI"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
         //   ingresarProducto();
        break;

        case 2:
         //    ingresarStock();
        break;

        case 3:
        //     cambiarPrecio();
        break;

        case 4:
        //     listarProductos();
        break;

        case 0:
            return;
        break;
        }
    }
}





void menuUsuario(){

    Usuario usuario;
    UsuarioManager um;
    int opc;
    cout<<"1)INICIAR SESION"<<endl;
    cout<<"2)REGISTRARSE"<<endl;
    cin>>opc;

    switch(opc){

    case 1:
        int sector;
        usuario=um.iniciarSesion();
        sector=usuario.getSector();

        if(sector==1){

        }else if(sector==2){

        }
        else{

        }



    break;

    case 2:
        um.cargar();
    break;

    }









int x;


while(true){
    system("cls");
    cout<<"INICIO DE SESION"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)CREAR USUARIO"<<endl;
    cout<<"2)LISTAR USUARIOS"<<endl;
    cout<<"2)LISTAR USUARIO POR DNI"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
         //   ingresarProducto();
        break;

        case 2:
         //    ingresarStock();
        break;

        case 3:
        //     cambiarPrecio();
        break;

        case 4:
        //     listarProductos();
        break;

        case 0:
            return;
        break;
        }
    }
}








void menuVentas(){

int x;
VentaManager vm;
DetalleVentaManager dm;

while(true){
    system("cls");
    cout<<"MENU VENTAS "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)REGISTRAR UNA VENTA"<<endl;
    cout<<"2)LISTAR VENTA POR ID"<<endl;
    cout<<"3)LISTAR VENTA CON DETALLE POR ID"<<endl;
    cout<<"4)LISTAR TODAS LAS VENTAS"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
          comprar();
        break;

        case 2:
        vm.listarPorID();
        break;

        case 3:
            int id;
            id=vm.listarPorID();
         listarDetallesVenta(id);

        break;

        case 4:
        vm.listarTodos();
        break;

        case 0:
        return;
        break;
        }
        system("pause");
    }
}



void menuStock(){

int x;
ProductoManager aux;
while(true){
    system("cls");
    cout<<"MENU STOCK"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)REGISTRAR NUEVO PRODUCTO"<<endl;
    cout<<"2)LISTAR PRODUCTO POR ID"<<endl;
    cout<<"3)LISTAR TODOS LOS PRODUCTOS"<<endl;
    cout<<"4)INGRESA STOCK DE PRODUCTO REGISTRADO"<<endl;
    cout<<"5)CAMBIAR PRECIO"<<endl;
    cout<<"6)ELIMINAR PRODUCTO"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");


    switch(x){
        case 1:
            aux.cargar();

        break;

        case 2:
            aux.listarPorID();

        break;

        case 3:
            aux.listarTodos();

        break;

        case 4:
        //     aux.ingresoStock();
        break;

        case 5:
        //     aux.cambiarPrecio();
        break;

        case 6:
        //     aux.bajaLogica();
        break;

        case 0:
            return;
        break;
        }

        system("pause");

    }
}






void menuPrincipal(){

int x;


while(true){
    system("cls");
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1)MENU STOCK"<<endl;
    cout<<"2)MENU VENTAS"<<endl;
    cout<<"3)INFORMES"<<endl;
    cout<<"4)CONFIGURACION"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
           menuStock();
        break;

        case 2:
            menuVentas();
        break;

        case 3:
          menuUsuario();
        break;

        case 4:
            menuConfiguracion();
        break;

        case 0:
        return;
        break;


    }
}

}


#endif // MENUS_H_INCLUDED
