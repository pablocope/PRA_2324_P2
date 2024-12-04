#include <vector>
#include "DyV.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TAMANYO 10

int main(){

	//int vector_prueba[10] = {0,1,2,3,4,5,6,7,8,9};
	//int vector_prueba_inv[10] = {9,8,7,6,5,4,3,2,1,0};

	srand(time(NULL));

	//generamos un vector aleatorio desordenado
	int vector_desordenado[10];

	cout << "El vector generado es: {";

	for(int i = 0; i<10; i++){
		vector_desordenado[i] = rand() % 10;
		cout << vector_desordenado[i];
		if(i < 9){
			cout << ", ";
		}else{
			cout << "}" << endl;
		}
	}

	//ordenamos el vector
	QuickSort(vector_desordenado, 0, 10);

        for(int i = 0; i<10; i++){
                cout << vector_desordenado[i];
                if(i < 9){
                        cout << ", ";
                }else{
                        cout << "}" << endl;
                }
        }

	//buscamos un número aleatorio a ver si está
	int n = rand() % 10;

	cout << "Dado un vector con los números del 0 al 9 ordenados: " << endl;

	cout << "Buacamos el número " << n << endl;
	cout << "El número se encuentra en la posición " << BusquedaBinaria(n, vector_desordenado, 0, 10) << endl;

/*
	cout << "En el caso de tener un vector ordenado en orden inverso ..." << endl;
	cout << "Buacamos el número " << n << endl;
        cout << "El número se encuentra en la posición " << BusquedaBinaria_INV(n, vector_prueba_inv, 0, 10) << endl;
*/
	return 0;
}
