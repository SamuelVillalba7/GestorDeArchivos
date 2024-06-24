#include <iostream>
using namespace std;
#include "CierreDeCajaArchivo.h"

CierreDeCajaArchivo::CierreDeCajaArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


CierreDeCajaArchivo::CierreDeCajaArchivo(){
    _nombreArchivo ="CierreDeCaja.dat";
}


void CierreDeCajaArchivo::vaciarArchivo(){

     FILE *farchivo;
    farchivo=fopen(_nombreArchivo.c_str(),"wb");
     if (farchivo == nullptr){
        cout<<"NO SE PUDO ABRIR DEL ARCHIVO"<<endl;
        return ;
     }

    fclose(farchivo);

}


bool CierreDeCajaArchivo::guardar(CierreDeCaja cierreDeCaja){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr){return false;}

    bool escribio = fwrite(&cierreDeCaja, sizeof(CierreDeCaja), 1, p);
    fclose(p);
    return escribio;

}
bool CierreDeCajaArchivo::modificar(CierreDeCaja cierreDeCaja, int pos){


    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr){return false;}

    fseek(p,sizeof(CierreDeCaja)*pos ,SEEK_SET);

    bool escribio = fwrite(&cierreDeCaja, sizeof(CierreDeCaja), 1, p);
    fclose(p);
    return escribio;


}


CierreDeCaja CierreDeCajaArchivo::leer(int posicion){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return CierreDeCaja();
    }
    CierreDeCaja aux;
    fseek(p, posicion*sizeof(CierreDeCaja), SEEK_SET);
    fread(&aux, sizeof(CierreDeCaja), 1, p);
    fclose(p);
    return aux;

}

int CierreDeCajaArchivo::contarRegistros(){

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(CierreDeCaja);

}

int CierreDeCajaArchivo::buscarPosicion(int id){

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++){
        CierreDeCaja aux = leer(x);
        if (id == aux.getId()){
            return x;
        }
    }
    return -1;

}


int CierreDeCajaArchivo::generarId(){
    int id,cant=contarRegistros();

    if(cant>0)
    {
        CierreDeCaja aux=leer(cant-1);
        id= aux.getId()+1;
        return id;
    }
    else{
        return 1;
    }

}

