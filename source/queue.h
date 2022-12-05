#include<iostream>
#include <mutex>
#include <stdlib.h>
#include <time.h>
#include <thread>
using namespace std;

template <class T>
struct Node
{
    T dato;
    Node *next;
    Node *prev;

    Node(T _dato){
        dato = _dato;
        next = 0;
        next = 0;
    }
};

template <class T>
class Cola
{
    private:    
        //Node<T>* queue = nullptr;
        Node<T> *head;
        Node<T> *tail;
        int nElementos; // numero de elementos

    public:
        //mutex candado;
        Cola(){
            head = 0;
            tail = 0;
            nElementos = 0;
        }

        ~Cola()
        {
            while (tail) {
                pop();
            }
        }

        bool empty(){
            if(nElementos == 0){
                return true;
            }
            else{
                return false;
            }
        }

        T pop(){
            
            if (nElementos == 0){
                //cout << "Lista vacia" << endl;
                //return 0;
                throw std::out_of_range("Lista vacia");
            }
            
            T aux1;
            aux1 = head->dato; //guardamos para el retorno de la funcion

            Node<T> *newNodo = head;
            head = head->next; // avanzamos head al siguiente

            // si la lista sigue con datos (acomomdamos head)
            if(head){
                head->prev = nullptr;
            } 
            
            delete newNodo;
            nElementos = nElementos - 1;
            
            return aux1; // retorno
        }

        void push(T valor){
            //candado.lock();
            //cout << "Añadiendo: " << valor << endl;

            Node<T> *newNodo = new Node<T>(valor); 
            //newNodo->dato = valor;

            // lista vacia?
            if(nElementos == 0){
                head = newNodo;
                tail = newNodo;
            }
            else{
                // doble enlace
                newNodo->prev = tail; 
                tail->next = newNodo;

                // Redireccionamos tail
                tail = newNodo;
            }
            nElementos = nElementos + 1;
        }
};