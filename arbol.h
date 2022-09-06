#pragma once
#include <iostream>

using namespace std;

class Node {
public:
    int     dato;
    int     fe; 
    Node* left;
    Node* right;

    Node(int dato) {
     this->dato = dato;
     this->   fe = 0;
     this ->left = NULL;
     this->   right = NULL;
    }
};

class arbol {
private:
    Node* raiz;
public:
    
    arbol() {
        raiz = nullptr;
    }
    Node* buscar(int dato, Node* raiz) {
        if (raiz == nullptr) {
            return nullptr;
        }
        else if (raiz->dato == dato) {
            return raiz;
        }
        else if (raiz->dato < dato) {
            return buscar(dato, raiz->right);
        }
        else if (raiz->dato > dato) {
            return buscar(dato, raiz->left);
        }
    }

    int obtenerFE(Node* nodo) {
        if (nodo == nullptr) {
            return -1;
        }
        else {
            return nodo->fe;
        }
    }

   

    Node* orden_ll(Node* nodo) {
        Node* aux = nodo->left;
        nodo->left = aux->right;

        aux->right = nodo;

        nodo->fe = max(obtenerFE(nodo->left), obtenerFE(nodo->right)) + 1;
        aux->fe = max(obtenerFE(aux->left), obtenerFE(aux->right)) + 1;

        return aux;
    }

    Node* Ordenar_lr(Node* nodo) {
        Node* aux;

        nodo->left = Orden_rr(nodo->left);
        aux = orden_ll(nodo);

        return aux;
    }

    Node* Orden_rr(Node* nodo) {
        Node* aux = nodo->right;
        nodo->right = aux->left;

        aux->left = nodo;

        nodo->fe = max(obtenerFE(nodo->left), obtenerFE(nodo->right)) + 1;
        aux->fe = max(obtenerFE(aux->left),obtenerFE(aux->right)) + 1;

        return aux;
    }

    Node* Ordenar_rl(Node* nodo) {
        Node* aux;

        nodo->right = orden_ll(nodo->right);
        aux = Orden_rr(nodo);

        return aux;
    }

    Node* pushNodo(Node* nuevo, Node* subArbol) {
        Node* nuevoPadre = subArbol;

        if (nuevo->dato < subArbol->dato) {
            if (subArbol->left == nullptr) {
                subArbol->left = nuevo;
            }
            else {
                subArbol->left = pushNodo(nuevo, subArbol->left);

                int balance = obtenerFE(subArbol->left) - obtenerFE(subArbol->right);

                if (balance == 2) {
                    if (nuevo->dato < subArbol->left->dato) {
                        nuevoPadre = orden_ll(subArbol);
                    }
                    else {
                        nuevoPadre = Ordenar_lr(subArbol);
                    }
                }

            }
        }
        else if (nuevo->dato > subArbol->dato) {
            if (subArbol->right == nullptr) {
                subArbol->right = nuevo;
            }
            else {
                subArbol->right = pushNodo(nuevo, subArbol->right);

                int balance = obtenerFE(subArbol->right) - obtenerFE(subArbol->left);

                if (balance == 2) {
                    if (nuevo->dato > subArbol->right->dato) {
                        nuevoPadre = Orden_rr(subArbol);
                    }
                    else {
                        nuevoPadre = Ordenar_rl(subArbol);
                    }
                }
            }
        }
        else {
            cout << "valor duplicado!" << endl;
        }


        if ((subArbol->left == nullptr) && (subArbol->right != nullptr)) {
            subArbol->fe = subArbol->right->fe + 1;
        }
        else if ((subArbol->right == nullptr) && (subArbol->left != nullptr)) {
            subArbol->fe = subArbol->left->fe + 1;
        }
        else {
            subArbol->fe = max(obtenerFE(subArbol->left), obtenerFE(subArbol->right)) + 1;
        }

        return nuevoPadre;
    }

    void ver_arbol(Node * nodo , int contabor) {
        if (nodo == nullptr) {
            return;
        }
        else
        {

            ver_arbol(nodo->right, contabor +1 );
            for (int i = 0; i < contabor; i++)
            {
                cout << "  ";
            }
            cout << nodo->dato<<endl;
            ver_arbol(nodo->left, contabor + 1);

        }
    }

    int sacar_altura(Node* n) {
        if (n == nullptr) {
            return -1;
        }

        int derAl, Altiz;

        derAl =sacar_altura(n->right);
        Altiz =sacar_altura(n->left);

        if (Altiz > derAl) {
            return Altiz + 1;
        }
        else {
            return derAl + 1;
        }

    }
    

    void push(int dato) {
        Node* nuevo = new Node (dato);

        if (raiz == nullptr) {
            raiz = nuevo;
        }
        else {
            raiz = pushNodo(nuevo, raiz);
        }
    }

    void inOrden(Node* nodo) {
        if (nodo != nullptr) {
            inOrden(nodo->left);
            cout << nodo->dato << " ";
            inOrden(nodo->right);
        }
    }

    void preOrden(Node* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preOrden(nodo->left);
            preOrden(nodo->right);
        }
    }

    void postOrden(Node* nodo) {
        if (nodo != NULL) {
            postOrden(nodo->left);
            postOrden(nodo->right);
            cout << nodo->dato << " ";
        }
    }


    Node*sacar_raiz() {
        return raiz;
    }

    
};

