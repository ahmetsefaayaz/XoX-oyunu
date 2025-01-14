#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

static const int width = 3;
static const int height = 3;
static char tablo[height][width];
static char Player = 'X';
static char AI = 'O';
static int x, y;
static int ax, ay;

bool AIwin = false;
bool Playerwin = false;
bool Draw = false;

void System();
void Startup();
void Input();
void Movement();
void Print();
void EndTheGame();


int main(){
	Startup();
	System();

	return 0;
}
void System() {
	int bug = 0;
	while (AIwin == false && Playerwin == false && Draw == false) {
		system("cls");
		Print();
		if (Playerwin == true || AIwin == true || Draw == true) {
			break;
		}
			
		Input();
		system("cls");
		Print();
		if (Playerwin == true || AIwin == true || Draw == true) {
			break;
		}
		Movement();
		

	}
		EndTheGame();
}
void Startup() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tablo[i][j] = ' ';
		}
	}


}
void Input() {
	cout << "Sirayla Satir ve Sutun Seciniz:";
	cin >> y >> x;
	for (;;) {
		if (y - 1 < 0 || y > height || x - 1 < 0 || x > width || tablo[y - 1][x - 1] != ' ') {
			cout << "gecersiz hamle tekrar deneyin" << endl;
			return Input();

		}
		else
			break;
	}



	tablo[y-1][x-1] = Player;

}
void Movement() {
	int randomkose,AIctrl=0;
	srand(time(0));
	

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (tablo[i][j] == AI)
				AIctrl++;



		}
	}









			if (AIctrl == 0) {
				if (tablo[(height - 1) / 2][(width - 1) / 2] == ' ') {
					tablo[(height - 1) / 2][(width - 1) / 2] = AI;
					return;
				}
				else {
					randomkose = 1 + rand() % 4;
					switch (randomkose) {
					case 1:
						if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return ;
					case 2:
						if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return;

					case 3:
						if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return;
					case 4:
						if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						return;

					}

				}

			}
			

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					// Bitirici Hamleler (Winning moves)
					if (j + 2 < width && (tablo[i][j] == AI && tablo[i][j + 1] == AI && tablo[i][j + 2] == ' ')) {
						tablo[i][j + 2] = AI;
						return;
					}
					else if (j + 2 < width && (tablo[i][j] == AI && tablo[i][j + 2] == AI && tablo[i][j + 1] == ' ')) {
						tablo[i][j + 1] = AI;
						return;
					}
					else if (j + 2 < width && (tablo[i][j + 1] == AI && tablo[i][j + 2] == AI && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i][j] == AI && tablo[i + 1][j] == AI && tablo[i + 2][j] == ' ')) {
						tablo[i + 2][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i][j] == AI && tablo[i + 2][j] == AI && tablo[i + 1][j] == ' ')) {
						tablo[i + 1][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i + 1][j] == AI && tablo[i + 2][j] == AI && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i][j] == AI && tablo[i + 1][j + 1] == AI && tablo[i + 2][j + 2] == ' ')) {
						tablo[i + 2][j + 2] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i][j] == AI && tablo[i + 2][j + 2] == AI && tablo[i + 1][j + 1] == ' ')) {
						tablo[i + 1][j + 1] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i + 2][j + 2] == AI && tablo[i + 1][j + 1] == AI && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i][j] == AI && tablo[i + 1][j - 1] == AI && tablo[i + 2][j - 2] == ' ')) {
						tablo[i + 2][j - 2] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i][j] == AI && tablo[i + 2][j - 2] == AI && tablo[i + 1][j - 1] == ' ')) {
						tablo[i + 1][j - 1] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i + 2][j - 2] == AI && tablo[i + 1][j - 1] == AI && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
				}
			}
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (j + 2 < width && (tablo[i][j] == Player && tablo[i][j + 1] == Player && tablo[i][j + 2] == ' ')) {
						tablo[i][j + 2] = AI;
						return;
					}
					else if (j + 2 < width && (tablo[i][j] == Player && tablo[i][j + 2] == Player && tablo[i][j + 1] == ' ')) {
						tablo[i][j + 1] = AI;
						return;
					}
					else if (j + 2 < width && (tablo[i][j + 1] == Player && tablo[i][j + 2] == Player && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i][j] == Player && tablo[i + 1][j] == Player && tablo[i + 2][j] == ' ')) {
						tablo[i + 2][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i][j] == Player && tablo[i + 2][j] == Player && tablo[i + 1][j] == ' ')) {
						tablo[i + 1][j] = AI;
						return;
					}
					else if (i + 2 < height && (tablo[i + 1][j] == Player && tablo[i + 2][j] == Player && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i][j] == Player && tablo[i + 1][j + 1] == Player && tablo[i + 2][j + 2] == ' ')) {
						tablo[i + 2][j + 2] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i][j] == Player && tablo[i + 2][j + 2] == Player && tablo[i + 1][j + 1] == ' ')) {
						tablo[i + 1][j + 1] = AI;
						return;
					}
					else if (i + 2 < height && j + 2 < width && (tablo[i + 2][j + 2] == Player && tablo[i + 1][j + 1] == Player && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i][j] == Player && tablo[i + 1][j - 1] == Player && tablo[i + 2][j - 2] == ' ')) {
						tablo[i + 2][j - 2] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i][j] == Player && tablo[i + 2][j - 2] == Player && tablo[i + 1][j - 1] == ' ')) {
						tablo[i + 1][j - 1] = AI;
						return;
					}
					else if (i + 2 < height && j - 2 >= 0 && (tablo[i + 2][j - 2] == Player && tablo[i + 1][j - 1] == Player && tablo[i][j] == ' ')) {
						tablo[i][j] = AI;
						return;
					}
				}
			}
			randomkose = 1 + rand() % 4;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					//Ofansif Hamleler.
					switch (randomkose) {
					case 1:
						if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return;
					case 2:
						if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return;

					case 3:
						if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						return;
						
					case 4:
						if (tablo[height - 1][width - 1] == ' ')
							tablo[height - 1][width - 1] = AI;
						else if (tablo[0][0] == ' ')
							tablo[0][0] = AI;
						else if (tablo[0][width - 1] == ' ')
							tablo[0][width - 1] = AI;
						else if (tablo[height - 1][0] == ' ')
							tablo[height - 1][0] = AI;
						return;

					}
				}
			}
					//random hamleler
					for (;;) {
						ax = rand() % width;
						ay = rand() % height;
						if (tablo[ay][ax] == ' ') {
							tablo[ay][ax] = AI;
							return;
						}


					}

				

		



	
	

}
void Print() {
	cout << " ";
	for (int j = 0; j < width; j++) {
		cout << " " << j + 1 << " ";
	}
	cout << "\n";

	for (int i = 0; i < height; i++) {
		for (int j = -1; j < width; j++) {
			if (j == -1)
				cout << i + 1;
			else
				cout << "[" << tablo[i][j] << "]";

		}
		cout << "\n";
	}


										//Kazanma Kaybetme Kontrol.
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			
			if ((j + 2 < width) && tablo[i][j] == Player && (tablo[i][j + 1] == Player && tablo[i][j + 2] == Player)) {
				Playerwin = true;
			}
			
			
			else if (i + 2 < height && tablo[i][j] == Player && (tablo[i + 1][j] == Player && tablo[i + 2][j] == Player)) {
				Playerwin = true;
			}
			
			else if (i + 2 < height && j + 2 < width && tablo[i][j] == Player && (tablo[i + 1][j + 1] == Player && tablo[i + 2][j + 2] == Player)) {
				Playerwin = true;
			}
			
			else if (i + 2 < height && j - 2 >= 0 && tablo[i][j] == Player && (tablo[i + 1][j - 1] == Player && tablo[i + 2][j - 2] == Player)) {
				Playerwin = true;
			}
			else if (j + 2 < width && tablo[i][j] == AI && (tablo[i][j + 1] == AI && tablo[i][j + 2] == AI)) {
				AIwin = true;
			}
			else if (i + 2 < height && tablo[i][j] == AI && (tablo[i + 1][j] == AI && tablo[i + 2][j] == AI)) {
				AIwin = true;
			}

			else if (i + 2 < height && j + 2 < width && tablo[i][j] == AI && (tablo[i + 1][j + 1] == AI && tablo[i + 2][j + 2] == AI)) {
				AIwin = true;
			}
			else if (i + 2 < height && j - 2 >= 0 && tablo[i][j] == AI && (tablo[i + 1][j - 1] == AI && tablo[i + 2][j - 2] == AI)) {
				AIwin = true;
			}




		}

	}


	Draw = true;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (tablo[i][j] == ' ') {
				Draw = false;
				break;
			}
		}
		if (!Draw) break;
	}




}
void EndTheGame() {
	if (Playerwin == true) {
		cout << "Kazandiniz!!!" << endl;
	}
	else if (AIwin == true) {
		cout << "Kaybettiniz." << endl;
	}
	else if (Draw == true) {
		cout << "Berabere." << endl;
	}
}