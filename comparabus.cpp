/*Busqueda binaria*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
using namespace std;

int busquedaSecuencial(int , int [], int);
void seleccionDirecta( int [], int);
int busquedaBinaria(int, int[], int);

int main(){
	int m, arr[80000], n, dato, p, dc;
	srand(time(0));
	
	cout << "Digite la cantidad de terminos del arreglo: " << endl;
	cin >> m;
	
	cout << endl;
	
	//arreglo generado de numeros
	
	for(int i = 0; i<m; i++){
		arr[i] = rand()% 100000;
	}
	
 	seleccionDirecta(arr, m);

	cout << endl;
	
	do{
		
	
	cout << "Digite el numero que esta buscando: " << endl;
	cin >> dato;
	
	
	cout << "MENU: " << endl;
	cout << "1. Busqueda por seleccion " << endl;
	cout << "2. Busqueda binaria " << endl;
	cout << "3. Salir." << endl;
	cout << "Opcion: " << endl;
	cin >> n;
	
	// Variables para medir el tiempo
	auto start = chrono::high_resolution_clock::now(); 
	auto end = chrono::high_resolution_clock::now();
	
	switch(n){
		case 1:{
			
			
            const int NUM_BUSQUEDAS = 30000; // Realiza 30,000 búsquedas del mismo dato
            start = chrono::high_resolution_clock::now(); // Iniciar el tiempo

            for (int i = 0; i < NUM_BUSQUEDAS; i++) {
                p = busquedaSecuencial(m, arr, dato); // Repetir la búsqueda
            }

            end = chrono::high_resolution_clock::now(); // Finalizar el tiempo
            
            if (p >= 0){
                cout << "El numero se encuentra en la posicion " << p+1 << " del primer arreglo." << endl;
            } else {
                cout << "El numero no se encuentra en el arreglo." << endl;
            }

            // Calcular la duración
            chrono::duration<double> duration = end - start;
            cout << "\nTiempo total de ejecucion para " << NUM_BUSQUEDAS << " búsquedas: " 
                 << duration.count() << " segundos" << endl;
        
        
        	break;
		}
		case 2:{
			
			const int NUM_BUSQUEDAS = 30000; // Realiza 30,000 búsquedas del mismo dato
            start = chrono::high_resolution_clock::now(); // Iniciar el tiempo
			
			for (int i = 0; i < NUM_BUSQUEDAS; i++) {
				p = busquedaBinaria(m, arr, dato);
			}
			
			end = chrono::high_resolution_clock::now(); // Finalizar el tiempo
			
			 if (p >= 0) {
                cout << "El numero se encuentra en la posicion " << p + 1 << " del arreglo." << endl;
            } else {
                cout << "El numero no se encuentra en el arreglo." << endl;
            }
             // Calcular la duración
            chrono::duration<double> duration = end - start;
            cout << "\nTiempo total de ejecucion para " << NUM_BUSQUEDAS << " busquedas: " 
                 << duration.count() << " segundos" << endl;
            
			break;
		}
		
		case 3:
			cout << "Saliendo..." << endl;
			break;
		default: 
			cout << "Numero incorrecto..." << endl;
	}
	
	cout << endl;
	
	cout << "Si desea continuar escriba un numero: (1)SI o (0)NO " << endl;
	cin >> dc;
	}while(dc == 1);
	
	return 0;
}

void seleccionDirecta(int arr[], int m){
	int menor, k;
	
	//Algoritmo del metodo de seleccion directa
	for (int i = 0; i<m-1; i++){
		menor = arr[i];
		k = i;
		for(int j = i+1; j<m; j++){
			if (menor > arr[j]){
				menor = arr[j];
				k = j;
			}
		}
		arr[k] = arr[i];
		arr[i] = menor;
	}
	
}

int busquedaSecuencial(int m, int arr[], int dato){
	int i = 0, pos;
	
	while((i <= m-1) && (arr[i]<dato)){
		i++;
	}
	
	if ((i>m-1) || (arr[i] > dato)){
		return pos = -i;

	}else{
		return pos = i;

	}
	
}

int busquedaBinaria(int m, int arr[], int dato){
	int izq = 0, der = m - 1;

    while (izq <= der) {
        int n = (izq + der) / 2;
        if (arr[n] == dato) {
            return n; 
        } else {
            if (dato > arr[n]) {
                izq = n + 1;
            } else {
                der = n - 1;
            }
        }
    }

    return -1; 
}
