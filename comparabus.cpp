
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int busquedaSecuencial(int, int[], int);
void metodoShell(int[], int);
int busquedaBinaria(int, int[], int);

int main() {
    int n, p, dc, num_busquedas, m;

    const int tam = 1000000; 
  
    int* arr = new int[tam];
    int* arr1 = new int[tam];

    srand(time(0));

    do {
        cout << "MENU: " << endl;
        cout << "1. Busqueda secuencial " << endl;
        cout << "2. Busqueda binaria " << endl;
        cout << "3. Salir." << endl;
        cout << "Opcion: ";
        cin >> n;
		
		cout << endl;
		
        cout << "Ingreso al menu, seleccionando la opcion: " << n << endl;
		
		cout << endl;

        cout << "Ingrese la cantidad de elementos del arreglo: ";
        cin >> m;
		
		cout << endl;
		
        switch (n) {
            case 1: {
                cout << "Ingrese el numero de busquedas secuenciales: ";
                cin >> num_busquedas;

                for (int i = 0; i < m; i++) {
                    arr1[i] = 1000 + rand() % 100000;
                }

                cout << "Arreglo generado con exito. Iniciando busqueda..." << endl;

                auto start = chrono::high_resolution_clock::now(); 

                for (int i = 0; i < num_busquedas; i++) {
                    int dato = arr1[rand() % m];
                    p = busquedaSecuencial(m, arr1, dato);
                }

                auto end = chrono::high_resolution_clock::now(); 

                chrono::duration<double> duration = end - start;
                cout << "Tiempo total para " << num_busquedas << " busquedas secuenciales: "
                    << duration.count() << " segundos" << endl;

                break;
            }

            case 2: {
                cout << "Ingrese el numero de busquedas binarias: ";
                cin >> num_busquedas;

                for (int i = 0; i < m; i++) {
                    arr[i] = 1000 + rand() % 100000;
                }

                metodoShell(arr, m);

                cout << "Arreglo ordenado con exito. Iniciando busqueda binaria..." << endl;

                auto start = chrono::high_resolution_clock::now(); 

                for (int i = 0; i < num_busquedas; i++) {
                    int dato = arr[rand() % m];
                    p = busquedaBinaria(m, arr, dato);
                }

                auto end = chrono::high_resolution_clock::now(); 

                chrono::duration<double> duration = end - start;
                cout << "Tiempo total para " << num_busquedas << " busquedas binarias: "
                    << duration.count() << " segundos" << endl;

                break;
            }

            case 3:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion incorrecta." << endl;
        }

        cout << "Desea continuar? (1)SI o (0)NO: ";
        cin >> dc;

    } while (dc == 1);

    // Liberar memoria dinámica
    delete[] arr;
    delete[] arr1;

    return 0;
}

void metodoShell(int arr[], int m) {
    int menor, k, cen, aux, j;

    // Algoritmo del método de Shell
    k = m / 2;

    while (k > 0) {
        cen = 1;
        while (cen == 1) {
            cen = 0;
            j = 0;
            while (j + k < m) {
                if (arr[j + k] < arr[j]) {
                    aux = arr[j];
                    arr[j] = arr[j + k];
                    arr[j + k] = aux;
                    cen = 1;
                }
                j++;
            }
        }
        k = k / 2; // Reducir el valor de k
    }
}

int busquedaSecuencial(int m, int arr1[], int dato) {
    for (int i = 0; i < m; i++) {
        if (arr1[i] == dato) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int m, int arr[], int dato) {
    int izq = 0, der = m - 1;

    while (izq <= der) {
        int n = (izq + der) / 2;
        if (arr[n] == dato) {
            return n;
        } else if (dato > arr[n]) {
            izq = n + 1;
        } else {
            der = n - 1;
        }
    }
    return -1;
}
