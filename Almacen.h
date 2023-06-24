// En este archivo se crea la clase Almacen que depende de la clase ProductoAlmacen.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#ifndef ALMACEN_H
#define ALMACEN_H
#include "ProductoAlmacen.h"
#include <string>

using namespace std;

class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen();
        void mostrarProductos();
        void setExistenciaAlmacen(int i, int cantidad);
        int getSize();
        ProductoAlmacen getProducto(int pos);
};
#endif