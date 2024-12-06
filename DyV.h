#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

//función para imprimir vectores
template <typename T>
void imprimir_vector(T v[], int tamanyo){

	cout << "{";

	for(int i = 0; i<tamanyo; i++){
                cout << v[i];
                if(i < tamanyo-1){
                        cout << ", ";
                }else{
                        cout << "}" << endl;
                }
        }
}


template <typename T>
int BusquedaBinaria(T x, T v[], int ini, int fin){

	if(ini > fin){
		return -1; //No se encuentra en el array
	}

	int medio = (ini + fin)/2;

	if(v[medio] == x){
		return medio;
	}else if(v[medio] > x){
		return BusquedaBinaria(x, v, ini, medio-1);
	}else{
		return BusquedaBinaria(x, v, medio+1, fin);
	}

}

template <typename T>
int BusquedaBinaria_INV(T x, T v[], int ini, int fin){

        if(ini > fin){
                return -1; //No se encuentra en el array
        }

        int medio = (ini + fin)/2;

        if(v[medio] == x){
                return medio;
        }else if(v[medio] < x){
                return BusquedaBinaria_INV(x, v, ini, medio-1);
        }else{
                return BusquedaBinaria_INV(x, v, medio+1, fin);
        }

}


template <typename T>
int Partition(T v[], int ini, int fin){

	T x = v[fin];
	int i = ini;

	for(int j = ini; j <= fin-1; j++){
		if(v[j] <= x){
			T aux = v[i];
			v[i] = v[j];
			v[j] = aux;

			i++;
		}
	}
	
	T aux = v[i];
        v[i] = v[fin];
        v[fin] = aux;

	return i;
}


template <typename T>
void QuickSort(T v[], int ini, int fin){
        if(ini < fin){
                int pivot = Partition(v, ini, fin);

                QuickSort(v, ini, pivot-1);
                QuickSort(v, pivot+1, fin);
        }
}


template <typename T>
int Partition_mid(T v[], int ini, int fin) {
    
    int mid = ini + (fin - ini) / 2;
    T x = v[mid];


    T aux = v[mid];
    v[mid] = v[fin];
    v[fin] = aux;

    int i = ini;

    for (int j = ini; j <= fin - 1; j++) {
        if (v[j] <= x) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
    }

    aux = v[i];
    v[i] = v[fin];
    v[fin] = aux;

    return i;
}

template <typename T>
void QuickSort_mid(T v[], int ini, int fin){
        if(ini < fin){
                int pivot = Partition_mid(v, ini, fin);

                QuickSort(v, ini, pivot-1);
                QuickSort(v, pivot+1, fin);
        }
}



template <typename T>
int Partition_ini(T v[], int ini, int fin) {
    T x = v[ini];
    int i = ini + 1;

    for (int j = ini + 1; j <= fin; j++) {
        if (v[j] <= x) {
            T aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
    }

    
    T aux = v[i - 1];
    v[i - 1] = v[ini];
    v[ini] = aux;

    return i - 1;
}

template <typename T>
void QuickSort_ini(T v[], int ini, int fin){
        if(ini < fin){
                int pivot = Partition_ini(v, ini, fin);

                QuickSort(v, ini, pivot-1);
                QuickSort(v, pivot+1, fin);
        }
}
