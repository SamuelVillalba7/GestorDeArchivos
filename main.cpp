#include <iostream>
#include <cstring>
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
#include "SucursalManager.h"
#include "UsuarioManager.h"
#include "Categoria.h"

#include "CierreDeCajaManager.h"



void comprar(Usuario usuario);
void listarDetallesVenta(int idVenta);
void vuelto(float precio);




int main()
{
    /*
    char contrasenia[9],contra[5];
    string _dni ;
    int dni;
   dni=45905856;

    _dni= to_string(dni);
    strcpy(contrasenia,_dni.c_str());
    cout <<_dni<<endl;
    cout <<contrasenia[0]<<endl;
    cout <<contrasenia[1]<<endl;
    cout <<contrasenia[2]<<endl;
    cout <<contrasenia[3]<<endl;

    strcpy(contra,contrasenia);

    cout<<contra<<endl<<endl;

*/





   UsuarioManager um;
   um.menuInicio();



    return 0;
}



void comprar(Usuario usuario){

    int id=1;
    float precio;

    Producto producto;
    ProductoArchivo productoArchivo;
    DetalleVentaManager dvm;
    DetalleVentaArchivo detalleArchivo;
    VentaManager vm;
    VentaArchivo ventaArchivo;
    ProductoManager productoManager;




    cout<<"Ingrese el id de los productos"<<endl;
    cout <<"Ingresando un 0 como id terminara de cargar"<<endl;
    cout <<endl<<endl;


    int idVenta=ventaArchivo.generarId();


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

    bool result=productoManager.restarStock(producto.getId());

    if(!result){
        cout<<"Pruebe con otro id"<<endl;
        continue;
    }

    DetalleVenta detalle(idVenta,producto.getId());
    detalleArchivo.guardar(detalle);



    dvm.listarDetallesVenta(idVenta);

    precio+=producto.getPrecioVenta();

    }

    cout<<endl;
    cout <<"total a pagar : $"<<precio<<endl;
    cout<<endl;
    int formaPago;
     cout<<"1.Efectivo      2.Tajeta"<<endl;
    cout<<"Ingrese Forma de pago : ";

    cin>>formaPago;
    cout<<endl;



    int sucursal,dni;
    sucursal = usuario.getSucursal();
    dni=usuario.getDni();

    Venta venta(idVenta,formaPago,precio,sucursal,dni);
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
