#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void ver_carta(int t)
{
	int bar, carta, naipe;
	bar = (t / 52);
	carta = ((t % 52) / 4) + 1;
	naipe = (((t % 52) % 4 ) % 13);
	if(naipe == 0)
	{
		naipe = 4;
	}
	if ((t >= 49 && t <= 52) || (t >= 100 && t <= 104))
	{
		carta = 13;
	}
	cout << setw(2) << "Naipe " << naipe  << " da " << "";
	cout << setw(2) << "Carta " << carta << " ";
	if (bar <= 0)
	{
		cout << "Baralho 1";
	}
	else
	{
		cout << "Baralho 2";
	}
}

int main(int argc, char** argv)
{
	int s;
	int *carta, **jog;
	carta = new int [104];
	jog = new int* [4];

	for (int i = 0; i < 11; ++i)
	{
		*jog = new int [11];
	}
	for (int i = 0; i < 104; ++i)
	{
		carta[i] = 0;
	}

	srand(time(0));

	for (int i = 0; i < 4; ++i)
	{
		cout << "Jogador " << i + 1 << endl;
		for (int j = 0; j < 11;)
		{
			s = rand() % (104 + 1 - 1) + 1;
			if(carta[s] == 0)
			{
				cout << setw(3) << s << "- ";
				ver_carta(s);
				cout << endl;
				carta[s] = 1;
				++j;
			}
		}
	}
	s = 52;
	cout << setw(3) << s << "- ";
	ver_carta(s);
	cout << endl;
	s = 104;
	cout << setw(3) << s << "- ";
	ver_carta(s);
	cout << endl;
	s = 3;
	cout << setw(3) << s << "- ";
	ver_carta(s);
}

//cout << r << "- " << r % 100 << endl;
//4-10-2  ->  10 de espada do baralho 2


