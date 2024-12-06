#include <vector>
#include "DyV.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int main(){

	//int vector_prueba[10] = {0,1,2,3,4,5,6,7,8,9};
	//int vector_prueba_inv[10] = {9,8,7,6,5,4,3,2,1,0};

	srand(time(NULL));

	//generamos un vector aleatorio desordenado
	int vector_desordenado[10], vector_desordenado2[10], vector_desordenado3[10];

	cout << "El vector generado es: ";

	for(int i = 0; i<10; i++){
		vector_desordenado[i] = rand() % 10;
		vector_desordenado2[i] = vector_desordenado[i];
		vector_desordenado3[i] = vector_desordenado[i];
	}
	imprimir_vector(vector_desordenado, 10);
	
	auto start = chrono::system_clock::now();
	//ordenamos el vector
	QuickSort(vector_desordenado, 0, 9);
	auto end = chrono::system_clock::now();
	chrono::duration<float, milli> duration = end - start;
	cout << "Duración QuickSort (pivote fin): " << duration.count() << "s" << std::endl;

	imprimir_vector(vector_desordenado, 10);

	auto start = chrono::system_clock::now();
        //ordenamos el vector
        QuickSort_mid(vector_desordenado2, 0, 9);
        auto end = chrono::system_clock::now();
        chrono::duration<float, milli> duration = end - start;
        cout << "Duración QuickSort (pivote mid): " << duration.count() << "s" << std::endl;

	imprimir_vector(vector_desordenado2, 10);

	auto start = chrono::system_clock::now();
        //ordenamos el vector
        QuickSort_ini(vector_desordenado3, 0, 9);
        auto end = chrono::system_clock::now();
        chrono::duration<float, milli> duration = end - start;
        cout << "Duración QuickSort (pivote ini): " << duration.count() << "s" << std::endl;

	imprimir_vector(vector_desordenado3, 10);

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
