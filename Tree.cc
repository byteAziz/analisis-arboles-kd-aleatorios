#include "Tree.hh"

BinaryTree::BinaryTree(int d) {
    k = d;
    arrel = nullptr;
}

void BinaryTree::BorrarInit() {
    BorrarBinaryTree(arrel);
    arrel = nullptr;
}

void BinaryTree::BorrarBinaryTree(node* n) {
    if (n != nullptr) {
        BorrarBinaryTree(n->left);
        BorrarBinaryTree(n->right);
        delete n;
    }
}

void BinaryTree::insert(const vector<double>& a) {
    arrel = insertRecursive(arrel, a, 0);
}

BinaryTree::node* BinaryTree::insertRecursive(node* actual, const vector<double>& c, int height) {
    if (actual == nullptr) {     // Creación nodo para la posción buscada
        node* newNode = new node;
        newNode->clau = c;
        newNode->j = height % k;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Búsqueda de la posción del nodo
    int dimension = height % k;
    if (c[dimension] < actual->clau[dimension])
        actual->left = insertRecursive(actual->left, c, height + 1);
    else
        actual->right = insertRecursive(actual->right, c, height + 1);

    return actual;
}

BinaryTree::BinaryTree(int k, int n, int treeType) {
    //Creación funte, semilla, distribución y generador
    random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    uniform_real_distribution<double> Uniforme(0.0, 1.0);
    default_random_engine RNG(seed);

    // Bucle de inserción de nodos con coordenadas aleatorias
    arrel = nullptr;
    this->k = k;
    vector<double> values(k);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; i++) values[i] = Uniforme(RNG);

        if(treeType == 0) insert(values);
        else if (treeType == 1) insertRelaxed(values);
        else if (treeType == 2) insertSquarish(values);
    }
}

double BinaryTree::CalcDistancia(const vector<double>& P, const vector<double>& Q) {
    double distancia = 0.0;
    for(int i = 0; i < k; i++) {
        distancia += pow(P[i] - Q[i], 2);
    }
    return sqrt(distancia);
}

vector<double> BinaryTree::nearestNeighbor(const vector<double>& origen) {
    if (arrel == nullptr) return{}; // Árbol vacio

    node* vecino = nullptr;
    double millorDistancia = numeric_limits<double>::max();

    nearestNeighbor(arrel, origen, vecino, millorDistancia);
    if (vecino != nullptr) return vecino->clau;
    else return {};
}

void BinaryTree::nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia) {
    if (actual == nullptr) return;
    ++count; // Contador de nodos visitados

    // Calculo mejor distancia
    double actualDistancia = CalcDistancia(actual->clau, origen);
    if (actualDistancia < millorDistancia) {
            vecino = actual;
            millorDistancia = actualDistancia;
    }

    int j = actual->j;
    double valorOrigen = origen[j];
    double valorActual = actual->clau[j];

    // Valorar que hijos explorar en la busqueda
    if (valorOrigen < valorActual) {
        nearestNeighbor(actual->left, origen, vecino, millorDistancia);
        if (valorActual - valorOrigen <= millorDistancia) {
            nearestNeighbor(actual->right, origen, vecino, millorDistancia);
        }
    } else {
        nearestNeighbor(actual->right, origen, vecino, millorDistancia);
        if (valorOrigen - valorActual <= millorDistancia) {
            nearestNeighbor(actual->left, origen, vecino, millorDistancia);
        }
    }
}

int BinaryTree::checkNumNodes() {
    int aux = count;
    count = 0;
    return aux;
}

void BinaryTree::insertRelaxed(const vector<double>& a) {
    arrel = insertRelaxed(arrel, a);
}

BinaryTree::node* BinaryTree::insertRelaxed(node* actual, const vector<double>& c) {
    if (actual == nullptr) { // Creación nodo para la posción buscada; discriminante aleatorio
        random_device myRandomDevice;
        unsigned seed = myRandomDevice();
        uniform_int_distribution<int> Uniforme(0, k-1);
        default_random_engine RNG(seed);
        

        node* newNode = new node;
        newNode->clau = c;
        newNode->j = Uniforme(RNG);
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Búsqueda de la posción del nodo
    int dimension = actual->j;
    if (c[dimension] < actual->clau[dimension])
        actual->left = insertRelaxed(actual->left, c);
    else
        actual->right = insertRelaxed(actual->right, c);

    return actual;
}

void BinaryTree::insertSquarish(const vector<double>& a) {
    vector<pair<double, double>> minIMaxIni(a.size(), {0.0, 1.0});
    arrel = insertSquarish(arrel, a, minIMaxIni);
}

BinaryTree::node* BinaryTree::insertSquarish(node* actual, const vector<double>& c, vector<pair<double,double>> minIMax) {
    if (actual == nullptr) {      // Creación nodo para la posción buscada y elección de discriminante según lado mas largo de la "bounding box"
        node* newNode = new node;
        newNode->clau = c;
        int h = 0;
        double dist = minIMax[0].second - minIMax[0].first;

        for (int i = 1; i < k; i++) {
            double newDist = minIMax[i].second - minIMax[i].first;
            if (newDist >= dist) {
                h = i;
                dist = newDist;
            }
        }
        
        newNode->j = h % k;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Búsqueda de la posción del nodo + actualización "bounding box"
    int dimension = actual->j;
    if (c[dimension] < actual->clau[dimension]) {
        minIMax[dimension].second = actual->clau[dimension];
        actual->left = insertSquarish(actual->left, c, minIMax);
    }
    else {
        minIMax[dimension].first = actual->clau[dimension];
        actual->right = insertSquarish(actual->right, c, minIMax);
    }

    return actual;
}

vector<double> BinaryTree::nearestNeighborLINEAL(const vector<double>& origen) {
    if (arrel == nullptr) return{}; // arbre buit

    node* vecino = nullptr;
    double millorDistancia = numeric_limits<double>::max();

    nearestNeighborLINEAL(arrel, origen, vecino, millorDistancia);
    if (vecino != nullptr) return vecino->clau;
    else return {};
}


void BinaryTree::nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia) {
    if (actual == nullptr) return;
    ++count;

    double actualDistancia = CalcDistancia(actual->clau, origen);

    if (actualDistancia < millorDistancia and actualDistancia != 0.0) {
            vecino = actual;
            millorDistancia = actualDistancia;
    }
    //IZQUIERDA
    nearestNeighborLINEAL(actual->left, origen, vecino, millorDistancia);
    //DERECHA
    nearestNeighborLINEAL(actual->right, origen, vecino, millorDistancia);
}

void BinaryTree::print2DUtil(node* root, int space)
{
    if (root == nullptr)
        return;

    const int spaceIncrement = 10;

    print2DUtil(root->right, space + spaceIncrement);

    cout << endl << string(space, ' ');

    cout << root->j << " ";

    cout << endl;

    print2DUtil(root->left, space + spaceIncrement);
}

void BinaryTree::print2D()
{
    print2DUtil(arrel, 0); //space = 0
}

