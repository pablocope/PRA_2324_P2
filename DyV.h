#include <vector>

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
