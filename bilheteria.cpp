#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define LIN 41
#define COL 16

void mostrarMatriz (int **x,int **y)
{
	for (int i=1; i<LIN; i++)
	{
		for (int j = 1; j<COL; j++)
		{
			if(y[i][j]==0)
			{
				cout<<".";
			}else{
				cout<<"#";
			}
			cout << setw(4) << x[i][j] << " | ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	int **mat;
	int **ma;
	int i, j, k, fileira, coluna, escolha = 9,ocps = 0;
	int ao5=0, ao10=0, ao15=0;
	
	ma = new int* [40];
	mat = new int* [40];
	
	for(i=1; i<LIN; i++)
	{
		ma[i] = new int[15];
		mat[i] = new int[15];
	}
	
	k=1;
	j=1;
	
	for (i=1; i<LIN; i++)
	{
		for (j = 1; j<COL; j++)
		{
			ma [i][j] = 0;
			mat [i][j] = k++;				
		}		
	}		
	while (escolha != 0)
	{		
		cout << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento"<< endl;
		cout << "Digite o numero de acordo com a funcao desejada: ";
		cin >> escolha; 
		switch (escolha)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				cout <<"Digite o numero da fileira desejada: ";
				cin>>fileira;				 				
				cout << endl;
		  		cout <<"Digite o numero da coluna desejada: ";
		  		cin >>coluna; 
				cout << endl;
				if (ma[fileira][coluna]==0)
				{
					cout<<"Lugar reservado com sucesso.";
					ma[fileira][coluna] = 1;
					ocps += 1;
				}else{
					cout<<"Lugar ja ocupado!";
				}
				if(fileira <6 && ma[fileira][coluna] == 1)
				{
					ao5 += 50;
				}else if (fileira <11 && ma[fileira][coluna] == 1)
				{
					ao10 += 30;
				}else if (fileira < 16 && ma[fileira][coluna] == 1)
				{
					ao15 += 15;
				}	
				break;
			}
			case 2:
			{
		   		mostrarMatriz(mat,ma);
		   		break;
			}
			case 3:
			{
				int total = ao5 + ao10 + ao15;
				cout << "Qtde de lugares ocupados: "<< ocps << endl << "Valor da bilheteria: R$"<< total;
				break;
			}
			default:
			{
				cout<<"O numero inserido eh invalido!!!";
				break;
			}
		}
	}
}