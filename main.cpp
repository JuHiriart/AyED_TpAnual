#include <iostream>
#include <cstdlib>



using namespace std;

void cargaTabla(int **tabla,int puntaje, int jugador){
	
}

int tirar(int juego[]){
	
	for(int i=0; i<5; i++){
		juego[i] = rand() % (6 + 1) ;
	}
	
	//debug
	for(int i=0; i<5; i++){
		cout << juego[i] << endl;
	}
		
}


/*
int jugar(int ***tabla, int juego[], int jugador){
	
	int puntaje = 0;
	
	//logica de escalera
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
	
	for(int i=0; i<5; i++){
		
		if(juego[i] == 1 ){
			f1 = 1;
		}
		if(juego[i] == 2 ){
			f2 = 1;
		}
		if(juego[i] == 3 ){
			f3 = 1;
		}
		if(juego[i] == 4 ){
			f4 = 1;
		}
		if(juego[i] == 5 ){
			f5 = 1;
		}
		if(juego[i] == 6 ){
			f6 = 1;
		}
	
	}
	
	if((f1==1 && f2==1 && f3==1 && f4==1 && f5==1) || (f2==1 && f3==1 && f4==1 && f5==1 && f6==1) || (f3==1 && f4==1 && f5==1 && f6==1 && f1==1)){
		puntaje = 25;
		cargaTabla(tabla, puntaje, jugador);
		cout << "hay escalera";
		return 0;
	}
	
}
*/


int initMatrix(int tabla[5][11], int jugadores){

	for(int i=0; i<jugadores; i++)
	{
		for(int j=0; j<11; j++)
		{
			tabla[i][j]=-1;
		}
	}
	return 0;
}



int main() {
	
	int jugadores;
	int juego[5];
	int jugador = 0;
	
	cout << "Ingrese cantidad de jugadores (3 a 5)" << endl;
	cin >> jugadores;
	
	int tabla[5][11];
	
	//init de matriz
	initMatrix(tabla, jugadores);
	
	//debug matriz
	for(int i=0; i<jugadores; i++){
		for(int j=0; j<11; j++){
			cout << tabla[i][j];
		}
		cout << endl;
	}
	
	/*
	for(int i=0; i<11; i++){
		for(int j=0; j<jugadores; j++){
			
			tirar(juego);
			jugar(tabla, juego, jugador);		
			
		}
	}
	*/
	
	
	
	
	
	
	
	
	
	return 0;
}
