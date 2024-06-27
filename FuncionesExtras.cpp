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

string pedirFrase(){
    string aux, frase;
    aux = stringNoVacio();
    frase = fraseMayus(aux);
    return frase;
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


string stringNoVacio() {
    string palabra;
    while(true) {
        fflush(stdin);
        getline(cin, palabra);
        if (!palabra.empty()) {
            return palabra;
        } else {
            cout << "Ingrese un valor no vacio: ";
            fflush(stdin);
        }
    }
    return palabra;
}

int validarPositivo(int num){
    while(true){
        if (num < -1) {
            cout << "Numero negativo no valido. " << endl;
            num = -2;
        }
        else{
            return num;
        }
        return num;

    }
}


int pedirNumero() {
    int numero;
    while (true) {
      //  cout << "Ingrese un numero: ";
        cin >> numero;

        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada
            cout << "Entrada invalida. Ingresar solo numeros. " << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada en caso de caracteres adicionales
            validarPositivo(numero);
            if(numero>=-1)
                break;
        }
    }
    return numero;
}

float pedirFloat() {
    float numero;
    while (true) {
     //   cout << "Ingrese un numero: ";
        cin >> numero;

        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada
            cout << "Entrada invalida. Ingresar solo numeros. " << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada en caso de caracteres adicionales
            validarPositivo(numero);
            if(numero>=-1)
                break;
        }
    }
    return numero;
}

float floatPositivo(float num){
    while(true){
        if (num < -1) {
            cout << "Numero negativo no valido. " << endl;
            num = -2;
        }
        else{
            return num;
        }
        return num;

    }
}

void inicializarVec(int *vec,int tam){

    int x;
    for(x=0;x<tam;x++){
        vec[x]=0;
    }

}
