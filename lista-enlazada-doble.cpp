#include <iostream>
using namespace std;

class Lista {
    private:
    class Nodo{
        public:
        int dato;
        Nodo *anterior;
        Nodo *siguiente; //la lista doble tiene dos punteros en cada nodo
    };
    Nodo *raiz;
    Nodo *tope; //agrego un puntero tope para tener registrados los dos extremos de la lista.
    public:
    Lista();
    ~Lista();
    void agregarNodo(int numero);
    void agregarNodoEnPosicion(int numero, int posicion);
    void imprimirLista();
    void borrarNodo(int nodo);

};

Lista::Lista(){ //se inicializan en NULL los dos punteros de la Lista en el constructor
    raiz = NULL;
    tope = NULL;
}

Lista::~Lista(){
    Nodo *recorrer = raiz;
    Nodo *borrar;
    while(recorrer != NULL){
        borrar = recorrer;
        recorrer = recorrer->siguiente;
        delete borrar;
    }
}

void Lista::agregarNodo(int numero){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = numero;
    if(raiz == NULL){ //si no hay raiz el nodo se agrega como raiz y tope.
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;
        raiz = nuevo;
        tope = nuevo;

    } else { //si ya hay raiz, solo se corre el tope y se referencia el nuevo nodo en su anterior y se referencia el anterior en el tope
        tope->siguiente = nuevo;
        nuevo->anterior = tope;
        nuevo->siguiente = NULL;
        tope = nuevo;
    }
    
    
}

void Lista::borrarNodo(int nodo){
    int contador = 1; //contador indice por si quiero borrar por posicion y no por contenido.
    Nodo *iterador = raiz; //creamos un puntero iterador del tamaño de un nodo
    
    while(iterador != NULL){
        if(iterador->dato == nodo && iterador->anterior == NULL){
            raiz = iterador->siguiente; //si el contenido del nodo coincide y su anterior es null, es la raiz
            tope = iterador->siguiente; //hacemos la raiz y tope el siguiente
            delete iterador; //se borra el actual(raiz)
        }

        
        if(iterador->dato == nodo && iterador->siguiente == NULL){
            Nodo *nodoAnterior; //si el contenido coincide y el siguiente es null, es el tope
            nodoAnterior = iterador->anterior; 
            //hacemos null la referencia del siguiente en el nodo anterior
            //primero almacenamos el nodo anterior en un puntero temporal para acceder a sus propiedades
            nodoAnterior->siguiente = NULL; 
            delete iterador; //borramos el actual.

        }else if(iterador->dato == nodo && iterador->siguiente != NULL){
            //si coincide el contenido y el siguiente no es null, no estamos en un extremo
            Nodo *nodoSiguiente;
            nodoSiguiente = iterador->siguiente;
            Nodo *nodoAnterior; 
            nodoAnterior = iterador->anterior;
            //creamos dos punteros temporales para almacenar el anterior y el siguiente para acceder a sus propiedades
            nodoAnterior->siguiente = nodoSiguiente; //referenciamos esos dos nodos saltando al actual
            nodoSiguiente->anterior = nodoAnterior;

            delete iterador; //borramos actual
            
            
        }
        
        iterador = iterador->siguiente; 
        contador++;
        //si no entran en los if el buble avanza un nodo y se actualiza el indice (que no estoy usando)

    }
    
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

void Lista::agregarNodoEnPosicion(int numero, int posicion){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = numero;
    int contador = 1;
    Nodo *iterador;
    //creamos un nodo nuevo, le asignamos contenido y creamos un indice y un iterador
    iterador = raiz;
    while(iterador != NULL){
        //iteramos hasta la posicion escrita para alojar el nuevo nodo
        if(contador == posicion){
            if(posicion == 1){ //si el posicion es 1, se agrega nuevo como raiz
                nuevo->anterior = NULL;
                nuevo->siguiente = raiz;
                raiz->anterior = nuevo;
                raiz = nuevo;
            } else {
                if(iterador->siguiente == NULL){ //si llegamos a un iterador donde el siguiente sea null, es el tope
                    iterador->siguiente = nuevo; //se referencia el nuevo en el iterador
                    nuevo->anterior = iterador; //se referencia iterador en el nuevo
                    nuevo->siguiente = NULL; //el siguiente de nuevo es null
                    tope = nuevo; //nuevo es el nuevo tope. Ingresar un nuevo en un lista de 5 elementos
                    //en la pos 5 te da un nuevo nodo en una posicion 6
                } else{ //si no estamos en el primero o el ultimo...
                    Nodo *anteriorNodo;
                    //declaramos un nodo temporal y lo referenciamos con el iterador y su anterior
                    anteriorNodo = iterador->anterior;
                    anteriorNodo->siguiente = nuevo;
                    nuevo->siguiente = iterador;            
                    iterador->anterior = nuevo;
                    nuevo->anterior = anteriorNodo;
                }
                //en el hipotetico caso que uno ingrese una posicion mayor a la del ultimo nodo de la lista
                //el nodo queda huerfano.
            }
        } 

        contador++;
        iterador = iterador->siguiente;
    }
}

int main(){
    Lista *lista1;
    lista1 = new Lista();
    lista1->agregarNodo(3);
    lista1->agregarNodo(40);
    lista1->agregarNodo(50);
    lista1->agregarNodo(8);
    lista1->agregarNodo(13);
    lista1->imprimirLista();
    lista1->borrarNodo(3);
    cout<<endl;
    lista1->imprimirLista();
    lista1->agregarNodoEnPosicion(90, 1);
    lista1->agregarNodoEnPosicion(900, 5);
    cout<<endl;
    lista1->imprimirLista();
    delete lista1;
    return 0;
}

