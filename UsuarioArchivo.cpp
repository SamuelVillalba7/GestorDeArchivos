#include <iostream>
using namespace std;
#include "UsuarioArchivo.h"

UsuarioArchivo::UsuarioArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


UsuarioArchivo::UsuarioArchivo(){
    _nombreArchivo ="usuarios.dat";
}

void UsuarioArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}


bool UsuarioArchivo::guardar(Usuario usuario){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&usuario, sizeof(Usuario), 1, p);
    fclose(p);
    return escribio;

}


bool UsuarioArchivo::modificar(Usuario usuario,int pos){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr){return false;}

    fseek(p,sizeof(Usuario)*pos,SEEK_SET);

    bool escribio = fwrite(&usuario, sizeof(Usuario), 1, p);
    fclose(p);
    return escribio;

}



Usuario UsuarioArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return Usuario();
    }
    Usuario aux;
    fseek(p, posicion*sizeof(Usuario), SEEK_SET);
    fread(&aux, sizeof(Usuario), 1, p);
    fclose(p);
    return aux;

}

int UsuarioArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Usuario);

}

int UsuarioArchivo::buscarPosicion(int dni){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        Usuario aux = leer(x);
        if (dni == aux.getDni()){
            return x;
        }
    }
    return -1;

}

