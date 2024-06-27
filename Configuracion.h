#pragma once

#include "ProductoArchivo.h"
#include "VentaArchivo.h"
#include "DetalleVentaArchivo.h"
#include "CategoriaArchivo.h"
#include "CierreDeCajaArchivo.h"
#include "SucursalArchivo.h"
#include "UsuarioArchivo.h"
#include "FuncionesExtras.h"


class Configuracion{

    private:
        char _BkpProducto[30];
        char _BkpSucursal[30];
        char _BkpCategoria[30];
        char _BkpVenta[30];
        char _BkpDetalleVenta[30];
        char _BkpCierreDeCaja[30];
        char _BkpUsuario[30];

        char _InicioProducto[30];
        char _InicioSucursal[30];
        char _InicioCategoria[30];

    public:

        Configuracion();

        void menuPrincipal();
        void menuCrearBkp();
        void menuRestablecer();
        void menuVaciarArchivos();

        void limpiarBkpSucursal();
        void limpiarBkpProducto();
        void limpiarBkpVenta();
        void limpiarBkpDetalleVenta();
        void limpiarBkpCierreDeCaja();
        void limpiarBkpCategoria();
        void limpiarBkpUsuario();

        void crearBkpSucursal();
        void crearBkpProducto();
        void crearBkpVenta();
        void crearBkpDetalleVenta();
        void crearBkpCierreDeCaja();
        void crearBkpCategoria();
        void crearBkpUsuario();

        void restablecerCategoria();
        void restablecerSucursal();
        void restablecerProducto();
        void restablecerVenta();
        void restablecerDetalleVenta();
        void restablecerCierreDeCaja();
        void restablecerUsuario();

        void datosDeInicio();
        void restablecerCategoriaInicio();
        void restablecerSucursalInicio();
        void restablecerProductoInicio();
};
