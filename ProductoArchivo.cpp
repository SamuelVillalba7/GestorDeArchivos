#include <iostream>
using namespace std;
#include "ProductoArchivo.h"

ProductoArchivo::ProductoArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


ProductoArchivo::ProductoArchivo(){
    _nombreArchivo ="productos.dat";
}

void ProductoArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}


bool ProductoArchivo::guardar(Producto producto){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&producto, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;

}
bool ProductoArchivo::modificar(Producto producto, int pos){


    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr){return false;}

    fseek(p,sizeof(Producto)*pos ,SEEK_SET);

    bool escribio = fwrite(&producto, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;


}


Producto ProductoArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return Producto();
    }
    Producto aux;
    fseek(p, posicion*sizeof(Producto), SEEK_SET);
    fread(&aux, sizeof(Producto), 1, p);
    fclose(p);
    return aux;

}

int ProductoArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Producto);

}

int ProductoArchivo::buscarPosicion(int id){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        Producto aux = leer(x);
        if (id == aux.getId()){
            return x;
        }
    }
    return -1;

}


int ProductoArchivo::generarId(){
    int id,cant=contarRegistros();

    if(cant>0)
    {
        Producto aux=leer(cant-1);
        id= aux.getId()+1;
        return id;
    }
    else{
        return 1;
    }

}

bool ProductoArchivo::existeNombre(string nombre) { /// Func que evita que se repitan nombres
    int cant = contarRegistros();
    for (int x = 0; x < cant; x++) {
        Producto aux = leer(x);
        if (nombre == aux.getNombre()) {
            return true;
        }
    }
    return false;
}

