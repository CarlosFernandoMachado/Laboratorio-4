# include <iostream>

using std::cout;
using std::cin;
using std::endl;

void borrar(int*** arreglo[], int size);
int*** crear();

int main(int argc, char*argv[]){
	int size = 12;
	int*** arreglo1 = crear();
	int*** arreglo2 = crear();
	
	return 0;
}

void borrar(int*** arreglo[], int size){
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			delete[] arreglo[i][j];
	for (int i = 0; i < size; i++)
		delete[] arreglo[i];
	delete[] arreglo;
}
int*** crear(){
	int size = 12;
	int*** arreglo = new int**[size];
	for (int i = 0; i < size; i++)
		arreglo[i] = new int* [size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arreglo[i][j] = new int[size];
	return arreglo;
}
