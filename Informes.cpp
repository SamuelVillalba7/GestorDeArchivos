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
        cout << "4) INFORMES DE CATEGORIAS" << endl;
        cout << "5) INFORMES DE SUCURSALES" << endl;
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

            case 4:
                {
                    consultasCategoria();
                }
                break;

            case 5:
                {
                    consultasSucursal();
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
        cout << "3) LISTAR VENTA POR ID" << endl;
        cout << "4) LISTAR TODAS LAS VENTAS" << endl;
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
                    vm.listarPorID();
                }
            case 4:
                {
                    vm.listarTodos();
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




void InformesManager::consultasCategoria(){
    int opc;
    CategoriaManager cm;
    while(true){
        system("cls");
        cout << "  CONSULTAS DE CATEGORIA" << endl;
        cout << "---------------------------" << endl;
        cout << "1) CATEGORIA QUE MAS SE VENDIO" << endl;
        cout << "2) CATEGORIA QUE MENOS SE VENDIO" << endl;
        cout << "3) CATEGORIA QUE MAS GANANCIAS GENERO" << endl;
        cout << "4) CATEGORIA QUE MENOS GANANCIAS GENERO" << endl;
        cout << "5) CANTIDAD DE PRODUCTOS VENDIDOS POR CATEGORIA" << endl;
        cout << "6) CUANTA GANANCIA RECAUDO CADA CATEGORIA" << endl;
        cout << "7) CATEGORIAS QUE SUPERARON X GANANCIA" << endl;
        cout << "8) CATEGORIAS QUE NO SUPERARON X GANANCIA" << endl;
        cout << "9) CATEGORIAS QUE SUPERARON X VENTAS" << endl;
        cout << "10) CATEGORIAS QUE NO SUPERARON X VENTAS" << endl;
        cout << "11) VENTAS DE CATEGORIA POR ID" << endl;
        cout << "12) GANANCIAS DE CATEGORIA POR ID" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                   cm.masVendida();
                }
                break;
            case 2:
                {
                    cm.menosVendida();
                }
                break;
            case 3:
                {
                   cm.generoMasGanancias();
                }
                break;
            case 4:
                {
                   cm.generoMenosGanancias();
                }
                break;

            case 5:
                {
                   cm.ventasPorCategoria();
                }
                break;

            case 6:
                {
                   cm.recaudadoPorCategoria();
                }
                break;

            case 7:
                {
                   cm.superoGanancias();
                }
                break;

            case 8:
                {
                   cm.noSuperoGanancias();
                }
                break;

            case 9:
                {
                   cm.superoVentas();
                }
                break;

            case 10:
                {
                   cm.noSuperoVentas();
                }
                break;

            case 11:
                {
                   cm.ventaPorId();
                }
                break;

             case 12:
                {
                   cm.gananciaPorId();
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





void InformesManager::consultasSucursal(){
    int opc;
    SucursalManager sm;
    while(true){
        system("cls");
        cout << "  CONSULTAS DE EMPLEADO" << endl;
        cout << "---------------------------" << endl;
        cout << "1) GANANCIA DE SUCURSAL POR ID" << endl;
        cout << "2) GANANCIA DE CADA SUCURSAL" << endl;
        cout << "3) CUAL SUCURSAL GENERO MAS GANANCIA" << endl;
        cout << "4) CUAL SUCURSAL GENERO MENOS GANANCIA" << endl;
        cout << "5) CUALES SUCURSALES SUPERO X GANANCIA" << endl;
        cout << "6) CUALES SUCURSALES NO SUPERO X GANANCIA" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opc;
        system("cls");

        switch(opc){
            case 1:
                {
                    sm.gananciaPorId();
                }
                break;
            case 2:
                {
                    sm.gananciasPorSucursal();
                }
                break;
            case 3:
                {
                    sm.generoMasGanancias();
                }
                break;
            case 4:
                {
                    sm.generoMenosGanancias();
                }
                break;

            case 5:
                {
                    sm.superoGanancia();
                }
                break;
            case 6:
                {
                    sm.noSuperoGanancia();
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
