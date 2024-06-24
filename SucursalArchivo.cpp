#include <iostream>
using namespace std;
#include "SucursalArchivo.h"

SucursalArchivo::SucursalArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


SucursalArchivo::SucursalArchivo(){
    _nombreArchivo ="sucursal.dat";
}

void SucursalArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}



bool SucursalArchivo::guardar(Sucursal sucursal){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&sucursal, sizeof(Sucursal), 1, p);
    fclose(p);
    return escribio;

}
bool SucursalArchivo::modificar(Sucursal sucursal, int pos){


    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr){return false;}

    fseek(p,sizeof(Sucursal)*pos ,SEEK_SET);

    bool escribio = fwrite(&sucursal, sizeof(Sucursal), 1, p);
    fclose(p);
    return escribio;


}


Sucursal SucursalArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return Sucursal();
    }
    Sucursal aux;
    fseek(p, posicion*sizeof(Sucursal), SEEK_SET);
    fread(&aux, sizeof(Sucursal), 1, p);
    fclose(p);
    return aux;

}

int SucursalArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Sucursal);

}

int SucursalArchivo::buscarPosicion(int id){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        Sucursal aux = leer(x);
        if (id == aux.getId()){
            return x;
        }
    }
    return -1;

}


int SucursalArchivo::generarId(){
    int id,cant=contarRegistros();

    if(cant>0)
    {
        Sucursal aux=leer(cant-1);
        id= aux.getId()+1;
        return id;
    }
    else{
        return 1;
    }

}

