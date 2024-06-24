#include <iostream>
using namespace std;
#include "FuncionesExtras.h"


void guionCero(int num){
    if(num == 0)   {cout << "- ";}
    else{
        cout << num;
    }
}

bool exitCarga(int num){
    if (num == -1){
        cout << "Se ha cancelado la carga!" << endl;
        return true;
    }
    return false;
}

string fraseMayus(string frase){
    transform(
    frase.begin(),  //itera cada caracter de principio a fin
    frase.end(),
    frase.begin(),  // empieza desde el principio

    [](char& c) {   //lambda, toma un caracter y lo transforma
    return toupper(c);
    });

    return frase;
}

void coincidencia(bool coincidencia){
    if(!coincidencia){
        system("cls");
        cout << "------------------------------" << endl;
        cout << "Sin coincidencias encontradas." << endl;
        cout << "------------------------------" << endl << endl;
    }
}



int validarNumero(){
    int n;
    cin>>n;

    if(n==false || n < 0){
        return -1;
    }
    return n;
}
