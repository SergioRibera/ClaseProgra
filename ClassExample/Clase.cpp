#include <iostream>
#include "Clase.h"

#define MAX 100

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
void Clase::invertirVector(){
    int vec2[MAX];
    for (int i = 0; i < m; i++)
        vec2[i] = v1[m - (i + 1)];
        // cuando el tamaño del arreglo (m) es igual a 4
        // m - (i + 1)
        // tamañoDelArreglo - (posicionActual + 1)
        // es decir que cuando i sea 0
        // nuestro indice invertido va a ser
        // 4 - (0 + 1)
        // 4 - 1
        // = 3
        //
        // int int_monto = System::Convert::ToInt32(textmonto->Text);

    cout << "Vector Invertido: " << endl;

    for (int i = 0; i < m; i++){
        cout << "[" << i << "] => " << vec2[i] << endl;
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
