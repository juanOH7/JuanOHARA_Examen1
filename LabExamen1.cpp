#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::abs;

int**newArray();
void imprimirTablero(int**, int);
void llenarTablero(int**, int);
void deletePunteros(int**,int);

int main(int argc, char const *argv[]){
	int size = 7, turno=1, posX, posY, posXMover, posYMover;
	bool contJuego = true, turnoValidoSel == true, turnoValidoMov = true;
	int** tablero = newArray();
	llenarTablero(tablero, size);
	imprimirTablero(tablero, size);
	do{
		if (turno == 1){
			while(turnoValidoSel){
				turnoValido = validarTurnoJUg1Sel(arreglo, posX, posY);
				if (turnoValido == true){
					cout << "Posicion no valida!!";
				}
			}
			turno = 2;
		}else if(turno == 2){
			turno = 1;
		}
	} while (contJuego);
	deletePunteros(tablero,size);
	return 0;
}
void turnoMover(int &posX, int &posY){
	cout << "ingrese las coordenadas que quiere mover" << endl;
	cout << "Pos X :" << endl;
	cin >> posX;
	cout << "Pos Y :" << endl;
	cin >> posY;
}
void imprimirTablero(int** arreglo, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if (arreglo[i][j] == 1){
				cout << "[J]" ;
			}else if (arreglo[i][j] == 2){
				cout << "[P]" ;
			}else {
				cout << "[ ]";
			}
		}
		cout << "" << endl;
	}
}
void llenarTablero(int** arreglo, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0;j < size; ++j){
			if( ( i == 0 && j == 3) || (i == 6 && j == 3) ){
				arreglo[i][j] = 1;
			}else if( (i == 3 && j == 0) || (i == 3&&j == 6) ){
				arreglo[i][j] = 2;
			}else{
				arreglo[i][j] = 0;
			}
		}
	}
}
int**newArray(){
	int size=7;
	int**arreglo= new int*[size];
	for (int i = 0; i < size; ++i){
		arreglo[i]=new int[7];
	}
	for (int j = 0; j < size; ++j){
			arreglo[j]= new int[7];
	}
	//fin new
	return arreglo;
}
bool validarTurnoJUg1Sel(int** arreglo, int x, int y){
	if (arreglo[x][y] == 0){
		return true;
	}else if(arreglo[x][y] == 1){
		return false;
	}else {
		return true;
	}
}
bool validarTurnoJUg2Sel(int** arreglo, int x, int y){
	if (arreglo[x][y] == 0){
		return true;
	}else if(arreglo[x][y] == 2){
		return false;
	}else {
		return true;
	}
}
void deletePunteros(int** arreglo, int size){
	for (int i = 0; i < size; ++i)
	{
			delete[] arreglo[i];	
	}
	delete[] arreglo;//fin delete
}