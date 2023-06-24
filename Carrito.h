// En este archivo se crea la clase Carrito que depende de la clase ProductoCarrito.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#ifndef CARRITO_H
#define CARRITO_H
#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include <string>

using namespace std;

class Carrito{
    private:
        string cliente;
        int size;
        ProductoCarrito productos[10];

    public:
        Carrito(string cliente);
        void setProducto(string id, string nombre, double precio, int cantidad);
        ProductoCarrito getProducto(int i);
        void setCantProducto(int i, int cantidadNueva);
        int getSize();
        double total();
        void imprimirCarrito();
        void vaciarCarrito();
};
#endif

