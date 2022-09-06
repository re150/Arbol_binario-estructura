#include "arbol.h"

int main() {

    int altura = 0, contabor = 0;

    arbol* a = new arbol();

    a->push(5);
    a->push(4);
    a->push(3);
    a->push(2);
    a->push(1);
    a->push(8);
    a->push(7);

    cout << "InOrden" << endl;
    a->inOrden(a->sacar_raiz());
    cout << "\n" << endl;



    cout << "PostOrden" << endl;
    a->postOrden(a->sacar_raiz());
    cout << "\n" << endl;

    cout << "preorden" << endl;
    a->preOrden(a->sacar_raiz());
    cout << "\n" << endl;

    cout << "Ver el arbol balanceado \n" << endl;
    a->ver_arbol(a->sacar_raiz(), contabor);

    return 0;
}

