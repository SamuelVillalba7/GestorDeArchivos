#include "ProductoArchivo.h"

ProductoArchivo::ProductoArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


ProductoArchivo::ProductoArchivo(){
    _nombreArchivo ="productos.dat";
}

bool ProductoArchivo::guardar(Producto producto){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

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

