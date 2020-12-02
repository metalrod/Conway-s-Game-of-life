// Game of Life.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include <random>
#include <iostream>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}




int main()
{
	
	

	//type arrayName [ y ][ x ];
	const int x_max = 5;
	const int y_max = 5;
	int feldA[y_max+2][x_max+2];
	int feldB[y_max+2][x_max+2];
	int ii = 0;
	int jj = 0;
	int count = 0;

	//Das Feld_A und Feld_B mit 0 initialisieren
	for (int y = 0; y < y_max+2; y++)
	{
		for (int x = 0; x < x_max+2; x++)
		{
			feldA[y][x] = 0;
			feldB[y][x] = 0;
		}
	}

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist1(0, 1); // distribution in range [0, 1]


	
	//Eingabe Random Belegung des Feldes
	for (int y = 1; y < y_max+1; y++)
	{
		for (int x = 1; x < x_max+1; x++)
			{
				feldA[y][x] = dist1(rng);
				feldB[y][x] = feldA[y][x];
			}
	}

	while (1)
	{
	//Feld Ausgeben
		gotoxy(0, 0);
		Sleep(500);
		for (int y = 1; y < y_max+1; y++)
		{
			for (int x = 1; x < x_max+1; x++)
			{
				feldA[y][x] = feldB[y][x];
				if (feldA[y][x]){ 
					std::cout << feldA[y][x];
				}
				else {
					std::cout << " ";
				}
				std::cout << "|";
			}
			std::cout << std::endl;
		}
		


	//Feld bearbeiten
		for (int y = 1; y < y_max+1; y++)
		{
			for (int x = 1; x < x_max+1; x++)
			{
				//Umgebung Feld A prüfen
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (feldA[y+i][x+j] && !(i==0 && j==0)) {
							//std::cout << i << j << std::endl;
							count++;
						}
					}
				}
				
				//Feld B verändern
					switch (count) {
				case 0: feldB[y][x] = 0;
					break;
				case 1: feldB[y][x]=0;
					break;       
				case 2: if (feldA[y][x]) { feldB[y][x] = 1; }
						else{feldB[y][x] = 0;};
					break;
				case 3: feldB[y][x] = 1;
					break;
				default: feldB[y][x]=0;
					break;
				}
					count = 0;
				}
			}
		//std::cout << jj << ii;
			
		}

	system("pause");

	return 0;
	}
	
	


	
