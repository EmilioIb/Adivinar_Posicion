#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Funciones
void explicacion();
void inicio();
void juego();
void imprimir();

//Variables
int fil = 3;
char a[3][3], opc;
int x, y, ox, oy;


int main(){
	
	explicacion();
	inicio();

	getch();
	return 0;
}

void explicacion(){
	cout<<"\t\t\t----- BIENVENIDO -----"<<endl;
	cout<<"En pantalla se mostraran 9 casillas, en una de ellas se encuentra un barco enemigo, \ntienes que indicar la posicion donde quieres atacar. Si fallas, se mostrara una X en la \nposicion y continuara el juego hasta que aciertes. Buena suerte."<<endl;
	system("pause");
	system("cls");
}

void inicio(){
	srand(time(NULL));
	
	x = rand()%(fil);
	y = rand()%(fil);
	
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < fil; j++){
			a[i][j] = '?';
		}
	}
	
	juego();		
}

void juego(){
	do{
		imprimir();	
		
		do{
			cout<<"Ingresa la posicion en X: ";
			cin>>ox;
			cout<<"Ingresa la posicion en Y: ";
			cin>>oy;
			
			if(ox > fil-1 || oy > fil-1){
				cout<<"VALORES FUERA DE RANGO"<<endl;
			}
		}while(ox > fil-1 || oy > fil-1);
		
		a[ox][oy] = 'X';
		
		
		system("pause");
		system("cls");
	} while(ox != x || oy != y);
		
		a[x][y] = 'G';
		imprimir();
		cout<<"------ GANASTE ------"<<endl;
		system("pause");
		system("cls");
		

		cout<<"Quieres jugar de nuevo? (S/N)"<<endl;
		cin>>opc;
		
		if(opc == 'S' || opc == 's'){
			system("cls");
			inicio();
		}
		else{
			cout<<"SALIENDO DEL PROGRAMA...";
		}
		
}

void imprimir(){
	cout<<"       ARREGLOS       "<<endl;
	cout<<" EMILIO IBARRA VALDEZ "<<endl;
	cout<<" ESTRUCTURAS DE DATOS "<<endl;
	cout<<"    4B 25/02/2021     "<<endl<<endl;
	//cout<<"["<<x<<"] ["<<y<<"]"<<endl;
	for(int i = 0; i < fil; i++){
		cout<<"|";
		for(int j = 0; j < fil; j++){
			cout<<"  "<<a[i][j]<<"  |"; 
		}
		cout<<"\n ___________________\n\n";
	}
}
