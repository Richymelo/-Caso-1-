#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <origin/main/listaTAD.h">
//Funciones
string getTop5(Node* head){
    string top = "";
  for (int i = 0; i < 5; i++) {
    if (head != NULL){
        top += getDisplay(i) + "\n";
        head= head->next
    }
  }
  return top;
}

string mostrar(Node* head, string elem){
     //obtiene el siguiente item
    int posicion = buscarElem(head, elem);
    if (posicion != -1) {
        Node* siguiente = getNext(head, posicion);
        if (siguiente != NULL) {
            cout << siguiente->data << endl;
        } else {
            cout << "No hay un elemento siguiente después de '" << elem << "'" << endl;
        }
    } else {
        cout << "Error: elemento no encontrado" << endl;
    }
}

void borrar(Node* head, string elem){
    remove(head, elem);
}

void reordenar(Node** head, int elem, int nPosicion) {
    if (esvacia(*head)) {
        cout << "Error: lista vacía" << endl;
        return;
    }
    int encontrado = buscarElem(*head, elem);
    if (encontrado == -1) {
        cout << "Error: elemento no encontrado" << endl;
        return;
    }
    remove(head, elem);
    insertar(head, elem, nPosicion);
}
    
 int main() {
    Node* head = NULL;
    insertar(&head, "Manzana", 0);
    insertar(&head, "Banana", 1);
    insertar(&head, "Cereza", 2);
    insertar(&head, "Damasco", 3);

    cout << "Todos los elementos:" << endl;
    display(head);

    cout << "Los 5 primeros elementos:" << endl;
    string top5 = getTop5(head);
    cout << top5;

    cout << "El siguiente elemento después del primero:" << endl;
    string siguiente = mostrar("Manzana");
    cout << siguiente << endl;

    cout << "Reordenar 'Cereza' a la posición 1:" << endl;
    reordenar(&head, "Cereza", 1);
    display(head);

    cout << "Eliminar 'Banana':" << endl;
    borrar("Banana");
    display(head);

    return 0;
 }