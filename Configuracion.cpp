#include <iostream>
#include <cstring>
using namespace std;
#include "Configuracion.h"


 Configuracion::Configuracion(){

    strcpy(_BkpProducto,"Producto.bkp");
    strcpy(_BkpVenta,"Venta.bkp");
    strcpy(_BkpDetalleVenta,"DetalleVenta.bkp");
    strcpy(_BkpSucursal,"Sucursal.bkp");
    strcpy(_BkpCategoria,"Categoria.bkp");
    strcpy(_BkpCierreDeCaja,"CierreDeCaja.bkp");
    strcpy(_BkpUsuario,"Usuario.bkp");


    strcpy(_InicioProducto,"Producto.inicio");
    strcpy(_InicioSucursal,"Sucursal.inicio");
    strcpy(_InicioCategoria,"Categoria.inicio");
}


void Configuracion::limpiarBkpProducto(){

     FILE *farchivo;
    farchivo=fopen(_BkpProducto,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpVenta(){

     FILE *farchivo;
    farchivo=fopen(_BkpVenta,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpDetalleVenta(){

     FILE *farchivo;
    farchivo=fopen(_BkpDetalleVenta,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpCierreDeCaja(){

     FILE *farchivo;
    farchivo=fopen(_BkpCierreDeCaja,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpSucursal(){

     FILE *farchivo;
    farchivo=fopen(_BkpSucursal,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpCategoria(){

     FILE *farchivo;
    farchivo=fopen(_BkpCategoria,"wb");
    fclose(farchivo);

    }

    void Configuracion::limpiarBkpUsuario(){

     FILE *farchivo;
    farchivo=fopen(_BkpUsuario,"wb");
    fclose(farchivo);

    }











  void Configuracion::crearBkpProducto(){

    limpiarBkpProducto();

  int cant,x;
  ProductoArchivo aux;
  cant=aux.contarRegistros();

  Producto *vec;

  vec=new Producto[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpProducto,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(Producto),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

  cout<<"Se creo el bkp correctamente"<<endl;

  }



   void Configuracion::crearBkpVenta(){

    limpiarBkpVenta();

  int cant,x;
  VentaArchivo aux;
  cant=aux.contarRegistros();

    Venta *vec;

  vec=new Venta[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpVenta,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(Venta),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

  cout<<"Se creo el bkp correctamente"<<endl;

  }




   void Configuracion::crearBkpDetalleVenta(){

    limpiarBkpDetalleVenta();

  int cant,x;
  DetalleVentaArchivo aux;
  cant=aux.contarRegistros();

  DetalleVenta *vec;

  vec=new DetalleVenta[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpDetalleVenta,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(DetalleVenta),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

    cout<<"Se creo el bkp correctamente"<<endl;
  }



   void Configuracion::crearBkpCierreDeCaja(){

    limpiarBkpCierreDeCaja();

  int cant,x;
  CierreDeCajaArchivo aux;
  cant=aux.contarRegistros();

  CierreDeCaja *vec;

  vec=new CierreDeCaja[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpCierreDeCaja,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(CierreDeCaja),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

  cout<<"Se creo el bkp correctamente"<<endl;
  }



   void Configuracion::crearBkpSucursal(){

    limpiarBkpSucursal();

  int cant,x;
  SucursalArchivo aux;
  cant=aux.contarRegistros();

  Sucursal *vec;

  vec=new Sucursal[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpSucursal,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(Sucursal),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

    cout<<"Se creo el bkp correctamente"<<endl;
  }



   void Configuracion::crearBkpCategoria(){

    limpiarBkpCategoria();

  int cant,x;
  CategoriaArchivo aux;
  cant=aux.contarRegistros();

  Categoria *vec;

  vec=new Categoria[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpCategoria,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(Categoria),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

  cout<<"Se creo el bkp correctamente"<<endl;

  }



   void Configuracion::crearBkpUsuario(){

    limpiarBkpUsuario();

  int cant,x;
  UsuarioArchivo aux;
  cant=aux.contarRegistros();

  Usuario *vec;

  vec=new Usuario[cant];

  for(x=0;x<cant;x++){

    vec[x]=aux.leer(x);

  }

  FILE *farchivo;
    farchivo=fopen(_BkpUsuario,"ab");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

  for(x=0;x<cant;x++){

    fwrite(&vec[x],sizeof(Usuario),1,farchivo);

  }

   fclose(farchivo);
  delete [] vec;

  cout<<"Se creo el bkp correctamente"<<endl;

  }



    void Configuracion::restablecerProducto(){

     ProductoArchivo arch;
     arch.vaciarArchivo();
     Producto aux;

     FILE *farchivo;
    farchivo=fopen(_BkpProducto,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Producto),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


 void Configuracion::restablecerDetalleVenta(){

     DetalleVentaArchivo arch;
     arch.vaciarArchivo();
     DetalleVenta aux;

     FILE *farchivo;
    farchivo=fopen(_BkpDetalleVenta,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (DetalleVenta),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


void Configuracion::restablecerCierreDeCaja(){

     CierreDeCajaArchivo arch;
     arch.vaciarArchivo();
     CierreDeCaja aux;

     FILE *farchivo;
    farchivo=fopen(_BkpCierreDeCaja,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (CierreDeCaja),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


void Configuracion::restablecerSucursal(){

     SucursalArchivo arch;
     arch.vaciarArchivo();
     Sucursal aux;

     FILE *farchivo;
    farchivo=fopen(_BkpSucursal,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Sucursal),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


void Configuracion::restablecerCategoria(){

     CategoriaArchivo arch;
     arch.vaciarArchivo();
     Categoria aux;

     FILE *farchivo;
    farchivo=fopen(_BkpCategoria,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof(Categoria),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


void Configuracion::restablecerUsuario(){

     UsuarioArchivo arch;
     arch.vaciarArchivo();
     Usuario aux;

     FILE *farchivo;
    farchivo=fopen(_BkpUsuario,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Usuario),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}


void Configuracion::restablecerVenta(){

     VentaArchivo arch;
     arch.vaciarArchivo();
     Venta aux;

     FILE *farchivo;
    farchivo=fopen(_BkpVenta,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Venta),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);

     cout<<"Se restablecio correctamente"<<endl;
}





void Configuracion::datosDeInicio(){

     restablecerCategoriaInicio();
     restablecerProductoInicio();
     restablecerSucursalInicio();
    cout<<"Se restablecio correctamente"<<endl;
}


 void Configuracion::restablecerProductoInicio(){

     ProductoArchivo arch;
     arch.vaciarArchivo();
     Producto aux;

     FILE *farchivo;
    farchivo=fopen(_InicioProducto,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Producto),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);
}


void Configuracion::restablecerSucursalInicio(){

     SucursalArchivo arch;
     arch.vaciarArchivo();
     Sucursal aux;

     FILE *farchivo;
    farchivo=fopen(_InicioSucursal,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof (Sucursal),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);
}


void Configuracion::restablecerCategoriaInicio(){

     CategoriaArchivo arch;
     arch.vaciarArchivo();
     Categoria aux;

     FILE *farchivo;
    farchivo=fopen(_InicioCategoria,"rb");
    if(farchivo==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
    }

    while(fread(&aux,sizeof(Categoria),1,farchivo)==1){
        arch.guardar(aux);
    }
     fclose(farchivo);
}















void Configuracion::menuPrincipal(){

     int opcion;
    while (true){
        system("cls");
        cout << "MENU CONFIGURACION" << endl;
        cout << "----------------" << endl;
        cout << "1) CREAR BKPS" << endl;
        cout << "2) RESTAURAR DATOS" << endl;
        cout << "3) LIMPIAR ARCHIVOS" << endl;
        cout << "4) ESTABLECER DATOS DE INICIO" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                   menuCrearBkp();
                }
                break;
            case 2:
                {
                   menuRestablecer();
                }
                break;
            case 3:
                {
                    menuVaciarArchivos();
                }
                break;

            case 4:
                {
                    datosDeInicio();
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
void Configuracion::menuCrearBkp(){

    int opcion;
    while (true){
        system("cls");
        cout << "MENU CONFIGURACION" << endl;
        cout << "----------------" << endl;
        cout << "1) PRODUCTO BKP" << endl;
        cout << "2) VENTA BKP" << endl;
        cout << "3) DETALLE VENTA BKP" << endl;
        cout << "4) SUCURSAL BKP" << endl;
        cout << "5) CATEGORIA BKP" << endl;
        cout << "6) CIERRE DE CAJA BKP" << endl;
        cout << "7) USUARIO BKP" << endl;

        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                   crearBkpProducto();
                }
                break;
            case 2:
                {
                    crearBkpVenta();
                }
                break;
            case 3:
                {
                  crearBkpDetalleVenta();
                }
                break;
            case 4:
                {
                  crearBkpSucursal();
                }
                break;

            case 5:
                {
                  crearBkpCategoria();
                }
                break;

            case 6:
                {
                  crearBkpCierreDeCaja();
                }
                break;

            case 7:
                {
                  crearBkpUsuario();
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
void Configuracion::menuRestablecer(){



    int opcion;
    while (true){
        system("cls");
        cout << " MENU CONFIGURACION" << endl;
        cout << "----------------" << endl;
        cout << "1) RESTABLECER PRODUCTO" << endl;
        cout << "2) RESTABLECER VENTA BKP" << endl;
        cout << "3) RESTABLECER DETALLE VENTA BKP" << endl;
        cout << "4) RESTABLECER SUCURSAL BKP" << endl;
        cout << "5) RESTABLECER CATEGORIA BKP" << endl;
        cout << "6) RESTABLECER CIERRE DE CAJA BKP" << endl;
        cout << "7) RESTABLECER USUARIO BKP" << endl;
        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                   restablecerProducto();
                }
                break;
            case 2:
                {
                    restablecerVenta();
                }
                break;
            case 3:
                {
                  restablecerDetalleVenta();
                }
                break;
            case 4:
                {
                  restablecerSucursal();
                }
                break;

            case 5:
                {
                  restablecerCategoria();
                }
                break;

            case 6:
                {
                  restablecerCierreDeCaja();
                }
                break;

            case 7:
                {
                  restablecerUsuario();
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





void Configuracion::menuVaciarArchivos(){


    ProductoArchivo productoArch;
    VentaArchivo ventaArch;
    DetalleVentaArchivo detalleVentaArch;
    CategoriaArchivo categoriaArch;
    SucursalArchivo sucursalArch;
    CierreDeCajaArchivo cierreArch;
    UsuarioArchivo usuarioArch;


    int opcion;
    while (true){
        system("cls");
        cout << " MENU CONFIGURACION" << endl;
        cout << "--VACIAR ARCHIVOS--" << endl;
        cout << "-------------------" << endl;
        cout << "1) VACIAR PRODUCTO" << endl;
        cout << "2) VACIAR VENTA " << endl;
        cout << "3) VACIAR DETALLE VENTA " << endl;
        cout << "4) VACIAR SUCURSAL " << endl;
        cout << "5) VACIAR CATEGORIA " << endl;
        cout << "6) VACIAR CIERRE DE CAJA " << endl;
        cout << "7) VACIAR USUARIO " << endl;

        cout << "---------------------------" << endl;
        cout << "0) SALIR" << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                   productoArch.vaciarArchivo();
                }
                break;
            case 2:
                {
                    ventaArch.vaciarArchivo();
                }
                break;
            case 3:
                {
                  detalleVentaArch.vaciarArchivo();
                }
                break;
            case 4:
                {
                  sucursalArch.vaciarArchivo();
                }
                break;

            case 5:
                {
                  categoriaArch.vaciarArchivo();
                }
                break;

            case 6:
                {
                  cierreArch.vaciarArchivo();
                }
                break;

            case 7:
                {
                  usuarioArch.vaciarArchivo();
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
