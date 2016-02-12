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
void ataquenormal(int x, int y, int z, int*** &arreglo, int &naves);
void ataqueExpansive(int x, int y, int z, int*** &arreglo, int &naves);
void ataquewaveXY(int z, int*** &arreglo, int &naves);
void ataquewaveXZ(int y, int*** &arreglo, int &naves);
void ataquewaveYZ(int x, int*** &arreglo, int &naves);

int main(int argc, char*argv[]){
	int size = 12;
	int*** arreglo1 = crear();
	int*** arreglo2 = crear();
	int naves1 = 15, naves2 = 15;
	int turno = 1, menu = 0;
	int waves1 = 3, waves2 = 3, expansive1 = 3, expansive2 = 3;
	int x,y,z;
	bool validar = true;
	AsignarNaves(arreglo1);
	AsignarNaves(arreglo2);
	while (naves1 != 0 && naves2 != 0){
		if (turno == 1){
			cout << "-------------------------JUGADOR-1---------------------------------" << endl;
			turno++;
			ImprimirNaves(arreglo1);
			cout << "Le quedan " << naves2 << " por destruir" << endl;
			cout << "Tiene " << waves1 << " ataques wave restantes" << endl;
			cout << "Tiene " << expansive1 << " ataques expansive restantes" << endl;
			while (validar){
				cout << "1: Ataque Normal\n2: Ataque Wave\n3: Ataque Expansive" << endl;
				cin >> menu;				
				if (menu == 2 && waves1 == 0){
					cout << "No tiene mas ataques wave" << endl;
				}else if (menu == 3 && expansive1 == 0){
					cout << "No tiene mas ataques expansive" << endl;
				}else{
					validar = false;
				}
			}
			validar = true;
			if (menu == 1){
				while (validar){
					cout << "Ingrese coordinada x: ";
					cin >> x;
					cout << "Ingrese coordinada y: ";
					cin >> y;
					cout << "Ingrese coordinada z: ";
					cin >> z;
					if (x < 0 || x > 11)
						cout << "La cordenada x tiene que estar entre 0 y 11" << endl;
					else if (y < 0 || y > 11)
						cout << "La cordenada y tiene que estar entre 0 y 11" << endl;
					else if (z < 0 || z > 11)
						cout << "La cordenada z tiene que estar entre 0 y 11" << endl;
					else
						validar = false;
				}
				validar = true;
				ataquenormal(x,y,z,arreglo2,naves2);
			}else if (menu == 2){
				cout << "1: XY\n2: XZ\n3: YZ\n";
				cin >> menu;
				if (menu == 1){
					while(validar){
						cout << "Ingrese el valor de Z: " << endl;
						cin >> z;
						if (z < 0 || z > 11)
							cout << "La coordenada z tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveXY(z,arreglo2,naves2);
				}
				if (menu == 2){
					while(validar){
						cout << "Ingrese el valor de Y: " << endl;
						cin >> y;
						if (y < 0 || y > 11)
							cout << "La coordenada z tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveXZ(y,arreglo2,naves2);
				}
				if (menu == 3){
					while(validar){
						cout << "Ingrese el valor de X: " << endl;
						cin >> x;
						if (x < 0 || x > 11)
							cout << "La coordenada z tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveYZ(x,arreglo2,naves2);
				}
			}else if (menu == 3){

			}
		}else{
			cout << "-------------------------JUGADOR-2---------------------------------" << endl;
			ImprimirNaves(arreglo2);
			turno --;
			cout << "Le quedan " << naves1 << " por destruir" << endl;
			cout << "Tiene " << waves2 << " ataques wave restantes" << endl;
			cout << "Tiene " << expansive2 << " ataques expansive restantes" << endl;
			while (validar){
				cout << "1: Ataque Normal\n2: Ataque Wave\n3: Ataque Expansive" << endl;
				cin >> menu;				
				if (menu == 2 && waves2 == 0){
					cout << "No tiene mas ataques wave" << endl;
				}else if (menu == 3 && expansive2 == 0){
					cout << "No tiene mas ataques expansive" << endl;
				}else{
					validar = false;
				}
			}
			validar = true;
			if (menu == 1){
				while (validar){
					cout << "Ingrese coordinada x: ";
					cin >> x;
					cout << "Ingrese coordinada y: ";
					cin >> y;
					cout << "Ingrese coordinada z: ";
					cin >> z;
					if (x < 0 || x > 11)
						cout << "La cordenada x tiene que estar entre 0 y 11" << endl;
					else if (y < 0 || y > 11)
						cout << "La cordenada y tiene que estar entre 0 y 11" << endl;
					else if (z < 0 || z > 11)
						cout << "La cordenada z tiene que estar entre 0 y 11" << endl;
					else
						validar = false;
				}
				validar = true;
				ataquenormal(x,y,z,arreglo1,naves1);
			}else if (menu == 2){
				cout << "1: XY\n2: XZ\n3: YZ\n";
				cin >> menu;
				if (menu == 1){
					while(validar){
						cout << "Ingrese el valor de Z: " << endl;
						cin >> z;
						if (z < 0 || z > 11)
							cout << "La coordenada z tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveXY(z,arreglo1,naves1);
				}
				if (menu == 2){
					while(validar){
						cout << "Ingrese el valor de Y: " << endl;
						cin >> y;
						if (y < 0 || y > 11)
							cout << "La coordenada z tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveXZ(y,arreglo1,naves1);
				}
				if (menu == 3){
					while(validar){
					cout << "Ingrese el valor de X: " << endl;
					cin >> x;
						if (x < 0 || x > 11)
							cout << "La coordenada x tiene que estar entre 0 y 11" << endl;
						else
							validar = false;
					}
					validar = true;
					ataquewaveYZ(x,arreglo1,naves1);
				}
			}else if (menu == 3){
				
			}
		}
	}
	if (naves1 == 0)
		cout << "HA GANADO EL JUGADOR 2" << endl;
	else if (naves2 == 0)
		cout << "HA GANADO EL JUGADOR 1" << endl;
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
void ataquenormal(int x, int y, int z, int*** &arreglo, int &naves){
	if (arreglo[x][y][z] == 2){
		naves--;
		cout << "Destruyo la nave en el punto: (" << x << "," << y << "," << z << ")" << endl;
		arreglo[x][y][z] = 1;
	}
}
void ataqueExpansive(int x, int y, int z, int*** &arreglo, int &naves){

	if(x>0 || y>0 || z>0 || x<11 || y<11 || z<11){	

		for(int i=x-1;i<x+2;i++){
			for(int j=y-1;j<x+2;j++){
				for(int w=z-1;w<x+2;w++){
					if(arreglo[i][j][w]==2){
						cout << "Nave destruida" << endl;
						naves--;
						arreglo[i][j][w]=1;
					}	
				}
			}
		}
	}
}
void ataquewaveXY(int z, int*** &arreglo, int &naves){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			if (arreglo[i][j][z] == 2){
				cout << "Destruyo la nave en el punto: (" << i << "," << j << "," << z << ")" << endl;
				arreglo[i][j][z] = 1;
				naves--;
			} 	
		}
	}
}
void ataquewaveXZ(int y, int*** &arreglo, int &naves){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			if (arreglo[i][y][j] == 2){
				cout << "Destruyo la nave en el punto: (" << i << "," << y << "," << j << ")" << endl;
				arreglo[i][y][j] = 1;
				naves--;
			} 	
		}
	}
}
void ataquewaveYZ(int x, int*** &arreglo, int &naves){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			if (arreglo[x][i][j] == 2){
				cout << "Destruyo la nave en el punto: (" << x << "," << i << "," << j << ")" << endl;
				arreglo[x][i][j] = 1;
				naves--;
			} 
		}
	}
}
