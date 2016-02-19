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
void moverPiezajug1(int**,int,int,int,int,double);
void moverPiezajug2(int**,int,int,int,int,double);
bool validarNOPiezaenPos(int**,int,int);
double distancia(int,int,int,int);
bool validarMovimiento(double);
void turnoMover(int&,int&);
bool validarCoordenadas(int,int);
bool validarTurnoJUg1Sel(int**,int,int);
bool validarTurnoJUg2Sel(int**,int,int);
void turnoMover2(int&,int&);

int main(int argc, char const *argv[]){
	int size = 7, turno=1, posX, posY, posXMover, posYMover, cont;
	int** arreglo = newArray();
	double dist;
	bool valiMoviLibre = true,valiMov = true ,valiCoor = true, valiTurnoSel1 = true,valiTurnoSel2 = true, terminoJuego= true;
	llenarTablero(arreglo,size);
	do{
		while (turno == 1){
			imprimirTablero(arreglo, size);
			while(valiMoviLibre && valiMov && valiTurnoSel1 && valiCoor){
				turnoMover(posX, posY);
				turnoMover2(posXMover, posYMover);
				valiMoviLibre = validarNOPiezaenPos(arreglo, posX, posY);
				dist = distancia(posX, posY, posXMover, posYMover);
				valiMov = validarMovimiento(dist);
				valiCoor = validarCoordenadas(posX, posY);
				valiTurnoSel1 = validarTurnoJUg1Sel(arreglo, posX, posY);
			}
			moverPiezajug1(arreglo, posX,posY, posXMover, posYMover, dist);
			cont++;
			turno = 2;
		}
		 while(turno == 2){
			imprimirTablero(arreglo, size);
			while(valiMoviLibre && valiMov && valiTurnoSel2 && valiCoor){
				turnoMover(posX, posY);
				turnoMover2(posXMover, posYMover);
				valiMoviLibre = validarNOPiezaenPos(arreglo, posX, posY);
				dist = distancia(posX, posY, posXMover, posYMover);
				valiMov = validarMovimiento(dist);
				valiCoor = validarCoordenadas(posX, posY);
				valiTurnoSel2 = validarTurnoJUg2Sel(arreglo, posX, posY);	
			}
			moverPiezajug1(arreglo, posX,posY, posXMover, posYMover, dist);
			cont++;
			turno = 1;
		}
	} while (cont != 20);
	deletePunteros(arreglo,size);
	return 0;
}

void moverPiezajug1(int** arreglo, int posX, int posY, int posXMover, int posYMover, double distancia){
	//un paso
	const double mover01 = sqrt(2);//diagonal
	const double mover11 = 1;
	//dos pasos
	const double mover02 = 2;
	const double mover22 = sqrt(8);//diagonal
	if ( (distancia == mover01) || (distancia == mover11) ){
		arreglo[posXMover][posYMover] = 1;
		if( (posXMover == 0) && (posYMover ==0) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 0) && (posYMover ==6) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==0) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==6) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posXMover == 0){
	    	for (int i = 0; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if(posXMover == 6){
	    	for (int i = 5; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posYMover == 0){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posYMover == 6){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }
	}else if( (distancia == mover02) || (distancia == mover22) ){
		arreglo[posXMover][posYMover] = 1;
		arreglo[posXMover][posYMover] = 0;
		if( (posXMover == 0) && (posYMover ==0) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 0) && (posYMover ==6) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==0) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==6) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posXMover == 0){
	    	for (int i = 0; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if(posXMover == 6){
	    	for (int i = 5; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posYMover == 0){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }else if (posYMover == 6){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 2){
						arreglo[i][j] == 1;
					}
			    }
	    	}
	    }
    }   
}
void moverPiezajug2(int** arreglo, int posX, int posY, int posXMover, int posYMover, double distancia){
	const double mover01 = sqrt(2);//diagonal
	const double mover11 = 1;
	//dos pasos
	const double mover02 = 2;
	const double mover22 = sqrt(8);//diagonal
	if ( (distancia == mover01) || (distancia == mover11) ){
		arreglo[posXMover][posYMover] = 2;
		if( (posXMover == 0) && (posYMover ==0) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 0) && (posYMover ==6) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==0) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==6) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posXMover == 0){
	    	for (int i = 0; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if(posXMover == 6){
	    	for (int i = 5; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posYMover == 0){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posYMover == 6){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }
	}else if( (distancia == mover02) || (distancia == mover22) ){
		arreglo[posXMover][posYMover] = 2;
		arreglo[posXMover][posYMover] = 0;
		if( (posXMover == 0) && (posYMover ==0) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 0) && (posYMover ==6) ){
			for (int i = 0; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==0) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if( (posXMover == 6) && (posYMover ==6) ){
			for (int i = 5; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posXMover == 0){
	    	for (int i = 0; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if(posXMover == 6){
	    	for (int i = 5; i < posXMover + 1; ++i){
				for (int j = posYMover - 1; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posYMover == 0){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 0; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }else if (posYMover == 6){
	    	for (int i = posXMover + 1; i < posXMover + 1; ++i){
				for (int j = 5; j < posYMover + 1; ++j){
					if (arreglo[i][j] == 1){
						arreglo[i][j] == 2;
					}
			    }
	    	}
	    }
    }
}

bool validarNOPiezaenPos(int** arreglo, int posXMover, int posYMover){//hay una pieza ahi para poder mover?
	if (arreglo[posXMover][posYMover] != 0){
		return true;
	}else {
		return false;
	}
}

double distancia(int posX, int posY,int posXMover, int posYMover){
	int dif1 = posX - posXMover;
	int dif2 = posY - posYMover;
	double douDif1 = pow(dif1, 2);
	double douDif2 = pow(dif2, 2);
	double sumaDif= douDif1 + douDif2;
	return sqrt(sumaDif);
}
bool validarMovimiento(double distancia){
	//un paso
	const double mover01 = sqrt(2);//diagonal
	const double mover11 = 1;
	//dos pasos
	const double mover02 = 2;
	const double mover22 = sqrt(8);//diagonal
	if ((distancia == mover11) || (distancia == mover01) || (distancia == mover02) || (distancia == mover22)){
		return false;
	}else{
		return true;
	}
}
void turnoMover(int &posX, int &posY){
	cout << "ingrese las coordenadas que quiere mover" << endl;
	cout << "Pos X :" << endl;
	cin >> posX;
	cout << "Pos Y :" << endl;
	cin >> posY;
}
void turnoMover2(int &posX, int &posY){
	cout << "ingrese las coordenadas hacia donde la quiere mover" << endl;
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

bool validarCoordenadas(int x, int y){
	if ((x > 6) || (x < 0)){
		return true;
	}else if((y > 6) || (y < 0)){
		return true;
	}else{
		return false;
	}
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