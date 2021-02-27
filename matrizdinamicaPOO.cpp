#include <iostream>

//la idea es hacer un matriz dinamica (en tiempo de ejecucion) peeero con POO, si, con clases.
//el codigo se basa en el publicado en https://mauricioavilesc.blogspot.com/2015/08/matriz-dinamica-en-c.html
//pero simplificandolo y quitandole los throw que estn deprecados.

using namespace std;

//aca hacemos un template de la clase. Explicacion: hacer un template generico nos permite castear
//la clase para diferentes tipos de dato como se explica acá: https://www.cprogramming.com/tutorial/templates.html

template <typename E>
class DynamicMatrix
{
private:
    int rows;
    int columns;
    E** matrix;
//el doble puntero para un arreglo de dos dimensiones 
public:
    DynamicMatrix(int pRows, int pColumns){
        //constructor que inicializa el numero de columnas y filas
        rows = pRows;
        columns = pColumns;
        matrix = new E*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new E[columns];
        }
    }
    //destructor de la clase
    ~DynamicMatrix() {
        for (int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
//el getter de la clase con el tipo generico
    E getValue(int pRow, int pColumn){
        
        return matrix[pRow][pColumn];
    }
//el setter de la clase que INGRESA un tipo generico
    void setValue(int pRow, int pColumn, E value){
        
        matrix[pRow][pColumn] = value;
    }
    //retorna el numero de filas.
    int getRows() {
        return rows;
    }
    //retorna el numero de columnas.
    int getColumns() {
        return columns;
    }
    //esta es una delaracion que usé pra probar que en clsses con template hay que incluir el template en la definicion
    void pepe();
};

//bien, esto me dio problemas, el sacar la definicion de un metodo por fuera de la clase
//(la declaracion queda dentro de la clase)
//cual era la historia? hay que incluir la declaracion del template en cda definicion de un metodo
//"ẗemplate<typename E> y el tag <E> luego del subespacio del metodo subespcio<E>::metodo"

template <typename E>
void DynamicMatrix<E>::pepe(){
        cout<<"pepe"<<endl;
}



int main(){
    //declaro un objeto y lo casteo como Int, invoco su contructor tambien.
    DynamicMatrix<int> matriz(10, 15);
    for (int i = 0; i < matriz.getRows(); i++) {
        for (int j = 0; j < matriz.getColumns(); j++) {
            matriz.setValue(i, j, i+j);
            //esto rellena la matriz con una serie de enteros
        }
    }
    //esto otro imprime l matriz.
    for (int i = 0; i < matriz.getRows(); i++) {
        for (int j = 0; j < matriz.getColumns(); j++) {
            cout << matriz.getValue(i, j) << "\t";
        }
        cout << endl;
    }
    return 0;
}


