#include <iostream>

using namespace std;

#include "ProductoManager.h"
#include "Producto.h"
#include "menus.h"
#include "Fecha.h"
#include "VentaManager.h"

#include "Venta.h"
#include "VentaArchivo.h"
#include "DetalleVenta.h"
#include "DetalleVentaManager.h"

void comprar();
void listarDetallesVenta(int idVenta);




int main()
{


  menuPrincipal();



    return 0;
}



void comprar(){

    int id=1,precio;

    Producto producto;
    ProductoArchivo productoArchivo;

    DetalleVentaArchivo detalleArchivo;
    VentaManager vm;
    VentaArchivo ventaArchivo;




    cout<<"Ingrese el id de los productos"<<endl;
    cout <<"Ingresando un 0 como id terminara de cargar"<<endl;
    cout <<endl<<endl;
     cout<<"Nombre        "<<"Precio"<<endl;


    int idVenta=vm.generarId();


    while(id>0){


    cin>>id;

    if(id==0){
        continue;
    }

    int pos;
    pos=productoArchivo.buscarPosicion(id);


    if(pos<0){
        cout<<"Producto no existe"<<endl;
        cout<<"Pruebe con otro id"<<endl;

        continue;
    }


    producto= productoArchivo.leer(pos);

    DetalleVenta detalle(idVenta,producto.getId());

    detalleArchivo.guardar(detalle);


    cout<<producto.getNombre()<<"    "<<producto.getPrecioVenta()<<endl;




    precio+=producto.getPrecioVenta();



    //archivo.restarStock();

    cout<<"id :";


    }
    int formaPago;
    cout<<"Ingrese Forma de pago"<<endl;
    cout<<"1.Efectivo      2.Tajeta"<<endl;
    cin>>formaPago;


    Venta venta(idVenta,formaPago,precio );
    ventaArchivo.guardar(venta);


}



    void listarDetallesVenta(int idVenta){

    ProductoManager pm;
    DetalleVentaManager dm;

    int cant;
    cant=dm.contarRegistrosPorId(idVenta);


    int *p;
    p=new int[cant];
    if(p==NULL){
        return ;
    }

    pm.listarVecDetalles(dm.cargarVector(p,idVenta),cant);


    delete p;


    }
