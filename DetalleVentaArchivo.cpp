#include <iostream>
using namespace std;
#include "DetalleVentaArchivo.h"

DetalleVentaArchivo::DetalleVentaArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


DetalleVentaArchivo::DetalleVentaArchivo(){
    _nombreArchivo ="detalleVentas.dat";
}

void DetalleVentaArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}

bool DetalleVentaArchivo::guardar(DetalleVenta aux){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&aux, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return escribio;

}

DetalleVenta DetalleVentaArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return DetalleVenta();
    }
    DetalleVenta aux;

    fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
    fread(&aux, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return aux;

}

int DetalleVentaArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(DetalleVenta);

}

int DetalleVentaArchivo::buscarPosicion(int id){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        DetalleVenta aux = leer(x);
        if (id == aux.getIdVenta()){
            return x;
        }
    }
    return -1;

}

/*

void DetalleVentaArchivo::listarProducto(){

        FILE *farchivo;
        farchivo=fopen(nombre,"rb");
        if(farchivo==NULL){
        cout<<"no se pudo abrir";
        return;
        }

        DetalleVenta aux;

        while(fread(&aux,sizeof (DetalleVenta),1,farchivo)==1){
        aux.mostrar();
        cout<<endl;
        }
        fclose(farchivo);

}

*/
