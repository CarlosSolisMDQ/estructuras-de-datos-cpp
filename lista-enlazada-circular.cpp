#include <iostream>

using namespace std;
/*
lista doblemente enlazada circular. es la misma lista enlazada doble pero el 
ultimo elemento se enlaza con la raiz y queda un circulo completo de referencias.
*/

class Lista {
    private:
    class Nodo {
        public:
        int dato;
        Nodo *anterior;
        Nodo *siguiente;
    };
    Nodo *raiz;
    Nodo *final;
    public:
    Lista();
    ~Lista();
    void agregarNodo(int numero);
    void borrarNodo(int datoNodo);
    void imprimirLista();
};

Lista::Lista(){
    raiz = NULL;
    final = NULL;
}

Lista::~Lista(){
//lo dejo para despues
}

void Lista::agregarNodo(int numero){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = numero;
    
    if (raiz == NULL){
        raiz = nuevo;
        final = nuevo;
        nuevo->anterior = final;
        nuevo->siguiente = nuevo;
        //cambio el metodo de adicion de nodos porque me parece que mis 
        //anteriores eran muy complicdos y equivocados

    } else {
        
        final->siguiente = nuevo;
        nuevo->anterior = final;
        nuevo->siguiente = raiz;
        final = nuevo;
        raiz->anterior = final;
        
    }
}

void Lista::borrarNodo(int datoNodo){
    Nodo *contador;
    contador = raiz;

    int numerador = 1;
    while(contador != final){
        contador = contador->siguiente;
        numerador++;
    }
    //uno un contador para delimitar el tamaño de la lista y iterar así por ella
    //si bien la maquina tiene que hacer dos recorridos, me parece mas simple con listas pequeñas
    while(numerador != 0){
        
        if(contador->dato == datoNodo){
            
                Nodo *Anterior = contador->anterior;
                Nodo *Siguiente = contador->siguiente;
                Anterior->siguiente = Siguiente;
                Siguiente->anterior = Anterior;
                
                raiz = Siguiente;
                final = Anterior;
                        
                delete contador;
                continue;
        }
        contador = contador->siguiente;
        numerador--;
    }
}

void Lista::imprimirLista(){
    Nodo *contador; 
    contador = raiz;
    int numerador = 1;
    while(contador != final){
        contador = contador->siguiente;
        numerador++;
    }
    //cambio el metodo para que no numere los nodos el revez.
    
    contador = raiz;
    int nodonumero = 0;
    while(nodonumero != numerador){
        cout<<"el nodo numero "<<nodonumero + 1 <<endl<<"contiene el valor: "<<contador->dato<<" en la direccion "<<contador<<endl;
        cout<<"nodo anterior > "<<contador->anterior<<" nodo siguiente > "<<contador->siguiente<<endl<<endl;
        contador = contador->siguiente;
        //iteramos la lista hasta null y imprimimos formateado los nodos      
        nodonumero++;
    }
    
}

int main(){

    Lista *lista1;
    lista1 = new Lista();
    lista1->agregarNodo(10);
    lista1->agregarNodo(8);
    lista1->agregarNodo(7);
    lista1->agregarNodo(9);
    lista1->agregarNodo(12);
    lista1->imprimirLista();
    
    cout<<endl;
    lista1->borrarNodo(9);
    lista1->imprimirLista();
    lista1->agregarNodo(200);
    cout<<endl;
    lista1->imprimirLista();
    delete lista1;

}