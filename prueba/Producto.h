#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
using namespace std;


class Producto{

private:
    int _id;
    int _stock;
    char _nombre[50];
    float _precioCompra;
    float _precioVenta;
    int _tipo;
    bool _estado;



public:

    Producto(int id,string nombre, float precioC,float precioV, int stock, int tipo);
    Producto();

    void setId(int x);
    void setNombre(string x);
    void setPrecioCompra(float x);
    void setPrecioVenta(float x);
    void setStock (int x);
    void setTipo(int x);
    void setEstado(bool x);




    string getNombre();
    float getPrecioCompra();
    float getPrecioVenta();
    int getStock();
    int getStockMinimo();
    int getTipo();
    int getId();






};

#endif // PRODUCTO_H_INCLUDED
