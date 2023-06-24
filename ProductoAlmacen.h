// En este archivo se crea la clase ProductoAlmacen.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <string>

using namespace std;

class ProductoAlmacen{
    private:
        string id,
               nombre;
        double precio;
        int existencia;

    public:
        ProductoAlmacen();
        ProductoAlmacen(string id, string nombre, double precio, int existencia);
        string getId();
        string getNombre();
        double getPrecio();
        int getExistencia();
        void imprimirProductos();
        void setExistencia(int x);
};
#endif
