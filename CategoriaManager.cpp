#include <iostream>
#include <cstring>
using namespace std;
#include <cstdlib>
#include "CategoriaManager.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include "DetalleVentaArchivo.h"
#include "DetalleVentaManager.h"
#include "ProductoManager.h"
#include "Venta.h"
#include "VentaArchivo.h"
#include "FuncionesExtras.h"



bool CategoriaManager::cargar()
{

    cout<<"----------"<<endl;
    cout<<"Categoria"<<endl;
    cout<<"----------"<<endl;

    Categoria aux;
    int id;
    string n;
    id=_archivo.generarId();
    cout<<"El id es: "<<id<<endl;

    aux.setId(id);

    fflush(stdin);
    cout<<"Ingrese nombre"<<endl;

    n = pedirFrase();

    aux.setNombre(n);
    aux.setEstado(true);


    if(_archivo.guardar(aux))
    {
        cout<<endl<<"Se guardo correctamente"<<endl;
        return true;
    }
    else
    {
        cout<<"No se pudo cargar"<<endl;
        return false;
    }


}

void CategoriaManager::mostrar(Categoria categoria)
{

    bool estado=categoria.getEstado();
    if(estado)
    {

        cout<<"El id es : "<<categoria.getId()<<endl;
        cout<<"El Nombre es : "<<categoria.getNombre()<<endl;

    }
}

void CategoriaManager::listarPorID()
{
    int id;
    cout << "ID de Sucursal a buscar: ";
    id = pedirNumero();

    int pos = _archivo.buscarPosicion(id);
    if (pos >= 0)
    {
        Categoria aux = _archivo.leer(pos);

        bool estado=aux.getEstado();

        if(!estado)
        {
            cout<<"--------------------------"<<endl;
            cout<<"Registro dado de baja"<<endl;
            cout<<"--------------------------"<<endl;
            return;
        }

        mostrar(aux);
    }
    else
    {
        cout << "No existe tal ID Sucursal." << endl;
    }

}





void CategoriaManager::listarTodos()
{
    for(int i=0; i<_archivo.contarRegistros(); i++)
    {
        mostrar(_archivo.leer(i));
        cout<<endl<<endl;
    }
}


bool CategoriaManager::IdDisponible(int id)
{
    if( _archivo.buscarPosicion(id)==-1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

string CategoriaManager::nombrePorId(int id)
{
    int pos;
    pos=_archivo.buscarPosicion(id);
    Categoria categoria=_archivo.leer(pos);

    return categoria.getNombre();
}

int CategoriaManager::ingresarId()
{

    int id, pos;
    cout <<"Ingrese el ID del producto"<<endl;
    id = pedirNumero();


    pos=_archivo.buscarPosicion(id);
    while(pos<0)
    {
        cout<<"ID no registrado"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Ingrese otro id"<<endl;
        cout <<"(Si ingresa -1 saldra de la carga)"<<endl;
        id = pedirNumero();

        if(id == -1)
        {
            return -1;

        }

        pos=_archivo.buscarPosicion(id);

    }

    return pos;

}

void CategoriaManager::bajaLogica()
{

    int pos;
    pos= ingresarId();
    Categoria aux;
    aux=_archivo.leer(pos);
    if (pos == -1)
    {
        cout<<"Salir de la operacion"<<endl;
        return;
    }

    bool estado=aux.getEstado();

    if(!estado)
    {
        cout<<"--------------------------"<<endl;
        cout<<"Registro dado de baja"<<endl;
        cout<<"--------------------------"<<endl;
        return;
    }

    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    mostrar(aux);
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;

    int opc;
    cout<<"Este producto quiere dar de baja? (1.Si 2.No)"<<endl;
    opc = pedirNumero();

    if(opc==1)
    {

        aux.setEstado(false);
        if(_archivo.modificar(aux,pos))
        {

            cout<<"Se elimino el registro"<<endl;
        }
        else
        {
            cout<<"No se pudo eliminar el registro"<<endl;
        }
    }
    else
    {
        cout<<"No se elimino el registro"<<endl;
    }

}




string CategoriaManager::devolverNombre(int pos)
{


    Categoria aux;
    CategoriaArchivo arch;
    aux= arch.leer(pos);
    return aux.getNombre();
}

void CategoriaManager::cargarCantVentas(int *vecCategorias,int tam)
{


    Fecha hoy;
    int x,i,ventaCant, categoria, cantDetalle ;

    inicializarVec(vecCategorias,tam);

    Venta venta;
    VentaArchivo ventaArch;
    ventaCant= ventaArch.contarRegistros();

    DetalleVentaManager detalleManager;
    DetalleVenta detalle;
    DetalleVentaArchivo detalleArch;

    ProductoManager productoManager;

    for(x=0; x<ventaCant; x++)
    {
        venta= ventaArch.leer(x);


        if(venta.getFecha().getMes() == hoy.getMes())
        {


            int *vec, id=venta.getId();
            cantDetalle= detalleManager.contarRegistrosPorId(id);
            vec= new int[cantDetalle];

            if(vec==NULL)
            {
                return ;
            }

            detalleManager.cargarVector(vec,id);




            for(i=0; i<cantDetalle; i++)
            {

                int idDetalle= vec[i];
                categoria= productoManager.devuelveCategoria(idDetalle);



                vecCategorias[categoria-1]++;

            }



            delete [] vec;
        }

    }


}


void CategoriaManager::cargarGanancias(int *vecCategorias,int tam)
{


    Fecha hoy;
    int x,i,ventaCant, categoria, cantDetalle,ganancia ;

    inicializarVec(vecCategorias,tam);

    Venta venta;
    VentaArchivo ventaArch;
    ventaCant= ventaArch.contarRegistros();

    DetalleVentaManager detalleManager;
    DetalleVenta detalle;
    DetalleVentaArchivo detalleArch;

    ProductoManager productoManager;

    for(x=0; x<ventaCant; x++)
    {
        venta= ventaArch.leer(x);


        if(venta.getFecha().getMes() == hoy.getMes())
        {


            int *vec, id=venta.getId();
            cantDetalle= detalleManager.contarRegistrosPorId(id);
            vec= new int[cantDetalle];

            if(vec==NULL)
            {
                return ;
            }

            detalleManager.cargarVector(vec,id);




            for(i=0; i<cantDetalle; i++)
            {

                int idDetalle= vec[i];
                categoria= productoManager.devuelveCategoria(idDetalle);
                ganancia= productoManager.devuelveGanancia(idDetalle);


                vecCategorias[categoria-1]+= ganancia;

            }



            delete [] vec;
        }

    }


}







void CategoriaManager::ventasPorCategoria()
{

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);

    for(x=0; x<cant; x++)
    {
        Categoria aux= arch.leer(x);
        bool estado=aux.getEstado();

        if(estado)
        {
            string nombre;
            nombre= devolverNombre(x);
            cout<<nombre<<" : "<<vecCategorias[x]<<endl;
        }


    }

}


void CategoriaManager::masVendida()
{

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);



    int maximo,pos=0;

    maximo= vecCategorias[0];

    for(x=1; x<cant; x++)
    {


        if(vecCategorias[x]>maximo)
        {

            maximo=vecCategorias[x];
            pos=x;
        }

    }


    cout<<endl<<"La categoria que mas se vendio fue :"<<pos+1<<" ( "<<devolverNombre(pos)<<" ) "<<endl<<endl;
}

void CategoriaManager::menosVendida()
{


    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);

    int minimo,pos=0;

    minimo= vecCategorias[0];

    for(x=1; x<cant; x++)
    {


        if(vecCategorias[x]<minimo)
        {

            minimo=vecCategorias[x];
            pos=x;
        }

    }


    cout<<endl<<"La categoria que menos se vendio fue :"<<pos+1<<" ( "<<devolverNombre(pos)<<" ) "<<endl<<endl;

}



void CategoriaManager::superoVentas()
{

    int ventas;
    cout<<"Se mostrara las categorias que superen la cantidad de ventas que ingrese: ";
    cin>>ventas;

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);
    Categoria aux;



    for(x=0; x<cant; x++)
    {

        if(vecCategorias[x]>ventas)
        {
            aux=arch.leer(x);
            cout<<"--------------------------"<<endl;
            mostrar(aux);
            cout<<"--------------------------"<<endl;

        }

    }



}


void CategoriaManager::noSuperoVentas()
{

    int ventas;
    cout<<"Se mostrara las categorias que no superen la cantidad de ventas que ingrese: ";
    cin>>ventas;

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);
    Categoria aux;



    for(x=0; x<cant; x++)
    {

        if(vecCategorias[x]<ventas)
        {
            aux=arch.leer(x);
            cout<<"--------------------------"<<endl;
            mostrar(aux);
            cout<<"--------------------------"<<endl;

        }

    }

}






void CategoriaManager::recaudadoPorCategoria()
{

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);


    for(x=0; x<cant; x++)
    {
        Categoria aux= arch.leer(x);
        bool estado=aux.getEstado();

        if(estado)
        {
            string nombre;
            nombre= devolverNombre(x);
            cout<<nombre<<" : $"<<vecCategorias[x]<<endl;
        }


    }

}


void CategoriaManager::generoMasGanancias()
{

    int cant,x, maximo,pos;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);


    maximo= vecCategorias[0];
    pos= 0;


    for(x=1; x<cant; x++)
    {

        if(maximo < vecCategorias[x])
        {

            maximo= vecCategorias[x];
            pos= x;
        }

    }


    cout<<"La categoria que genero mas ganancias fue : "<<pos+1<<" ( "<<devolverNombre(pos)<<" ) "<<endl<<endl;


}

void CategoriaManager::generoMenosGanancias()
{

    int cant,x, minimo,pos;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);


    minimo= vecCategorias[0];
    pos= 0;


    for(x=1; x<cant; x++)
    {

        if(minimo> vecCategorias[x])
        {

            minimo= vecCategorias[x];
            pos= x;
        }

    }


    cout<<"La categoria que genero menos ganancias fue : "<<pos+1<<" ( "<<devolverNombre(pos)<<" ) "<<endl<<endl;


}



void CategoriaManager::superoGanancias()
{

    int ganancia;
    cout<<"Se mostrara las categorias que superen la ganancias que ingrese: ";
    cin>>ganancia;

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);
    Categoria aux;



    for(x=0; x<cant; x++)
    {

        if(vecCategorias[x]>ganancia)
        {
            aux=arch.leer(x);
            cout<<"--------------------------"<<endl;
            mostrar(aux);
            cout<<"--------------------------"<<endl;

        }

    }



}



void CategoriaManager::noSuperoGanancias()
{

    int ganancia;
    cout<<"Se mostrara las categorias que no superen la ganancias que ingrese: ";
    cin>>ganancia;

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);
    Categoria aux;



    for(x=0; x<cant; x++)
    {

        if(vecCategorias[x]<ganancia)
        {
            aux=arch.leer(x);
            cout<<"--------------------------"<<endl;
            mostrar(aux);
            cout<<"--------------------------"<<endl;

        }
    }
}


void CategoriaManager::gananciaPorId()
{



    int id;
    cout<<"Ingrese el id de la categoria que quiera saber la ganancia"<<endl;
    cin>>id;


    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarGanancias(vecCategorias,cant);




    cout<<"Las ganancias de "<< devolverNombre(id-1) <<" : $"<< vecCategorias[id-1]<<endl;


}


void CategoriaManager::ventaPorId()
{

    int id;
    cout<<"Ingrese el id de la categoria que quiera saber las ventas"<<endl;
    cin>>id;

    int cant,x;
    CategoriaArchivo arch;
    cant= arch.contarRegistros();

    int vecCategorias[cant];

    cargarCantVentas(vecCategorias,cant);




    cout<<"Las ventas por producto de "<< devolverNombre(id-1) <<" : "<< vecCategorias[id-1]<<endl;


}



void CategoriaManager::menu()
{

    int opcion, aux;
    while (true)
    {
        system("cls");
        cout << "MENU CATEGORIAS" << endl;
        cout << "----------------" << endl;
        cout << "1) NUEVA CATEGORIA" << endl;
        cout << "2) LISTAR CATEGORIAS" << endl;
        cout << "3) LISTAR CATEGORIA POR ID" << endl;
        cout << "4) ELIMINAR CATEGORIAS" <<endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        opcion = pedirNumero();
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            cargar();
        }
        break;
        case 2:
        {
            listarTodos();
        }
        break;
        case 3:
        {
            listarPorID();
        }
        break;
        case 4:
        {
            bajaLogica();
        }
        break;
        case 5:
        {
            masVendida();
        }
        break;
        case 6:
        {
            menosVendida();
        }
        break;
        case 7:
        {
            ventasPorCategoria();
        }
        break;

        case 8:
        {
            superoVentas();
        }
        break;

        case 9:
        {
            noSuperoVentas();
        }
        break;
        case 10:
        {
            recaudadoPorCategoria();
        }
        break;
        case 11:
        {
            generoMasGanancias();
        }
        break;
        case 12:
        {
            generoMenosGanancias();
        }
        break;
        case 13:
        {
            superoGanancias();
        }
        break;
        case 14:
        {
            noSuperoGanancias();
        }
        break;
        case 15:
        {
            gananciaPorId();
        }
        break;
        case 16:
        {
            ventaPorId();
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


