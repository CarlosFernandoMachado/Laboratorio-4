# include <iostream>

using std::cout;
using std::cin;
using std::endl;

void borrar(int*** arreglo[], int size);
int*** crear();
void AsignarNaves(int*** x);

int main(int argc, char*argv[]){
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
void AsignarNaves(int*** x){

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
			x[ran1][ran2][ran3]==2;
			naves--;
		}else{

		}
	}	
}
