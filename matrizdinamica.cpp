#include <iostream>

using namespace std;


/*
Matriz en medoria dinamica (en tiempo de ejecucion) con punteros dobles. Es bastante similar el manejo
que podes hacer en JS pero con asignacion directa de memoria.

*/

void ingresarDatos(int **, int filas, int columnas);

void mostrarMatriz(int **, int filas, int columnas);



int main(){
    int **matriz, filas, columnas;
    //se declara un puntero doble, un puntero de punteros
    cout<<"ingresar un numero de filas: "<<endl;
    cin>>filas; 
    //leemos el valor de filas y columnas.
    cout<<"ingrese el numero de columnas: "<<endl;
    cin>>columnas;
    
    //en el puntero doble hago espacio para un array punteros del tamaño de enteros, tantos como filas
    matriz = new int *[filas];
    //itero en el array de matriz y hago espacio en cada fila para un array de enteros del tamaño de columnas
    for(int i = 0; i < filas; i++){
        matriz[i] = new int[columnas];
    }


    ingresarDatos(matriz, filas, columnas);
    
    mostrarMatriz(matriz, filas, columnas);
    
    for( int i=0; i<filas; i++ ){
        delete[] matriz[i];
    }
    //itero raiz y dealoco la memoria de cada fila y me cargo el array columna

    delete[] matriz;
    //borro la matriz.
    return 0;
}

void ingresarDatos(int **matriz, int filas, int columnas){
    
    //para ingresar a una posicion es igual que en js matriz[x][x]
    cout<<"ingresar los numeros de la matriz: "<<endl;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout<<"ingrese un numero: ";
            cin>>matriz[i][j];
        }
    }

}

void mostrarMatriz(int **matriz, int filas, int columnas){
    cout<<"imprimiendo matriz: "<<endl;
    //para imprimir lo mismo pero con cout
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
    cout << endl;
    }    
    
}