/*
Se eligio la lista doble enlazada para implementar el programa.
*/
//Funciones:
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};
Node* agregar (string data){ 
    Node* nNode=new Node();
    nNode->data=data;
    nNode->prev=nullptr;
    nNode->next=nullptr;
    return nNode;
}
void insertar(Node** head, string data, int posicion);{
    //inserta un nuevo item en una posicion especifica de la lista.
    if (posicion<0 || posicion>lenght(*head)) {
        cout << "Error: posicion invalida" << endl;
        return;
    }
    Node* nNode=agregar(data);
    if (posicion==0) {
        nNode->next= *head;
        if (*head != nullptr){
            (*head)->prev =nNode;
        }
        *head = nNode;
    } 
    else {
        Node* temp= *head;
        for (int i=0; i < posicion-1; i++) {
            temp=temp->next;
        }
        nNode->next=temp->next;
        if (temp->next != nullptr){
            temp->next->prev = nNode;
        }
        temp->next=nNode;
        nNode->prev=temp;
    }
}

bool esvacia(Node* head); {
    //determina si la lista esta vacia o no.
    return head==nullptr;
}

int lenght(Node*head) {
    int cont = 0;
    while (head!=nullptr) {
        cont++;
        head= head->next;
    }
    return cont;
}

int buscarElem(Node* head, string elem); {
    //busca el elemento indicado.
        while (head!=nullptr) {
            if (head->data==elem) {
                return 1;//si encuentra el elemento
            }
        head=head->next;
    }
    return -1;//si no encuentra el elemento
}

void remove(Node** head, string data); {
    //elimina el elemento indicado.
    if (esvacia(*head)) {
        cout << "Error: lista vacia" << endl;
        return;
    }
    Node* temp = *head;
    while (temp != nullptr) {
        if (temp->data == data) {
            if (temp == *head) {
                *head = temp->next;
                if (*head!=nullptr){
                    (*head)->prev=nullptr;
                }
            } 
            else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr){
                    temp->next->prev = temp->prev
                }
                
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
}
string getDisplay(Node* head, int posicion); {
    //obtiene el item en la poscicion
    Node* temp = *head;
    for (int i = 0; i < posicion; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void display(Node*head); {
    while(head!=nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* getNext(Node* head, int posicion); {
    //obtiene el siguiente elemento en la lista.
    if (posicion < 0 || posicion >= lenght(*head)) {
        cout << "Error: posicion invalida" << endl;
        return nullptr;
    }
    Node* temp = *head;
    for (int i = 0; i < posicion; i++) {
        temp = temp->next;
    }
    return temp->next;
}
