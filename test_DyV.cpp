#include <vector>
#include "DyV.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	int vector_prueba[10] = {0,1,2,3,4,5,6,7,8,9};
	int vector_prueba_inv[10] = {9,8,7,6,5,4,3,2,1,0};

	srand(time(NULL));

	int n = rand() % 10;

	cout << "Dado un vector con los números del 0 al 9 ordenados: " << endl;

	cout << "Buacamos el número " << n << endl;
	cout << "El número se encuentra en la posición " << BusquedaBinaria(n, vector_prueba, 0, 10) << endl;


	cout << "En el caso de tener un vector ordenado en orden inverso ..." << endl;
	cout << "Buacamos el número " << n << endl;
        cout << "El número se encuentra en la posición " << BusquedaBinaria_INV(n, vector_prueba_inv, 0, 10) << endl;

	return 0;
}
