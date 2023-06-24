// Este programa simula la venta en línea de una tienda. 
// Autores: Alejandra Velasco Zárate A01635453 y José Antonio Juárez Pacheco A00572186
// Diciembre, 2021

#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include "Carrito.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    // Se declaran las variables utilizadas en el programa.
    Almacen inventario;
    ProductoCarrito producto;
    string cliente,
           nombre,
           id;
    int cantidad,
        confirmacion;
    double precio;

    cout<<"Bienvenido a la tienda en linea :)"<<endl;
    cout<<"Ingrese su nombre: ";
    cin>>cliente;

    // Se inicializa el arreglo miCarrito con el constructor default de la clase Carrito.
    Carrito miCarrito(cliente);
    
    // Un ciclo que va a seguir apareciendo hasta que la elección sea 6. 
    int eleccion = 1;
    while (eleccion != 6){
        cout<<"\nMENU:\n\n\t1. Ver Productos\n\t2. Comprar\n\t3. Ver Carrito\n\t4. Editar\n\t5. Pagar\n\t6. Salir"<<endl;
        cout<<"\nIngresa el numero de la funcion que desea: ";
        cin>>eleccion;
        // Si elige ver productos se llama al método de la clase Almacen 'mostrarProductos'. 
        if (eleccion == 1){
          inventario.mostrarProductos();
        }
        else if (eleccion == 2){
          confirmacion = 0;
          // Hasta que haya confirmado el pedido y haya espacio en miCarrito, se agrega al arreglo un objeto de tipo ProductoCarrito. 
          while (confirmacion != 1 && miCarrito.getSize() < 10){
            cout<<"\nEscriba el ID del producto que desea agregar al carrito: ";
            cin>>id;
            cout<<"\nEscriba la cantidad que desea agregar: ";
            cin>>cantidad; 
            for (int i=0; i< inventario.getSize();i++){
              if (id == inventario.getProducto(i).getId()){
                nombre = inventario.getProducto(i).getNombre();
                precio = inventario.getProducto(i).getPrecio();
                if (cantidad > inventario.getProducto(i).getExistencia()){
                  while (cantidad > inventario.getProducto(i).getExistencia()){
                    cout<<"\nNo contamos con la cantidad que requieres de este producto"<<endl;
                    cout<<"\nLa cantidad que tenemos de este producto es: "<<inventario.getProducto(i).getExistencia()<<endl;
                    cout<<"\nEscriba nuevamente la cantidad que desea agregar: ";
                    cin>>cantidad;
                  }
                }
              }
            }
            cout<<"¿Estas seguro de querer agregar este producto al carrito?\n\t1. SI\t\t2. NO\n\nIngresa el numero 1 para SI o 2 para NO: ";
            cin>>confirmacion;
            if (confirmacion == 1){
              miCarrito.setProducto(id,nombre,precio, cantidad);
            }
          }
          if (miCarrito.getSize() == 10){
            cout<<"\nLo sentimos, solo puede tener 10 productos en el carrito :("<<endl;
          }
        }
        // Se imprime el arreglo miCarrito, con el método imprimirCarrito de la clase Carrito.
        else if (eleccion ==3){
          miCarrito.imprimirCarrito();
        }
        else if (eleccion == 4){
          confirmacion = 0;
          while (confirmacion != 1){
            cout<<"\nEscriba el ID del producto que desea cambiar en el carrito: ";
            cin>>id;
            cout<<"\nEscriba la nueva cantidad que desea agregar de ese producto: ";
            cin>>cantidad;
            for (int i = 0; i < miCarrito.getSize(); i++){
              for (int j = 0; j < inventario.getSize(); j++){
                if (id == miCarrito.getProducto(i).getId() && id == inventario.getProducto(j).getId()){
                  if (cantidad > inventario.getProducto(j).getExistencia()){
                    while (cantidad > inventario.getProducto(j).getExistencia()){
                      cout<<"\nNo contamos con la cantidad que requieres de este producto"<<endl;
                      cout<<"\nLa cantidad que tenemos de este producto es: "<<inventario.getProducto(j).getExistencia()<<endl;
                      cout<<"\nEscriba nuevamente la cantidad que desea agregar: ";
                      cin>>cantidad;
                    }
                  }
                  // Se cambia la cantidad del objeto ProductoCarrito que quiere el usuario con la cantidad que ingresó.
                  miCarrito.setCantProducto(i,cantidad);
                }
              }

            }
            cout<<"¿Estas seguro del cambio de producto en el carrito?\n\t1. SI\t\t2. NO\n\nIngresa el numero 1 para SI o 2 para NO: ";
            cin>>confirmacion;
          }
        }
        // Imprime el total con el método total() de la clase Carrito y vacía el carrito con el método vaciarCarrito de la clase Carrito.
        else if (eleccion == 5){
          cout<<"\nEl total a pagar es de: $"<<miCarrito.total()<<" pesos."<<endl;
          cout<<"\nGRACIAS POR TU COMPRA :)"<<endl;
          for (int i=0; i < miCarrito.getSize(); i++){
            for (int j=0; j < inventario.getSize(); j++){
              if(inventario.getProducto(j).getId() == miCarrito.getProducto(i).getId()){
                // Se resta los productos 'pagados' del arreglo inventario con el método setExistenciaAlmacen de la clase Almacen.
                inventario.setExistenciaAlmacen(j,miCarrito.getProducto(i).getCant());
              }
            }
          }
          miCarrito.vaciarCarrito();
        }
        // Valida que ingrese una funcion del menú. 
        else if (eleccion != 6){
          cout<<"\nEsta eleccion no corresponde a ninguna funcion del menu. Por favor ingresa una funcion valida. "<<endl;
        }
        else{
          cout<<"\nGracias por comprar en la tienda en linea. Que tenga lindo dia :)"<<endl;
        }
  
    } 
    return 0;
};