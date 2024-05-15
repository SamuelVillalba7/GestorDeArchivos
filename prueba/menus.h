#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "ProductoManager.h"
#include "VentaManager.h"
#include "DetalleVentaManager.h"
#include "Usuario.h"
#include "UsuarioManager.h"

using namespace std;

void comprar();
void listarDetallesVenta(int idVenta);

void menuStock();
void menuVentas();

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

    Usuario usuario;
    UsuarioManager um;
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
            int sector;
            usuario=um.iniciarSesion();
            sector=usuario.getSector();

            if(sector==1){
                menuStock();
            }else if(sector==2){
                menuVentas();
            }
        break;

        case 2:
            um.cargar();
        break;

        case 0:
            return;
        break;

        }
    system("pause");
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
    cout<<"0)SALIR"<<endl;
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
    cout<<"0)SALIR"<<endl;
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

    cout<<"0)SALIR"<<endl;
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
