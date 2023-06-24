// En este archivo se programan los métodos de la clase ProductoAlmacen.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#include "ProductoAlmacen.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor default de objeto ProductoAlmacen con valores predeterminados (vacios)
ProductoAlmacen::ProductoAlmacen(){
  this -> id = " ";
  this -> nombre = " ";
  this -> precio = 0.00;
  this -> existencia = 0;
}

// Constructor de objeto ProductoAlmacen con valores ingresados como parámetros de este método. 
ProductoAlmacen::ProductoAlmacen(string id, string nombre, double precio, int existencia){
    this -> id = id;
    this -> nombre = nombre;
    this -> precio = precio;
    this -> existencia = existencia;
}

// Regresa el atributo 'id' del objeto ProductoAlmacen.
string ProductoAlmacen::getId(){
    return this -> id;
}

// Regresa el atributo 'nombre' del objeto ProductoAlmacen.
string ProductoAlmacen::getNombre(){
  return this -> nombre;
}

// Regresa el atributo 'precio' del objeto ProductoAlmacen.
double ProductoAlmacen::getPrecio(){
    return this -> precio;
}

// Regresa el atributo 'existencia' del objeto ProductoAlmacen.
int ProductoAlmacen::getExistencia(){
    return this -> existencia;
}

// Imprime el objeto ProductoAlmacen con todos sus atributos.
void ProductoAlmacen::imprimirProductos(){
    cout<<"+ "<<id<<","<<nombre<<","<<precio<<","<<existencia<<endl;
}

// Modifica el atributo 'existencia' del objeto ProductoAlmacen, restandole al valor inicial, lo ingresado como parámetro de este método. 
void ProductoAlmacen::setExistencia(int x){
    this -> existencia = existencia - x;
}
