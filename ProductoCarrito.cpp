// En este archivo se programan los métodos de la clase ProductoCarrito.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include <iostream>

using namespace std;

// Constructor default de objeto ProductoCarrito con valores predeterminados (vacios)
ProductoCarrito::ProductoCarrito(){
  this -> id = "";
  this -> nombre = "";
  this -> precio = 0.00;
  this -> cantidad = 0;
}

// Constructor del objeto ProductoCarrito con valores ingresados como parámetros del método. 
ProductoCarrito::ProductoCarrito(string id, string nombre, double precio, int cantidad){
    this -> id = id;
    this -> nombre = nombre;
    this -> precio = precio;
    this -> cantidad = cantidad;
}

// Regresa el atributo 'id' del objeto ProductoCarrito.
string ProductoCarrito::getId(){
  return this -> id;
}

// Regresa el atributo 'cantidad' del objeto ProductoCarrito.
double ProductoCarrito::getCant(){
    return this -> cantidad;
}

// Regresa el subtotal del objeto ProductoCarrito con base en la cantidad requerida de este ProductoCarrito.
double ProductoCarrito::subtotal(){
    double subtotal = 0;
    subtotal = precio * cantidad;
    return subtotal;
}

// Modifica el atributo 'cantidad' del objeto ProductoCarrito, poniendo como la nueva cantidad el parámetro recibido en este método.
void ProductoCarrito::setCant(int cantidadNueva){
  this -> cantidad = cantidadNueva;
}

// Imprime el objeto ProductoCarrito con sus atributos y el subtotal.
void ProductoCarrito::imprimirProductos(){
    cout<<"+ "<<id<<" - "<<nombre<<" | $"<<precio<<" | "<<cantidad<<" | $"<<subtotal()<<endl;
}
