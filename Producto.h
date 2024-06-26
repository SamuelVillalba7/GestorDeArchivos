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
    int _categoria;

    bool _estado;



public:

    Producto(int id,string nombre, float precioC,float precioV, int stock, int categoria);
    Producto();


    void setId(int x);
    void setNombre(string x);
    void setPrecioCompra(float x);
    void setPrecioVenta(float x);
    void setStock (int x);
    void setCategoria(int x);


    void setEstado(bool x);
    bool getEstado();



    int getId();
    string getNombre();
    float getPrecioCompra();
    float getPrecioVenta();
    int getStock();
    int getStockMinimo();

    int getCategoria();







};

#endif // PRODUCTO_H_INCLUDED
