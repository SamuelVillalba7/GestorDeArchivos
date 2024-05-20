#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "ProductoManager.h"
#include "VentaManager.h"
#include "DetalleVentaManager.h"
#include "Usuario.h"
#include "UsuarioManager.h"

using namespace std;

void comprar(int sucursal);
void listarDetallesVenta(int idVenta);

void menuStock();
void menuVentas(int sucursal);

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
        //   menuStock();
        break;

        case 2:
          //  menuVentas();
        break;

        case 3:
        //  menuUsuario();
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


/*
void menuPrincipal(){

int x;
while(true){
    system("cls");
    cout<<"MENU DE ENCARGADO"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1) MENU DE STOCK"<<endl;
    cout<<"2) MENU DE VENTAS"<<endl;
    cout<<"3) INFORMES"<<endl;
    cout<<"4) USUARIOS"<<endl;
    cout<<"5) CONFIGURACION"<<endl;

    cout<<"0)SALIR"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE OPCION"<<endl;
    cin>>x;
    system("cls");

    switch(x){
        case 1:
        //   menuStock();
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


*/



#endif // MENUS_H_INCLUDED
