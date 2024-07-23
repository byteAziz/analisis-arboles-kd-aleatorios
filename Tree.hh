#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
#include <utility>
using namespace std;


class BinaryTree {
private:
    int k;
    struct node {
        node* left;
        node* right;
        vector<double> clau;   
        int j;  //discriminante
    };
    int count = 0; // Conteo de nodos visitados
    node* arrel;

    // PRE: actual = nodo, c = vector de coord., height = altura
    // POST: Insertar nodo standard recursivo
    BinaryTree::node* insertRecursive(node* actual, const vector<double>& c, int height);

    // PRE: root = nodo, space = valor separación
    // POST: Print árbol recursivo
    void print2DUtil(node* root, int space);

    // PRE: n = nodo
    // POST: Borrar árbol recursivo
    void BorrarBinaryTree(node* n);

    // PRE: P = punto 1, Q = punto 2
    // POST: Calcular distnacia euclidiana entre dos puntos P, Q
    double CalcDistancia(const vector<double>& P, const vector<double>& Q);

    // PRE: actual = nodo, origen = coord. origen, vecino = nodo mas cercano hasta ahora, millorDistancia = mejor distancia hasta ahora
    // POST: Búsqueda vecino recursivo
    void nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // PRE: actual = nodo, origen = coord. origen, vecino = nodo mas cercano hasta ahora, millorDistancia = mejor distancia hasta ahora
    // POST: Búsqueda vecino recursivo LINEAL
    void nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // PRE: actual = nodo, c = coord. nodo
    // POST: Insertar nodo tipo relaxed recursivo
    BinaryTree::node* insertRelaxed(node* actual, const vector<double>& c);

    // PRE: actual = nodo, c = coord. nodo, minImax = valores "bounding box"
    // POST: Insertar nodo tipo squarish recursivo
    BinaryTree::node* insertSquarish(node* actual, const vector<double>& c, vector<pair<double,double>> minIMax);


public:
    // PRE: d = dimensión del árbol
    // POST: Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    BinaryTree(int d);

    // PRE: k = dimensón, n = nodos, treeType = tipo de árbol (0-standard, 1-relaxed, 2-squarish)
    // POST: Constructora árbol aleatorio
    BinaryTree(int k, int n, int treeType);

    // PRE: a = coord. nodo
    // POST: Insertar nodo standard base
    void insert(const vector<double>& a);

    // PRE: Ø
    // POST: Print árbol
    void print2D();

    // PRE: Ø
    // POST: Borrar el árbol
    void BorrarInit();

    // PRE: origen = coord. origen
    // POST: Devuelve el vecino mas cercano al punto origen
    vector<double> nearestNeighbor(const vector<double>& origen);

    // PRE: origen = coord. origen
    // POST: Devuelve el vecino mas cercano al punto origen LINEAL
    vector<double> nearestNeighborLINEAL(const vector<double>& origen);

    // PRE: Ø
    // POST: Mirar numero de nodos recorridos y inicializar a 0
    int checkNumNodes();

    // PRE: a = coord. nodo
    // POST: Insertar nodo tipo relaxed base
    void insertRelaxed(const vector<double>& a);

    // PRE: a = coord. nodo
    // POST: Insertar nodo tipo squarish base
    void insertSquarish(const vector<double>& a);

};

#endif
