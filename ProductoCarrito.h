// En este archivo se crea la clase ProductoCarrito.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include "ProductoAlmacen.h"
#include "Almacen.h"
#include <string>

using namespace std;

class ProductoCarrito{
    private:
        string id,
               nombre;
        double precio;
        int cantidad;

    public:
        ProductoCarrito();
        ProductoCarrito(string id, string nombre, double precio, int cantidad);
        string getId();
        double getCant();
        double subtotal();
        void setCant(int cantidadNueva);
        void imprimirProductos();
};
#endif

