/*Busqueda binaria*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int busquedaSecuencial(int , int [], int);
void interDirIz( int [], int);
int main(){
	int m, arr[100], n, dato, p;
	srand(time(0));
	
	cout << "Digite la cantidad de terminos del arreglo: " << endl;
	cin >> m;
	
	cout << endl;
	
	//arreglo generado de numeros
	
	for(int i = 0; i<m; i++){
		arr[i] = rand()% 100;
	}
	
 	interDirIz(arr, m);

	cout << endl;
	
	cout << "Digite el numero que esta buscando: " << endl;
	cin >> dato;
	
	cout << "MENU: " << endl;
	cout << "1. Busqueda por seleccion " << endl;
	cout << "2. Busqueda binaria " << endl;
	cout << "3. Salir." << endl;
	cout << "Opcion: " << endl;
	cin >> n;
	
	switch(n){
		case 1:
			 p = busquedaSecuencial(m, arr, dato);
			 if (p >= 0){
			 
                cout << "El numero se encuentra en la posicion " << p+1 << " del primer arreglo. " << endl;
            }else{
			
                cout << "El numero no se encuentra en el arreglo." << endl;
			}
            
			break;
			
		case 2:
			//busquedaBinaria(m, arr);
			break;
			
		case 3:
			cout << "Saliendo..." << endl;
			break;
		default: 
			cout << "Numero incorrecto..." << endl;
	}
	return 0;
}

void interDirIz(int arr[], int m){
	int aux;
	cout << "El arreglo es: " << endl;
	
	for (int i = 0; i<m-1; i++){
		for ( int j = m-1; j>i; j--){
			if (arr[j] < arr[j-1]){
				aux = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = aux;
			}
		}
	}
	
	for ( int i = 0; i<m; i++){
		cout << arr[i] << " ";
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