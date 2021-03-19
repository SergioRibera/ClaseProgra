#include <iostream>
#include "Clase.h"

using namespace std;

// Constructor de la clase
Clase::Clase(){
    rellenarArreglo();
}
// Destructor de la clase
Clase::~Clase(){
}

void Clase::rellenarArreglo(){
    // Pedimos la cantidad de elementos para el arreglo mientras no exeda
    // nuestro valor maximo
    cout << "Introduce la cantidad de elementos para el arreglo: ";
    cin >> m;
    cout << endl;
    
    //
    //  Rellenamos los valores de 0 a m
    //
    for (int i = 0; i < m; i++){
        cout << "Introduce el elemento " << i << ": ";
        cin >> v1[i];
    }
}
//
//      Getters
//
int Clase::getElement(int index){
    return v1[index];
}

void Clase::getElements(){
    for (int i = 0; i < m; i++){
        cout << "[" << i << "] => " << v1[i] << endl;
    }
}
//
//      Setters
//
void Clase::setElement(int index, int value){
    v1[index] = value;
}
