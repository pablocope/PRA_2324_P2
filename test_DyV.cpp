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
	
	auto start_fin = std::chrono::system_clock::now();
    	QuickSort(vector_desordenado, 0, 9);
    	auto end_fin = std::chrono::system_clock::now();
    	std::chrono::duration<float, std::milli> duration_fin = end_fin - start_fin;
    	cout << "Duración QuickSort (pivote fin): " << duration_fin.count() << "ms" << std::endl;

    	imprimir_vector(vector_desordenado, 10);

    	// QuickSort con pivote en el medio
    	auto start_mid = std::chrono::system_clock::now();
    	QuickSort_mid(vector_desordenado2, 0, 9);
    	auto end_mid = std::chrono::system_clock::now();
    	std::chrono::duration<float, std::milli> duration_mid = end_mid - start_mid;
    	cout << "Duración QuickSort (pivote mid): " << duration_mid.count() << "ms" << std::endl;

    	imprimir_vector(vector_desordenado2, 10);

    	// QuickSort con pivote al inicio
    	auto start_ini = std::chrono::system_clock::now();
    	QuickSort_ini(vector_desordenado3, 0, 9);
    	auto end_ini = std::chrono::system_clock::now();
    	std::chrono::duration<float, std::milli> duration_ini = end_ini - start_ini;
	cout << "Duración QuickSort (pivote ini): " << duration_ini.count() << "ms" << std::endl;

    	imprimir_vector(vector_desordenado3, 10);

	//buscamos un número aleatorio a ver si está
	int n = rand() % 10;

	cout << "Dado un vector con los números del 0 al 9 ordenados: " << endl;
	cout << "Buacamos el número " << n << endl;
	
	if(BusquedaBinaria(n, vector_desordenado, 0, 10) >= 0){
		cout << "El número se encuentra en la posición " << BusquedaBinaria(n, vector_desordenado, 0, 10) << endl;
	}else{
		cout << "El número no se encuentra en el array" << endl;
	}

/*	
 *	//PARA EL QUICK SORT INVERSO
 *	cout << "En el caso de tener un vector ordenado en orden inverso ..." << endl;
 *	cout << "Buacamos el número " << n << endl;
 *      cout << "El número se encuentra en la posición " << BusquedaBinaria_INV(n, vector_prueba_inv, 0, 10) << endl;
*/
	return 0;
}
