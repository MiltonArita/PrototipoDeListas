#include <iostream>

using namespace std;

struct Nodo{
    int data;
    Nodo *siguiente, *anterior;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void eliminarLista(Nodo *&, int);

Nodo *lista=NULL;

int main(){
    insertarLista(lista,51);
    insertarLista(lista,50);
    insertarLista(lista,10);
    mostrarLista(lista);
    return 0;
}

void insertarLista(Nodo *&Lista, int dato){
    Nodo *nuevo_dato = new Nodo();
    nuevo_dato->data = dato;
    nuevo_dato->anterior = NULL;
    
    Nodo *a1 = lista;
    Nodo *a2;
    
    while(a1 != NULL){
        a2=a1;
        a1=a1-> siguiente;
    }
    
    if(lista == a1){
        lista=nuevo_dato;
        lista->anterior = nuevo_dato;
    }else{
        a2->siguiente = nuevo_dato;
    }
    nuevo_dato->siguiente = a1;
    
    cout<<"Elemento (" <<dato<< ") insertado a la lista correctamente"<<endl;
    cout<<""<<endl;
}

void mostrarLista(Nodo *Lista){
    Nodo *listado = new Nodo();
    listado = Lista;
    int elemento=1;
    while(listado != NULL){
        cout<<elemento++<<"- dato: "<<listado->data<<" siguiente:";
        (listado->siguiente == NULL) ? cout<<"vacio" : cout<< (listado->siguiente)->data;
        cout<<" anterior: ";
        (listado->anterior == NULL) ? cout<<"vacio" : cout<< (listado->anterior)->data;
        cout<<endl;
        listado= listado->siguiente;
    }
    cout<<"\nFin de la lista"<<endl;
}
