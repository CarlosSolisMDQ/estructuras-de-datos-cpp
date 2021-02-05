#include <iostream>
using namespace std;

//lista enlazada simple, con sus metodos para agregar al principio, al final, borrar y imprimir la list

class Lista {
    private:
    class Nodo {
    public:
        int dato;
        Nodo *siguiente;
    };
    Nodo *raiz;
      
    public:
    
    Lista();
    ~Lista();
    void agregarNodoAlInicio(int numero);
    void agregarNodoAlFinal(int numero);
    void borrarNodo(int numeroDeNodo);
    void imprimirLista();
};


Lista::Lista(){
    raiz = NULL;
}

Lista::~Lista(){
    Nodo *recorrer = raiz; //declaro un puntero recorrer con la memoria de un Nodo y le asigno la raiz
    Nodo *borrar; //declaro un Nodo borrar con el tamaño de memoria de un Nodo
    while (recorrer != NULL) //mientras recorrer no sea null
    {
        borrar = recorrer; //recorrer se asigna a borrar
        recorrer = recorrer->siguiente; //a recorrer se le asigna la direccion del nodo siguiente en la pila
        delete borrar; //se borra bor
    }
}

void Lista::agregarNodoAlInicio(int numero){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = numero; //bloque pra preparar el nuevo nodo
    
    if(raiz == NULL){
        raiz = nuevo; //si no hay raiz, se asigna el nuevo nodo
    } else {
        nuevo->siguiente = raiz; //si hay raiz se asigna la dir de la vieja raiz al nuevo nodo y se lo declara raiz
        raiz = nuevo;
    }
   
}

void Lista::agregarNodoAlFinal(int numero){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = numero;

    Nodo *nodoActual = raiz;
    while(nodoActual->siguiente != NULL){
        nodoActual = nodoActual->siguiente;
    } //iteramos para llegar al ultimo nodo que no tenga asignado un siguiente y le asignamos el nuevo nodo

    nodoActual->siguiente = nuevo;
}

void Lista::imprimirLista(){
    Nodo *contador; 
    contador = raiz;
    int numerador = 1;
    while(contador != NULL){
        cout<<"el nodo numero "<<numerador<<" contiene el valor: "<<contador->dato<<endl;
        contador = contador->siguiente;
        //iteramos la lista hasta null y imprimimos formateado los nodos      
        numerador++;
    }
}

void Lista::borrarNodo(int numeroDeNodo){
    Nodo *nodoActual;
    nodoActual = raiz; //guardamos el nodo actual
    int contador = 0; //iniciamos un contador de nodos
    Nodo *nodoAnterior; //iniciamos un nodo anterior como null
    nodoAnterior = NULL;
    Nodo *nodoPosterior; //iniciamos un nodo posterior
    while(nodoActual != NULL){
        contador++; //mientras nodoactual no sea null aumentamos el contador
        
        nodoPosterior = nodoActual->siguiente; //el podeterior es el puntero almacenado en nodoactual
        if (contador == numeroDeNodo){ //chequeamos si el numero coincide con la pos del nodo actual
            if(nodoAnterior == NULL){ //si nodoanterior es null, estmos en la raiz
                raiz = nodoActual->siguiente; //asignamos el siguiente como raiz
                delete nodoActual; //borramos el actual(la anterior raiz)
            } else { //si el nodo anterior no es null
                nodoAnterior->siguiente = nodoActual->siguiente; //asignamos el puntero del seguiente del actual al siguiente del anterior
                delete nodoActual; //borramos el actual
            }
            
            
        }
        nodoAnterior = nodoActual; //si no se dieron las condiciones avanzamos en la iteracion de l alista
        nodoActual = nodoActual->siguiente; //el actual se hace el anterior y el siguiente se hace el actual
    }
}

int main(){
    Lista *lista1; //creamos un puntero lista
    lista1 = new Lista(); //reservamos la memoria
    lista1->agregarNodoAlInicio(5); //agregamos un nodo al principio
    lista1->agregarNodoAlInicio(6);
    lista1->agregarNodoAlInicio(10);
    lista1->agregarNodoAlInicio(3);
    lista1->agregarNodoAlFinal(100); //agregamos un nodo al final
    lista1->imprimirLista(); //imprimimos
    lista1->borrarNodo(3); //borramos el tercer nodo
    cout<<"\n";
    lista1->imprimirLista(); //imprimimos
    delete lista1;
    return 0;
};