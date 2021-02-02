#include <iostream>

using namespace std;

//defino una clase pila, con la clase Nodo definida como private, 
//así que solo va a ser accesible desde los metodos de la misma clase Pila

class Pila {
private:
    class Nodo {
    public:
    //la case nodo contiene una variable numero y un puntero al nodo siguiente
        int info;
        Nodo *sig;
    };
//declaro un pentero a un Nodo con el nombre raiz.
    Nodo *raiz;
public:
//aca van los constructores, destructores y metodos
    Pila();
    ~Pila();
    void insertar(int x);
    int extraer();
    void imprimir();
};
//recordar los :: son el operador de acceso a ambito (subespacio::objeto) 
Pila::Pila()
{
    raiz = NULL; //se asigna null al puntero raiz.
}

void Pila::insertar(int x)
{
    Nodo *nuevo; //declaramos un nuevo nodo
    nuevo = new Nodo(); //creamos y asignamos el nodo a la variable nuevo
    nuevo->info = x; //asigno el paramotro a l variable info del nodo nuevo
    if (raiz == NULL) //si el puntero raiz es null
    {
        raiz = nuevo; //se asigna nuevo a raiz
        nuevo->sig = NULL; //el puntero siguiente del nodo Nuevo se hace null porque es la base de la pila
    }
    else // si raiz no es null
    {
        nuevo->sig = raiz; //al puntero siguiente del nuevo nodo se le asigna la direccion de la raiz (el nodo anterior)
        raiz = nuevo; //la posicion raiz la ocupa el nuevo nodo
    }
}

void Pila::imprimir()
{
    Nodo *reco = raiz; //declaramos un puntero reco(recorrer) y la asignamos la raiz(el nodo superior)
    cout << "Listado de todos los elementos de la pila.\n";
    while (reco != NULL) //mientras el puntero reco no sea null
    {
        cout << reco->info << "-"; //se imprime la propiedad info
        reco = reco->sig; //se asigna a reco la direccion del puntero guardado en dentro del nodo en lectura
    }
    cout << "\n";
}

int Pila::extraer()
{
    if (raiz != NULL) //mientras la raiz no sea null
    {
        int informacion = raiz->info; //se declara un var y se le asigna el contenido de info
        Nodo *bor = raiz; //se declara un puntero nodo "bor(borrar)" y se le asigna la raiz
        //la idea de usar Nodo es reservar la memoria para el nodo a leer en esa direccion de memoria
        raiz = raiz->sig; //la raiz se le asigna el puntero siguiente del nodo leido
        delete bor; //se borra el nodo leido
        return informacion; //retornamos la pripiedad leida
    }
    else
    {
        return -1;
    }
}

Pila::~Pila() //destructor de la clase pila
{
    Nodo *reco = raiz; //declaro un puntero recorrer con la memoria de un Nodo y le asigno la raiz
    Nodo *bor; //declaro un Nodo borrar con el tamaño de memoria de un Nodo
    while (reco != NULL) //mientras recorrer no sea null
    {
        bor = reco; //recorrer se asigna a borrar
        reco = reco->sig; //a recorrer se le asigna la direccion del nodo siguiente en la pila
        delete bor; //se borra bor
    }
}

int main()
{
    Pila *pila1; //declaro un puntero con el tamaño en memoria de pila
    pila1= new Pila(); //creo un objeto pila y lo asigno al puntero
    pila1->insertar(10); //inserto un dato
    pila1->insertar(40); //inserto un dato
    pila1->insertar(3); //inserto un dato
    pila1->imprimir(); //imprimo la pila
    cout<<"Extraemos de la pila:" <<pila1->extraer()<<"\n"; //se extrae un elemento del tope de la pila
    pila1->imprimir(); //se imprime la pila
    delete pila1; //se libera la memoria
    return 0;
}