# include <iostream>
#include <ctime>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;

void borrar(int*** &arreglo, int size);
int*** crear();
void AsignarNaves(int*** &x);
void ImprimirNaves(int*** x);

int main(int argc, char*argv[]){
	int size = 12;
	int*** arreglo1 = crear();
	int*** arreglo2 = crear();
	int naves1 = 0, naves2 = 0;
	int turno = 1, menu = 0;
	int waves1 = 3, waves2 = 3, expansive1 = 3, expansive2 = 3;
	AsignarNaves(arreglo1);
	AsignarNaves(arreglo2);
	while (naves1 != 0 || naves2 != 0){
		if (turno == 1){
			turno++;
			ImprimirNaves(arreglo1);
			cout << "Le quedan " << naves2 << " por destruir" << endl;
			cout << "Tiene " << waves1 << " ataques wave restantes" << endl;
			cout << "Tiene " << expansive1 << " ataques expansive restantes" << endl;
			cout << "1: Ataque Normal\n2: Ataque Wave\n3: Ataque Expansive" << endl;
			if (menu == 1){

			}else if (menu == 2){

			}else if (menu == 3){

			}
		}else{
			ImprimirNaves(arreglo2);
			turno --;
			cout << "Le quedan " << naves1 << " por destruir" << endl;
			cout << "Tiene " << waves2 << " ataques wave restantes" << endl;
			cout << "Tiene " << expansive2 << " ataques expansive restantes" << endl;
			cout << "1: Ataque Normal\n2: Ataque Wave\n3: Ataque Expansive" << endl;
			if (menu == 1){

			}else if (menu == 2){

			}else if (menu == 3){

			}
		}
	}
	borrar(arreglo1,size);
	borrar(arreglo2,size);
	return 0;
}

void borrar(int*** &arreglo, int size){
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
void AsignarNaves(int*** &x){

	int naves=15,ran1,ran2,ran3;
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			for(int w=0;w<12;w++){
				x[i][j][w]=1;
			}	
		}
	}
	while(naves!=0){

		srand(time(NULL));
		ran1 = rand()%12+0;
		ran2 = rand()%12+0;
		ran3 = rand()%12+0;		

		if(x[ran1][ran2][ran3]==1){
			x[ran1][ran2][ran3]=2;
			naves--;
		}else{

		}
	}	
}
void ImprimirNaves(int*** x){
	
	cout << "----------NAVES----------" << endl;

	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			for(int w=0;w<12;w++){
				if(x[i][j][w]==2){
					cout << "Nave en posicion: " << "( " << i << "," << j << "," << w << " )" << endl;
				}
			}	
		}
	}
}
