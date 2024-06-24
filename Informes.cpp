#include <iostream>

using namespace std;
#include "Informes.h"

//Menus:

void InformesManager::menuInformes(){
    int opc;

    while(true){
        system("cls");
        cout << "  INFORMES Y CONSULTAS:" << endl;
        cout << "---------------------------" << endl;
        cout << "1) CONSULTAS DE EMPLEADO" << endl;
        cout << "2) CONSULTAS DE STOCK" << endl;
        cout << "3) INFORMES DE VENTAS" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                    consultasEmpleados();
                }
                break;
            case 2:
                {
                    consultasStock();
                }
                break;
            case 3:
                {
                    consultasVenta();
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


void InformesManager::consultasEmpleados(){
    int opc;
    UsuarioManager um;
    while(true){
        system("cls");
        cout << "  CONSULTAS DE EMPLEADO" << endl;
        cout << "---------------------------" << endl;
        cout << "1) CONSULTAR POR DNI" << endl;
        cout << "2) CONSULTAR POR NOMBRE" << endl;
        cout << "3) CONSULTAR POR ROL" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                    um.listarPorDni();
                }
                break;
            case 2:
                {
                    um.listarPorNombre();
                }
                break;
            case 3:
                {
                    um.listarPorRol();
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

void InformesManager::consultasStock(){
    int opc;
    ProductoManager pm;
    while(true){
        system("cls");
        cout << "  CONSULTAS DE STOCK" << endl;
        cout << "---------------------------" << endl;
        cout << "1) PRODUCTOS CON STOCK 0" << endl;
        cout << "2) PRODUCTOS CON STOCK MENOR A X CANTIDAD" << endl;
        cout << "3) PRODUCTOS CON STOCK MAYOR A X CANTIDAD" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                    pm.listarStock0();
                }
                break;
            case 2:
                {
                    pm.listarStockMenor();
                }
                break;
            case 3:
                {
                    pm.listarStockMayor();
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

void InformesManager::consultasVenta(){
    int opc;
    VentaManager vm;
    CierreDeCajaManager cm;
    while(true){
        system("cls");
        cout << "  INFORMES DE VENTA" << endl;
        cout << "---------------------------" << endl;
        cout << "1) TOTAL RECAUDADO EN X FECHA" << endl;
        cout << "2) TOTAL RECAUDADO ESTE MES" << endl;
        cout << "3) " << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                    vm.recaudacionPorDia();
                }
            break;
            case 2:
                {
                    cm.facturadoPorMes();
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

