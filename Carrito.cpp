// En este archivo se programan los métodos de la clase Carrito.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include "Carrito.h"
#include <iostream>

using namespace std;

// Constructor default que crea un arreglo de tipo ProductoCarrito vacios. 
Carrito::Carrito(string cliente){
    this -> cliente = cliente;
    this -> size = 0;
    for (int i=0; i < 10; i++){
      productos[i] = ProductoCarrito();
    } 
}

// Se guardan en su respectiva posición productos de tipo ProductoCarrito con los atributos ingresados como paramétros de este método.
void Carrito::setProducto(string id, string nombre, double precio, int cantidad){
  this -> productos[size] = ProductoCarrito(id, nombre, precio, cantidad); 
  this -> size += 1;
}

// Regresa el objeto tipo ProductoCarrito del arreglo productos, que se encuentra en la posición ingresada como parámetro de este método.
ProductoCarrito Carrito::getProducto(int i){
  return this -> productos[i];
}

// Modifica el atributo 'cantidad' del objeto tipo ProductoCarrito, que se encuentra en la posición ingresada como parámetro de este método, con la nueva cantidad ingresada también como parámtero.
void Carrito::setCantProducto(int i, int cantidadNueva){
  productos[i].setCant(cantidadNueva);
}

// Regresa el tamaño del arreglo de objetos tipo ProductoCarrito conforme se hayan agregado en el main.cpp
int Carrito::getSize(){
  return this -> size;
}

// Regresa el total de todos los productos agregados al arreglo productos. 
double Carrito::total(){
    double total = 0;
    for (int i=0; i < size; i++){
        total +=  productos[i].subtotal();
    }
    return total;
}

// Imprime todos los productos del arreglo tipo ProductoCarrito.
void Carrito::imprimirCarrito(){
    cout<<"\nCarrito de compras de: "<<cliente<<endl;
    cout<<"\nID - NOMBRE | PRECIO | CANTIDAD | SUBTOTAL"<<endl;
    for (int i = 0; i < size; i++){
        this -> productos[i].imprimirProductos();
    }
    cout<<"\n\t\t\t\t\t\tTOTAL: $"<<total()<<endl;
}

// Borra todos los objetos tipo ProductoCarrito y en lugar se asignan objetos tipo ProductoCarrito vacios. 
void Carrito::vaciarCarrito(){
  this -> size = 0;
  for (int i=0; i < 10; i++){
    productos[i] = ProductoCarrito();
  }
}
