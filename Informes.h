#pragma once
#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "UsuarioManager.h"
#include "Producto.h"
#include "ProductoManager.h"
#include "ProductoArchivo.h"
#include "Venta.h"
#include "VentaArchivo.h"
#include "VentaManager.h"
#include "CierreDeCajaManager.h"
#include "CategoriaManager.h"
#include "SucursalManager.h"

using namespace std;

//Menus:

class InformesManager{
public:
    void menuInformes();
    void consultasEmpleados();
    void consultasStock();
    void consultasVenta();
    void consultasSucursal();
    void consultasCategoria();
};
