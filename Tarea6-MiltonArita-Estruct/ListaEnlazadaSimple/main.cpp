#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;

 
void insertarElemento(Tlista &lista, int valor)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
        lista = q;
 
    
    
    
}
 
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
           
        }
        q = q->sgte;
        i++;
    }
 
    
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
 void reportarLista(Tlista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}

 
void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 

        
       
int main()
{
    Tlista lista = NULL;
    int op;     
    int _dato;  
       
 
  

 
    do
    {
    	cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
	    cout<<" 1. INSERTAR ELEMENTO         "<<endl;
	    cout<<" 2. BUSCAR ELEMENTO                  "<<endl;
	    cout<<" 3. ELIMINAR ELEMENTO             "<<endl;
	    cout<<" 4. SALIR                            "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
         cin>> op;
 
        switch(op)
        {
          
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 insertarElemento(lista, _dato);
            break;
 
 
            case 2:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;
 
 
            case 3:
 
                cout<<"\n Valor a eliminar: "; cin>> _dato;
 
                eliminarElemento(lista, _dato);
            break;
 
           
 
                    }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=4);
 
 
   system("pause");
   return 0;}
