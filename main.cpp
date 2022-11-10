#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int cargaTabla(int tabla[11][5],int puntaje, int jugador, int fila){

	if (tabla[fila][jugador] == 0)
	{
		tabla[fila][jugador] = puntaje;
		return true;
	}

	cout << "el espacio estaba ocupado y no se pudo cargar el puntaje" << endl;
	return false;
	
}

void tirar(int juego[3][5]){
	
	
	
	for (int j=0; j<3; j++){
		for(int i=0; i<5; i++){
			juego[j][i] = 1 + (rand() % (5 + 1));
		}
	}
	
	//debug
	for (int j=0; j<3; j++){
		for(int i=0; i<5; i++){
			cout << juego[j][i];
		}
		cout << endl;
	}
		
}



int jugar(int tabla[11][5], int juego[3][5], int jugador){
	
	int puntaje = 0;
	int fila = -1;
	int f1, f2, f3, f4, f5, f6; //flags de n煤meros

	//l贸gica generala servida

	cout << "buscando generala servida..." << endl;

	f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

	for(int i=0; i<5; i++){
		
		if(juego[0][i] == 1 ){
			f1++;
		}
		if(juego[0][i] == 2 ){
			f2++;
		}
		if(juego[0][i] == 3 ){
			f3++;
		}
		if(juego[0][i] == 4 ){
			f4++;
		}
		if(juego[0][i] == 5 ){
			f5++;
		}
		if(juego[0][i] == 6 ){
			f6++;
		}
	
	}


	if((f1==5||f2==5||f3==5||f4==5||f5==5||f6==5)){
		
		puntaje = 999;
		fila = 9;

		if (cargaTabla(tabla, puntaje, jugador, fila))
		{
			cout << "hay GENERALA SERVIDA" << endl;
			return 0;
		}
	}

	cout << "no hay generala servida" << endl;

	//l贸gica de generala

	cout << "buscando generala..." << endl;


	for(int j=1; j<3; j++){
	f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

		for(int i=0; i<5; i++){
				
			if(juego[j][i] == 1 ){
				f1++;
			}
			if(juego[j][i] == 2 ){
				f2++;
			}
			if(juego[j][i] == 3 ){
				f3++;
			}
			if(juego[j][i] == 4 ){
				f4++;
			}
			if(juego[j][i] == 5 ){
				f5++;
			}
			if(juego[j][i] == 6 ){
				f6++;
			}
		
		}
	}


	if((f1==5||f2==5||f3==5||f4==5||f5==5||f6==5)){
		

		if(tabla[9][jugador] != 0){

			puntaje = 100;
			fila = 10;

			if (cargaTabla(tabla, puntaje, jugador, fila))
			{
				cout << "hay GENERALA DOBLE" << endl;
				return 0;
			}
		}
		else{
			puntaje = 50;
			fila = 9;
			if (cargaTabla(tabla, puntaje, jugador, fila))
			{
				cout << "hay GENERALA" << endl;
				return 0;
			}
		}

	}

	cout << "no hay generala" << endl;

	//l贸gica poker
	cout << "buscando poker..." << endl;


	for(int j=0; j<3; j++){

		f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

		for(int i=0; i<5; i++){
			
			if(juego[j][i] == 1 ){
				f1++;
			}
			if(juego[j][i] == 2 ){
				f2++;
			}
			if(juego[j][i] == 3 ){
				f3++;
			}
			if(juego[j][i] == 4 ){
				f4++;
			}
			if(juego[j][i] == 5 ){
				f5++;
			}
			if(juego[j][i] == 6 ){
				f6++;
			}
		}

		if((f1==4||f2==4||f3==4||f4==4||f5==4||f6==4)){
			
			puntaje = 45;
			fila = 8;

			if (cargaTabla(tabla, puntaje, jugador, fila))
			{
				cout << "hay poker" << endl;
				return 0;
			}
		}

	}

	cout << "no hay poker" << endl;


	//l贸gica full

	cout << "buscando full..." << endl;

	for(int j=0; j<3; j++){

		f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

		for(int i=0; i<5; i++){
			
			if(juego[j][i] == 1 ){
				f1++;
			}
			if(juego[j][i] == 2 ){
				f2++;
			}
			if(juego[j][i] == 3 ){
				f3++;
			}
			if(juego[j][i] == 4 ){
				f4++;
			}
			if(juego[j][i] == 5 ){
				f5++;
			}
			if(juego[j][i] == 6 ){
				f6++;
			}
		
		}

		if((f1==2||f2==2||f3==2||f4==2||f5==2||f6==2) && (f1==3||f2==3||f3==3||f4==3||f5==3||f6==3)){
			
			puntaje = 35;
			fila = 7;

			if (cargaTabla(tabla, puntaje, jugador, fila))
			{
				cout << "hay full" << endl;
				return 0;
			}
		}
	}

	cout << "no hay full" << endl;

	//l贸gica de escalera
	
	cout << "buscando escalera..." << endl;

	for (int j=0; j<3; j++){

		f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

		for(int i=0; i<5; i++){
			
			if(juego[j][i] == 1 ){
				f1 = 1;
			}
			if(juego[j][i] == 2 ){
				f2 = 1;
			}
			if(juego[j][i] == 3 ){
				f3 = 1;
			}
			if(juego[j][i] == 4 ){
				f4 = 1;
			}
			if(juego[j][i] == 5 ){
				f5 = 1;
			}
			if(juego[j][i] == 6 ){
				f6 = 1;
			}
	
		}
	
		if((f1==1 && f2==1 && f3==1 && f4==1 && f5==1) || (f2==1 && f3==1 && f4==1 && f5==1 && f6==1) || (f3==1 && f4==1 && f5==1 && f6==1 && f1==1)){
		
			puntaje = 25;
			fila = 6;

			if (cargaTabla(tabla, puntaje, jugador, fila)){
				cout << "hay escalera" << endl;
				return 0;
			}
		
		}
	}
	
	cout << "no hay escalera" << endl;

	//l贸gica num茅rica

	cout << "buscando mejor numero..." << endl;

	for(int j=0; j<3; j++){

		f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

		for(int i=0; i<5; i++){
			
			if(juego[j][i] == 1 ){
				f1++;
			}
			if(juego[j][i] == 2 ){
				f2++;
			}
			if(juego[j][i] == 3 ){
				f3++;
			}
			if(juego[j][i] == 4 ){
				f4++;
			}
			if(juego[j][i] == 5 ){
				f5++;
			}
			if(juego[j][i] == 6 ){
				f6++;
			}
		
		}

		if((f1==3||f2==3||f3==3||f4==3||f5==3||f6==3)){
			
			if (f1==3)
			{
				puntaje = 1*3;
				fila = 0;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay unos" << endl;
					return 0;
				}
			}
			
			if (f2==3)
			{
				puntaje = 2*3;
				fila = 1;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay dos" << endl;
					return 0;
				}
			}

			if (f3==3)
			{
				puntaje = 3*3;
				fila = 2;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay 3" << endl;
					return 0;
				}
			}

			if (f4==3)
			{
				puntaje = 4*3;
				fila = 3;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay cuatros" << endl;
					return 0;
				}
			}

			if (f5==3)
			{
				puntaje = 5*3;
				fila = 4;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay cincos" << endl;
					return 0;
				}
			}

			if (f6==3)
			{
				puntaje = 6*3;
				fila = 5;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay seis" << endl;
					return 0;
				}
			}

		}

		if((f1==2||f2==2||f3==2||f4==2||f5==2||f6==2)){
			
			if (f1==2)
			{
				puntaje = 1*2;
				fila = 0;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay unos" << endl;
					return 0;
				}
			}
			
			if (f2==2)
			{
				puntaje = 2*2;
				fila = 1;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay dos" << endl;
					return 0;
				}
			}

			if (f3==2)
			{
				puntaje = 3*2;
				fila = 2;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay 3" << endl;
					return 0;
				}
			}

			if (f4==2)
			{
				puntaje = 4*2;
				fila = 3;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay cuatros" << endl;
					return 0;
				}
			}

			if (f5==2)
			{
				puntaje = 5*2;
				fila = 4;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay cincos" << endl;
					return 0;
				}
			}

			if (f6==2)
			{
				puntaje = 6*2;
				fila = 5;
				if (cargaTabla(tabla, puntaje, jugador, fila))
				{
					cout << "hay seis" << endl;
					return 0;
				}
			}

		}
		
	}

	cout << "no hay triples ni dobles" << endl;

}



int initMatrix(int tabla[11][5], int jugadores){

	for(int i=0; i<11; i++)
	{
		for(int j=0; j<jugadores; j++)
		{
			tabla[i][j] = 0;
		}
	}
	return 0;
}


struct nombreJugador{
	char nombre[20];
};

struct Fecha{
	int dia;
	int mes; 
	int anio;
};

struct jugada{
	int idJugada;
	nombreJugador nombre;
	Fecha fecha;
	int puntaje;
};


int main() {
	
	srand (time (0));
	
	int jugadores;
	int juego[3][5];
	int jugador = 0;
	int j,i;
	nombreJugador nombres[5];
	Fecha fecha;
	
	
	
	cout << "Ingrese cantidad de jugadores (3 a 5)" << endl;
	cin >> jugadores;
	
	for(i = 0; i < jugadores;i++){
		cout << "Ingrese nombre del jugador " << i+1 << endl;
		cin >> nombres[i].nombre;
	}
	cout << "Ingrese la fecha" << endl;
	cout << "A駉: "; cin >> fecha.anio;
	cout << "Mes: "; cin >> fecha.mes;
	cout << "Dia: "; cin >> fecha.dia;
	
	
	int tabla[11][5];
	
	//init de matriz
	initMatrix(tabla, jugadores);
	
	//debug matriz
	for(int i=0; i<11; i++){
		
		for(int j=0; j<jugadores; j++){
			cout << tabla[i][j] << " ";
		}
		cout << endl;
	}
	
	
	for(int i=0; i<11; i++){
		for(int j=0; j<jugadores; j++){
			
			cout << endl << endl << "tiro numero " << i+1 << " de " << nombres[j].nombre << endl;

			tirar(juego);
			jugar(tabla, juego, jugador);
			jugador ++;
			if(jugador == jugadores){
				jugador = 0;
			}	
			
		}
	}
	
	//debuggeo de matriz 2
	char nombreColumna[11] = {'1','2','3','4','5','6','E','F','P','G','D'};
	for(int i=0; i<11; i++){
		cout << nombreColumna[i] << ": ";
		for(int j=0; j<jugadores; j++){
			cout << tabla[i][j] << " ";
		}
		cout << endl;
	}
	
	
	//calcular puntaje
		
	int puntaje = 0;
	int aux = 0;
	int pos = 0;
	
	for(int i=0; i<jugadores; i++){
		aux = 0;
		for(int j=0; j<11; j++){	
		
			aux += tabla[j][i];	
				
		}
		
		if (aux > puntaje){
			puntaje = aux;
			pos = i;
		}

	}
	
	
	
	//carga y lectura del archivo binario
	
	
	jugada highscore;
	
	FILE* f = fopen("generalaHighscores.dat", "r+b");
	
	int id=0;
	highscore.idJugada = 0;
	
	fseek(f, -sizeof(jugada),SEEK_END);
	
	if(fread(&highscore, sizeof(jugada),1,f)){
		cout << "ESTOY EN EL IF";
		id = highscore.idJugada + 1;
	}
	highscore.idJugada = id;
	
	fclose(f);
	

	
	highscore.puntaje = puntaje;
	highscore.nombre = nombres[pos];
	highscore.idJugada = id;
	highscore.fecha = fecha;
	
	f = fopen("generalaHighscores.dat","a+b");
	fwrite(&highscore,sizeof(jugada),1,f);
	fclose(f);
	
	f = fopen("generalaHighscores.dat","r+b");
	while(fread(&highscore, sizeof(jugada),1,f)){
		cout << "id: " << highscore.idJugada << endl << "nombere: " << highscore.nombre.nombre << endl << "fecha: " << highscore.fecha.dia << "/" << highscore.fecha.mes << "/" << highscore.fecha.anio << endl << "puntaje: " << highscore.puntaje << endl << endl;		
	}
	fclose(f);
	
	//creaci髇 y actualizaci髇 del ranking de los 3 mejores
	
	f = fopen("generalaHighscores.dat","r+b");
	while(fread(&highscore, sizeof(jugada),1,f)){
				
	}
	fclose(f);
	
	
	return 0;
}
