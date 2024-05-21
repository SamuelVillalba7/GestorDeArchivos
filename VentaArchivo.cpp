#include "VentaArchivo.h"

VentaArchivo::VentaArchivo(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

VentaArchivo::VentaArchivo()
{
    _nombreArchivo = "ventas.dat";
}

bool VentaArchivo::guardar(Venta aux)
{

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr)
    {
        return false;
    }

    bool escribio = fwrite(&aux, sizeof(Venta), 1, p);
    fclose(p);
    return escribio;

}

Venta VentaArchivo::leer(int posicion)
{

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr)
    {
        return Venta();
    }
    Venta aux;

    fseek(p, posicion*sizeof(Venta), SEEK_SET);
    fread(&aux, sizeof(Venta), 1, p);
    fclose(p);
    return aux;

}

int VentaArchivo::contarRegistros()
{

    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr)
    {
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Venta);

}

int VentaArchivo::buscarPosicion(int id)
{

    int x, cant = contarRegistros();

    for(x=0; x<cant; x++)
    {
        Venta aux = leer(x);
        if (id == aux.getId())
        {
            return x;
        }
    }
    return -1;

}
int VentaArchivo::generarId()
{
    int id,cant=contarRegistros();


    if(cant>0)
    {
        Venta aux=leer(cant-1);
        id= aux.getId()+1;
        return id;
    }
    else{
        return 1;
    }

}
