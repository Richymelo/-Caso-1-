#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <listaTAD.h">
//Funciones
string getTop5(){
    string top = "";
  for (int i = 0; i < 5; i++) {
    top += to_string(getDisplay(i)) + "\n";
  }
  return top;
}
string getAll(){
    //obtiene todos los items
    display();
    
}
string mostrar(string elem){
     //obtiene el siguiente item
    getNext();
    return 0
}
string borrar(string elem){=
    remove(elem);
}
string reordenar(Node** head, string elem, int nPosicion); {
    //reordena un item moviendolo de la posicion donde esta a una nueva.
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