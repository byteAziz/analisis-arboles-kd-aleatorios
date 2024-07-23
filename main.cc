#include <iostream>
#include <random>
#include <omp.h>
#include "Tree.hh"
using namespace std;

int main() {
    //Creación funte, semilla, distribución y generador
    random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    uniform_real_distribution<double> Uniforme(0.0, 1.0);
    default_random_engine RNG(seed);

    //Pregunta de variables 
    int k, n, t, q, typeTree;
    cout << "Elige tipo de arbol (0-kd, 1-Relaxed, 2-Squarish): ";
    cin >> typeTree;
    while(typeTree < 0 or typeTree > 2) cin >> typeTree;
    cout << "Valor de k: ";
    cin >> k;
    cout << "Valor de n: ";
    cin >> n;
    cout << "Numero de arboles: ";
    cin >> t;
    cout << "Consultas por arbol: ";
    cin >> q;

    //Bucle generador de arboles
    int sum = 0;
    for(int i = 0; i < t; i++) {
        BinaryTree Arbol(k, n, typeTree);

        //Paralelización del bucle de consultas
        #pragma omp parallel for num_threads(omp_get_max_threads()) reduction(+:sum)
        for(int j = 0; j < q; j++) {
            vector<double> consulta(k);
            for(int l = 0; l < k; l++) consulta[l] = Uniforme(RNG);

            //Busqueda del vecino mas cercano
            vector<double> vecino = Arbol.nearestNeighbor(consulta);

            sum += Arbol.checkNumNodes();    //Num. total de nodos recorridos
        }
        Arbol.BorrarInit();
    }
    //Media de nodos recorridos por consulta
    cout << endl << "Numero medio de nodos visitados: " << sum/(t*q) << endl;
}
