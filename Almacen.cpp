// En este archivo se programan los métodos de la clase Almacen.
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021. 

#include "ProductoAlmacen.h"
#include "Almacen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

// Constructor default que crea el arreglo de tipo ProductoAlmacen con base en los productos que existen en el archivo de texto 'productos.txt'.
Almacen::Almacen(){
    size = 0;
    string atributos[80],
           palabra;
    int i=0;
    ifstream lector("productos.txt");
    string linea;
    while(!lector.eof()){
        getline(lector,linea);
        stringstream ss(linea);
        while(getline(ss,palabra,',')){
          if (i < 80){
            atributos[i] = palabra;
            i++;
          }
        }          
    }
    lector.close();
    for (int i=0; i<= 80; i+=4){
      if (atributos[i] != ""){
        string id = atributos[i];
        string nombre = atributos[i+1];
        double precio = stod(atributos[i+2]);
        int existencia = atoi(atributos[i+3].c_str());
        this -> productos[size] = ProductoAlmacen(id,nombre,precio,existencia);
        size ++;
      }   
    }
}

// Imprime el arreglo produtcos de tipo ProductoAlmacen. 
void Almacen::mostrarProductos(){
    cout<<"ID,NOMBRE,PRECIO,CANTIDAD EN EXISTENCIA"<<endl;
    for (int i = 0; i < size; i++){
      productos[i].imprimirProductos();
    }
}

// Modifica el atributo 'existencia' del objeto ProductoAlmacen, por el parámetro cantidad, que se encuentra en el arreglo productos en el lugar del indice introducido por el parámtro i.
void Almacen::setExistenciaAlmacen(int i, int cantidad){
  productos[i].setExistencia(cantidad);
}

// Regresa el tamaño del arreglo productos. 
int Almacen::getSize(){
    return this -> size;
}

// Regresa el objeto tipo ProductoAlmacen del arreglo de tipo ProductoAlmacen del indice ingresado como parámetro. 
ProductoAlmacen Almacen::getProducto(int i){
    return this-> productos[i];
}