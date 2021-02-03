#include <iostream>
using namespace std;

//la cola es un formato de tipo FIFO first in, first out con lo cual el puntero no apunta desde el nodo
//nuevo al viejo, es al reves, desde el nodo viejo se apunta al nuevo porque se quita elementos de la cola
//empezando por la base y no por el tope

class Cola{
    private:
        class Nodo{
            public:
                int dato;
                Nodo *siguiente;

        };
    Nodo *raiz;
    Nodo *final;
    public:
        Cola();
        ~Cola();
        void insertarItem(int item);
        int quitarItem();
        void imprimirCola();
};

Cola::Cola(){
    raiz = NULL; //igual que en pila usamos un puntero raiz desde donde se va a quitar los nodos
    final = NULL; //ahora agregamos el puntero final, para controlar la iteracion de cada nodo a agregar
}

void Cola::insertarItem(int item){
    Nodo *nodoNuevo;
    nodoNuevo = new Nodo;
    nodoNuevo->dato = item; 

    if (raiz == NULL){
        raiz = nodoNuevo; //aca van los cambios, si no hay raiz, se asigna el nodo creado
        final = nodoNuevo; //como solo tenemos un nodo, ese nodo es el final de la cola
        final->siguiente = NULL; //como no hay nodo siguiente el puntero indicador es null

    } else { //si ya tenemos raiz
        final->siguiente = nodoNuevo; //se agrega al puntero del nodo final la dir del nodo creado 
        final = nodoNuevo; //se asigna un nuevo final, el nodo creado
        
        
    }
};

void Cola::imprimirCola(){
    Nodo *recorrer = raiz;
    cout << "Listado de todos los elementos de la pila.\n";
    while (recorrer != NULL) //mientras el puntero reco no sea null
    {
        cout << recorrer->dato << "-"; //se imprime la propiedad info
        recorrer = recorrer->siguiente; //se asigna a reco la direccion del puntero guardado en dentro del nodo en lectura
    }
    cout << "\n";
}

Cola::~Cola() //destructor de la clase pila
{
    Nodo *recorrer = raiz; //declaro un puntero recorrer con la memoria de un Nodo y le asigno la raiz
    Nodo *borrar; //declaro un Nodo borrar con el tamaño de memoria de un Nodo
    while (recorrer != NULL) //mientras recorrer no sea null
    {
        borrar = recorrer; //recorrer se asigna a borrar
        recorrer = recorrer->siguiente; //a recorrer se le asigna la direccion del nodo siguiente en la pila
        delete borrar; //se borra bor
    }
}

int Cola::quitarItem(){
    if(raiz != NULL){
    int informacion = raiz->dato; //se declara un var y se le asigna el contenido de info
        Nodo *borrar = raiz; //se declara un puntero nodo "bor(borrar)" y se le asigna la raiz
        //la idea de usar Nodo es reservar la memoria para el nodo a leer en esa direccion de memoria
        raiz = raiz->siguiente; //la raiz se le asigna el puntero siguiente del nodo leido
        delete borrar; //se borra el nodo leido
        return informacion; //retornamos la pripiedad leida
    }
    else
    {
        return -1;
    }    
    
}

int main()
{
    Cola *Cola1; //declaro un puntero con el tamaño en memoria de pila
    Cola1= new Cola(); //creo un objeto pila y lo asigno al puntero
    Cola1->insertarItem(10); //inserto un dato
    Cola1->insertarItem(8); //inserto un dato
    Cola1->insertarItem(40); //inserto un dato
    Cola1->insertarItem(15); //inserto un dato
    Cola1->insertarItem(3); //inserto un dato
    Cola1->imprimirCola(); //imprimo la pila
    cout<<"\n";
    cout<<"Extraemos de la pila:" <<Cola1->quitarItem()<<"\n"; //se extrae el primer elemento de la cola
    cout<<"\n";
    Cola1->imprimirCola(); //se imprime la pila
    delete Cola1; //se libera la memoria
    return 0;
}
