#include<iostream>
using namespace std;
#include <ctime>
#include "Fecha.h"

Fecha::Fecha(){

    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;

}

Fecha::Fecha(int dia, int mes, int anio){

    _dia=dia;
    _mes=mes;
    _anio=anio;

    bool flag;

    flag=validar();

    if(!flag){
        _dia=1;
        _mes=1;
        _anio=2023;
    }



}

bool Fecha::mismoDia(Fecha fecha){

    int dia,mes,anio;
    dia=fecha.getDia();
    mes=fecha.getMes();
    anio=fecha.getAnio();

    if(_dia==dia && _mes==mes &&_anio==anio){
        return true;
    }else{
        return false;
    }

}




int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}

/*
void fecha::setAnio(int x){
    _anio=x;
}

void fecha::setMes(int x){
    _mes=x;
}

void fecha::setDia(int x){
    _dia=x;
}

*/

void Fecha::cargar(){

    cout<<"ingrese dia"<<endl;
    cin>> _dia;

     cout<<"ingrese mes"<<endl;
    cin>> _mes;

     cout<<"ingrese anio"<<endl;
    cin>> _anio;

    bool flag= validar();


    if(!flag){
        _dia=1;
        _mes=1;
        _anio=2023;
    }

    mostrar();

}
void Fecha::mostrar(){

    cout<<_dia<<"/"<<_mes<<"/"<<_anio;


}


 bool Fecha::validarFecha(Fecha aux){

    bool flag;
    int dia=aux.getDia() ;
    int mes=aux.getMes() ;
    int anio=aux.getAnio() ;



    if (anio<0){
        return false;
    }
    if (mes<0 || mes>12){
        return false;
    }
    if (dia<0){
        return false;
    }



    flag=aux.bisiesto(anio);




    if(mes==2){

        if(flag){
            if(dia<30){
                return true;
            }
            else{
                return false;
            }
        }

        else{
            if(dia<29){
                return true;
            }
            else{
                return false;
            }

        }

    }



    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes== 10 || mes==12){

            if(dia<32){
                return true;
            }
            else{
                return false;
            }
    }

     if (mes==4 || mes==6 || mes==9 || mes==11 ){
        if(dia<31){
                return true;
            }
            else{
                return false;
        }
     }

 }





 bool Fecha::validar(){

      bool flag;



    if (_anio<0){
        return false;
    }
    if (_mes<0 || _mes>12){
        return false;
    }
    if (_dia<0){
        return false;
    }



    flag=bisiesto(_anio);




    if(_mes==2){

        if(flag){
            if(_dia<30){
                return true;
            }
            else{
                return false;
            }
        }

        else{
            if(_dia<29){
                return true;
            }
            else{
                return false;
            }

        }

    }



    if (_mes==1 || _mes==3 || _mes==5 || _mes==7 || _mes==8 || _mes== 10 || _mes==12){

            if(_dia<32){
                return true;
            }
            else{
                return false;
            }
    }

     if (_mes==4 || _mes==6 || _mes==9 || _mes==11 ){
        if(_dia<31){
                return true;
            }
            else{
                return false;
            }
     }

 }


bool Fecha::bisiesto(int anio){

    bool flag=false;


    if(anio%4==0){

        if(anio%100!=0){
            flag=true;
            return flag;
        }

        else if(anio%400==0){
            flag=true;
            return flag;
        }

    }


    return flag;

}









void Fecha::agregarDia(){

    _dia++;

    switch(_mes){

    case 1:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;

    case 2:

        bool flag;
        flag=bisiesto(_anio);

        if(flag){
            if(_dia==30){
                _dia=1;
                _mes++;

            }
        }
        else if(_dia==29){
                _dia=1;
                _mes++;
            }

    break;


    case 3:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;


    case 4:
        if(_dia==31){
            _mes++;
            _dia=1;
        }

    break;



    case 5:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;

    case 6:
        if(_dia==31){
            _mes++;
            _dia=1;
        }

    break;


    case 7:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;


    case 8:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;

    case 9:
        if(_dia==31){
            _mes++;
            _dia=1;
        }

    break;


    case 10:
        if(_dia==32){
            _mes++;
            _dia=1;
        }

    break;

    case 11:
        if(_dia==31){
            _mes++;
            _dia=1;
        }

    break;


    case 12:
        if(_dia==32){
            _anio++;
            _mes=1;
            _dia=1;

        }

    break;


    }


}







void Fecha::restarDia(){
    _dia--;

       switch(_mes){

    case 1:
        if(_dia==0){
            _anio--;
            _mes=12;
            _dia=31;
        }

    break;

    case 2:


        if(_dia==0){
            _dia=31;
            _mes--;

        }

    break;


    case 3:

        bool flag;
        flag=bisiesto(_anio);

       if(flag){
            if(_dia==0){
                _dia=29;
                _mes--;

            }
        }
        else if(_dia==0){
                _dia=28;
                _mes--;
            }



    break;


    case 4:
        if(_dia==0){
            _mes--;
            _dia=31;
        }

    break;



    case 5:
        if(_dia==0){
            _mes--;
            _dia=30;
        }

    break;

    case 6:
         if(_dia==0){
            _mes--;
            _dia=31;
        }

    break;


    case 7:
         if(_dia==0){
            _mes--;
            _dia=30;
        }

    break;


    case 8:
         if(_dia==0){
            _mes--;
            _dia=31;
        }

    break;

    case 9:
         if(_dia==0){
            _mes--;
            _dia=31;
        }

    break;


    case 10:
         if(_dia==0){
            _mes--;
            _dia=30;
        }

    break;

    case 11:
         if(_dia==0){
            _mes--;
            _dia=31;
        }

    break;


    case 12:
        if(_dia==0){
            _mes--;
            _dia=30;
        }

    break;


    }

}



string Fecha::toString(){

    string dia,mes,anio,texto;


    if(_dia<10){
        dia="0" + to_string(_dia);
    }
    else{
        dia=to_string(_dia);
    }

     if(_mes<10){
        mes="0" + to_string(_mes);
    }
    else{
        mes=to_string(_mes);
    }
    anio= to_string(_anio);


    texto= dia+"/"+mes+"/"+anio;



    return texto;



}

