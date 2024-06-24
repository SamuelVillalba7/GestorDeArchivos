#include <iostream>
using namespace std;
#include "CategoriaArchivo.h"

CategoriaArchivo::CategoriaArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


CategoriaArchivo::CategoriaArchivo(){
    _nombreArchivo ="categorias.dat";
}

void CategoriaArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}


bool CategoriaArchivo::guardar(Categoria categoria){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&categoria, sizeof(Categoria), 1, p);
    fclose(p);
    return escribio;

}
bool CategoriaArchivo::modificar(Categoria categoria, int pos){


    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr){return false;}

    fseek(p,sizeof(Categoria)*pos ,SEEK_SET);

    bool escribio = fwrite(&categoria, sizeof(Categoria), 1, p);
    fclose(p);
    return escribio;


}


Categoria CategoriaArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return Categoria();
    }
    Categoria aux;
    fseek(p, posicion*sizeof(Categoria), SEEK_SET);
    fread(&aux, sizeof(Categoria), 1, p);
    fclose(p);
    return aux;

}

int CategoriaArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Categoria);

}

int CategoriaArchivo::buscarPosicion(int id){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        Categoria aux = leer(x);
        if (id == aux.getId()){
            return x;
        }
    }
    return -1;

}


int CategoriaArchivo::generarId(){
    int id,cant=contarRegistros();

    if(cant>0)
    {
        Categoria aux=leer(cant-1);
        id= aux.getId()+1;
        return id;
    }
    else{
        return 1;
    }

}

