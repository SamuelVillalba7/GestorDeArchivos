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
void vuelto(float precio);




int main()
{


  menuPrincipal();



    return 0;
}



void comprar(){

    int id=1;
    float precio;

    Producto producto;
    ProductoArchivo productoArchivo;

    DetalleVentaArchivo detalleArchivo;
    VentaManager vm;
    VentaArchivo ventaArchivo;




    cout<<"Ingrese el id de los productos"<<endl;
    cout <<"Ingresando un 0 como id terminara de cargar"<<endl;
    cout <<endl<<endl;

    // cout<<"id        Nombre        "<<"Precio"<<endl<<endl;


    int idVenta=vm.generarId();


    while(id>0){

    cout<<"ingrese id: ";
    cin>>id;



    if(id==0){
        continue;
    }

    system("cls");

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



    listarDetallesVenta(idVenta);


    //cout<<producto.getNombre()<<"    "<<producto.getPrecioVenta()<<endl;




    precio+=producto.getPrecioVenta();



    //archivo.restarStock();

    //cout<<"id :";


    }

    cout<<endl;
    cout <<"total a pagar : $"<<precio<<endl;
    cout<<endl;
    int formaPago;
     cout<<"1.Efectivo      2.Tajeta"<<endl;
    cout<<"Ingrese Forma de pago : ";
    cin>>formaPago;
    cout<<endl;



    Venta venta(idVenta,formaPago,precio );
    ventaArchivo.guardar(venta);


    if(formaPago==1){

        vuelto(precio);

    }

    cout<<"ID DE VENTA: "<<idVenta<<endl<<endl;


}

    void vuelto(float precio){

    float pago,vuelto;

    cout<<"Con cuanto paga el cliente:  $";
    cin>> pago;

    vuelto=pago-precio;

    cout<<"el vuelto es:  $"<<vuelto<<endl<<endl;



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
