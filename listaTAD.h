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
    nNode->prev=NULL;
    nNode->next=NULL;
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
        *head = nNode;
    } 
    else {
        Node* temp= *head;
        for (int i=0; i < posicion-1; i++) {
            temp=temp->next;
        }
        nNode->next=temp->next;
        temp->next=nNode;
    }
}

Bool esvacia(Node* head); {
    //determina si la lista esta vacia o no.
    return head==NULL;
}
int lenght(Node*head) {
    int cont = 0;
    while (head!=NULL) {
        cont++;
        head=head->next;
    }
    return cont;
}
int buscarElem(Node* head, string elem); {
    //busca el elemento indicado.
        while (head!=NULL) {
        if (head->data==elem) {
            return head->data;
        }
        head=head->next;
    }
    return -1;//si no encuentra el elemento
}
void remove(Node** head, string data); {
    //elimina el elemento indicado.
    if (esvacia(*head)) {
        cout << "Error: lista vacia" << endl;
        return 0;
    }
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == elem) {
            if (temp == *head) {
                *head = temp->next;
                if (*head!=NULL){
                    (*head)->prev=NULL;
                }
            } 
            else {
                temp->prev->next = temp->next;
                
            }
            delete temp;
        }
        temp = temp->next;
    }
}
int getDisplay(Node* head, int posicion); {
    //obtiene el item en la poscicion
    Node* temp = *head;
    for (int i = 0; i < posicion; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void display(Node*head); {
    while(head!=NULL){
    cout << head->data << " ";
    head = head->next;
    }
    cout<<endl;
}

Node* getNext(Node* head, int posicion); {
    //obtiene el siguiente elemento en la lista.
    if (posicion < 0 || posicion >= lenght(*head)) {
        cout << "Error: posicion invalida" << endl;
        return NULL;
    }
    Node* temp = *head;
    for (int i = 0; i < posicion; i++) {
        temp = temp->next;
    }
    return temp->next;
}
