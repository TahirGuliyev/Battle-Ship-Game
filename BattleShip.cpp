#include<iostream>
#include<time.h>
#include<stdio.h>

using namespace std;

enum gemiTipi { Gemi5, Gemi4, Gemi3, Gemi2, Gemi1 };

struct donanma
{
	int koordinatX;
	int koordinatY;
	gemiTipi gemi;
	int olcu;
	int istiqamet;
	int can;
};

void xeriteGoster(char xerite[][10]);

void oyuncuGemileriniYerlesdir(donanma oyuncuGemileri[], char xerite1[][10]);

void dusmenGemileriniYerlesdir(donanma dusmenGemileri[], char xerite2[][10]);

void gemiYerl(donanma Gemiler[], char xerite[][10], int& gemiYerYoxla, int i);

void doyus(donanma oyuncuGemileri[], donanma dusmenGemileri[], char xerite1[][10], char xerite2[][10], char xerite3[][10], char xerite4[][10], int& qelebeler, int& meglubiyyetler);

void gemiYoxla(donanma Gemiler[], char xerite[][10], int X, int Y);

void teslimOl(bool& qelebeYoxla, int& meglubiyyetler);

int main()
{
	srand(unsigned int(time(NULL)));

	int qelebeler = 0;
	int meglubiyyetler = 0;

	bool yenidenOyna = true;

	do
	{
		donanma oyuncuGemileri[5];
		donanma dusmenGemileri[5];
		for (int i = 0; i < 5; i++)
		{
			oyuncuGemileri[i].koordinatX = 0;
			dusmenGemileri[i].koordinatX = 0;
			oyuncuGemileri[i].koordinatY = 0;
			dusmenGemileri[i].koordinatY = 0;
			oyuncuGemileri[i].istiqamet = 0;
			dusmenGemileri[i].istiqamet = 0;

			switch (i)
			{
			case 0: oyuncuGemileri[i].gemi = Gemi5;
				dusmenGemileri[i].gemi = Gemi5;
				oyuncuGemileri[i].olcu = 5;
				dusmenGemileri[i].olcu = 5;
				oyuncuGemileri[i].can = 5;
				dusmenGemileri[i].can = 5;
				break;
			case 1: oyuncuGemileri[i].gemi = Gemi4;
				dusmenGemileri[i].gemi = Gemi4;
				oyuncuGemileri[i].olcu = 4;
				dusmenGemileri[i].olcu = 4;
				oyuncuGemileri[i].can = 4;
				dusmenGemileri[i].can = 4;
				break;
			case 2: oyuncuGemileri[i].gemi = Gemi3;
				dusmenGemileri[i].gemi = Gemi3;
				oyuncuGemileri[i].olcu = 3;
				dusmenGemileri[i].olcu = 3;
				oyuncuGemileri[i].can = 3;
				dusmenGemileri[i].can = 3;
				break;
			case 3: oyuncuGemileri[i].gemi = Gemi2;
				dusmenGemileri[i].gemi = Gemi2;
				oyuncuGemileri[i].olcu = 3;
				dusmenGemileri[i].olcu = 3;
				oyuncuGemileri[i].can = 3;
				dusmenGemileri[i].can = 3;
				break;
			case 4: oyuncuGemileri[i].gemi = Gemi1;
				dusmenGemileri[i].gemi = Gemi1;
				oyuncuGemileri[i].olcu = 2;
				dusmenGemileri[i].olcu = 2;
				oyuncuGemileri[i].can = 2;
				dusmenGemileri[i].can = 2;
				break;
			}
		}
		char xerite1[10][10];
		char xerite2[10][10];
		char xerite3[10][10];
		char xerite4[10][10];

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				xerite1[i][j] = '~';
				xerite2[i][j] = '~';
				xerite3[i][j] = '~';
				xerite4[i][j] = '~';
			}
		}

		cout << "Gemi doyusu oyununa xos gelmisiniz. Burda gemilerinizi yerlesdire bilersiniz." << endl;
		cout << "Doyuse baslamaq ucun evvelce gemilerinizi yerlesdirin!";
		xeriteGoster(xerite1);
		oyuncuGemileriniYerlesdir(oyuncuGemileri, xerite1);
		dusmenGemileriniYerlesdir(dusmenGemileri, xerite2);
		doyus(oyuncuGemileri, dusmenGemileri, xerite1, xerite2, xerite3, xerite4, qelebeler, meglubiyyetler);

		int yeniden;
		system("cls");
		cout << "\nYeniden oynamaq isteyirsiniz?\n";
		cout << "He ucun 1-i yox ucun 2-ni secin: ";
		cin >> yeniden;

		if (yeniden == 2)
			yenidenOyna = false;
	} while (yenidenOyna);
	system("cls");
	cout << endl << qelebeler << " defe qazandiniz" << endl;
	cout << meglubiyyetler << " defe uduzdunuz" << endl;

	return 0;
}

void xeriteGoster(char xerite[][10])
{
	cout << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;
	int yOxu = 1;
	for (int i = 0; i < 10; i++)
	{
		if (yOxu == 10)
			cout << yOxu << " ";
		else
			cout << yOxu << "  ";
		yOxu++;
		for (int j = 0; j < 10; j++)
		{
			cout << xerite[i][j] << " ";
		}
		cout << "\n";
	}
}

void oyuncuGemileriniYerlesdir(donanma oyuncuGemileri[], char xerite1[][10])
{
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0: cout << "\n Gemi5 gemisini yerlesdirirsiniz. Bu gemi 5 xanani tutur. \n";
			cout << "\n 1 ile 10 arasinda X koordinatini daxil edin ";
			cin >> oyuncuGemileri[i].koordinatX;
			--oyuncuGemileri[i].koordinatX;
			cout << "\n 1 ile 10 arasinda Y koordinatini daxil edin ";
			cin >> oyuncuGemileri[i].koordinatY;
			--oyuncuGemileri[i].koordinatY;
			cout << "\n geminin istiqametini secin, saquli ucun 1, ufuqi ucun 2 daxil edin: ";
			cin >> oyuncuGemileri[i].istiqamet;
			system("cls");
			break;
		case 1: cout << "\n Gemi4 gemisini yerlesdirirsiniz. Bu gemi 4 xanani tutur. \n";
			cout << "\n 1 ile 10 arasinda X koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatX;
			--oyuncuGemileri[i].koordinatX;
			cout << "\n 1 ile 10 arasinda Y koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatY;
			--oyuncuGemileri[i].koordinatY;
			cout << "\n geminin istiqametini secin, saquli ucun 1, ufuqi ucun 2 daxil edin: ";
			cin >> oyuncuGemileri[i].istiqamet;
			system("cls");
			break;
		case 2: cout << "\n Gemi3 gemisini yerlesdirirsiniz. Bu gemi 3 xanani tutur. \n";
			cout << "\n 1 ile 10 arasinda X koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatX;
			--oyuncuGemileri[i].koordinatX;
			cout << "\n 1 ile 10 arasinda Y koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatY;
			--oyuncuGemileri[i].koordinatY;
			cout << "\n geminin istiqametini secin, saquli ucun 1, ufuqi ucun 2 daxil edin: ";
			cin >> oyuncuGemileri[i].istiqamet;
			system("cls");
			break;
		case 3: cout << "\n Gemi2 gemisini yerlesdirirsiniz. Bu gemi 2 xanani tutur. \n";
			cout << "\n 1 ile 10 arasinda X koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatX;
			--oyuncuGemileri[i].koordinatX;
			cout << "\n 1 ile 10 arasinda Y koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatY;
			--oyuncuGemileri[i].koordinatY;
			cout << "\n geminin istiqametini secin, saquli ucun 1, ufuqi ucun 2 daxil edin: ";
			cin >> oyuncuGemileri[i].istiqamet;
			system("cls");
			break;
		case 4: cout << "\n Gemi1 gemisini yerlesdirirsiniz. Bu gemi 2 xanani tutur. \n";
			cout << "\n 1 ile 10 arasinda X koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatX;
			--oyuncuGemileri[i].koordinatX;
			cout << "\n 1 ile 10 arasinda Y koordinatini daxil edin: ";
			cin >> oyuncuGemileri[i].koordinatY;
			--oyuncuGemileri[i].koordinatY;
			cout << "\n geminin istiqametini secin, saquli ucun 1, ufuqi ucun 2 daxil edin: ";
			cin >> oyuncuGemileri[i].istiqamet;
			system("cls");
			break;
		}
		switch (oyuncuGemileri[i].istiqamet)
		{
		case 1: break;
		case 2: break;
		default:
			system("cls");
			cout << "\n Geminin istiqameti ugursuz oldu, yeniden cehd et \n";  --i;   continue;

			break;
		}
		if (oyuncuGemileri[i].koordinatX < 0 || oyuncuGemileri[i].koordinatX > 9)
		{
			system("cls");
			cout << "\n X koordinati ugursuz oldu, yeniden cehd et \n";  --i; continue;

		}
		if (oyuncuGemileri[i].koordinatY < 0 || oyuncuGemileri[i].koordinatY > 9)
		{
			system("cls");
			cout << "\n Y koordinati ugursuz oldu, yeniden cehd et \n";  --i; continue;

		}
		int gemiYerYoxla = 0;

		gemiYerl(oyuncuGemileri, xerite1, gemiYerYoxla, i);

		if (gemiYerYoxla > 0)
		{
			system("cls");
			cout << "\nGemiler ust-uste ola bilmez. Yeniden cehd et.\n";
			i--;

			continue;
		}
		xeriteGoster(xerite1);
	}
}

void dusmenGemileriniYerlesdir(donanma dusmenGemileri[], char xerite2[][10])
{
	system("cls");
	cout << "\nDusmen gemileri yerlesdirildi. \n \n";

	for (int i = 0; i < 5; i++)
	{
		int randomX = rand() % 10;
		int randomY = rand() % 10;
		int randomDirection = rand() % 2 + 1;

		switch (i)
		{
		case 0: dusmenGemileri[i].koordinatX = randomX;
			dusmenGemileri[i].koordinatY = randomY;
			dusmenGemileri[i].istiqamet = randomDirection;
			break;
		case 1: dusmenGemileri[i].koordinatX = randomX;
			dusmenGemileri[i].koordinatY = randomY;
			dusmenGemileri[i].istiqamet = randomDirection;
			break;
		case 2: dusmenGemileri[i].koordinatX = randomX;
			dusmenGemileri[i].koordinatY = randomY;
			dusmenGemileri[i].istiqamet = randomDirection;
			break;
		case 3: dusmenGemileri[i].koordinatX = randomX;
			dusmenGemileri[i].koordinatY = randomY;
			dusmenGemileri[i].istiqamet = randomDirection;
			break;
		case 4:; dusmenGemileri[i].koordinatX = randomX;
			dusmenGemileri[i].koordinatY = randomY;
			dusmenGemileri[i].istiqamet = randomDirection;
			break;
		}
		int gemiYerYoxla = 0;

		gemiYerl(dusmenGemileri, xerite2, gemiYerYoxla, i);

		if (gemiYerYoxla > 0)
		{
			system("cls");

			i--;

			continue;
		}

	}
}

void gemiYerl(donanma Gemiler[], char xerite[][10], int& gemiYerYoxla, int i)
{
	int serhedYoxla = (10 - Gemiler[i].olcu);

	switch (Gemiler[i].istiqamet)
	{
	case 1:
		if (Gemiler[i].koordinatY <= serhedYoxla)
		{
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				if (xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] == '#')
				{
					gemiYerYoxla++;
				}

				Gemiler[i].koordinatY++;

			}
			if (gemiYerYoxla > 0)
			{
				break;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				Gemiler[i].koordinatY--;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] = '#';
				Gemiler[i].koordinatY++;
			}
			--Gemiler[i].koordinatY;
		}
		else
		{
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				if (xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] == '#')
				{
					gemiYerYoxla++;
				}

				Gemiler[i].koordinatY--;

			}
			if (gemiYerYoxla > 0)
			{
				break;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				Gemiler[i].koordinatY++;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] = '#';
				Gemiler[i].koordinatY--;
			}
			++Gemiler[i].koordinatY;
		}
		break;
	case 2:
		if (Gemiler[i].koordinatX <= serhedYoxla)
		{
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				if (xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] == '#')
				{
					gemiYerYoxla++;
				}

				Gemiler[i].koordinatX++;

			}
			if (gemiYerYoxla > 0)
			{
				break;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				Gemiler[i].koordinatX--;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] = '#';
				Gemiler[i].koordinatX++;
			}
			--Gemiler[i].koordinatX;
		}
		else
		{
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				if (xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] == '#')
				{
					gemiYerYoxla++;
				}

				Gemiler[i].koordinatX--;

			}
			if (gemiYerYoxla > 0)
			{
				break;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				Gemiler[i].koordinatX++;
			}
			for (int n = 1; n <= Gemiler[i].olcu; n++)
			{
				xerite[Gemiler[i].koordinatY][Gemiler[i].koordinatX] = '#';
				Gemiler[i].koordinatX--;
			}
			++Gemiler[i].koordinatX;
		}
		break;
	}
}

void doyus(donanma oyuncuGemileri[], donanma dusmenGemileri[], char xerite1[][10], char xerite2[][10], char xerite3[][10], char xerite4[][10], int& qelebeler, int& meglubiyyetler)
{
	int oyuncuXal = 0;
	int dusmenXal = 0;
	bool qelebeYoxla = true;

	cout << "Doyus baslanir. Dusmen gemilerinin yerini tapib mehv edin!\n";
	cout << "Vurdugunuz xanada X varsa gemi vurulub, o yazilibsa bosa cixdi.\n";

	while (qelebeYoxla)
	{
		int zerbeX;
		int zerbeY;

		cout << "\nBurda sizin zerbeler gorunur.\n";
		xeriteGoster(xerite3);

		cout << "\nHucum vaxtidir!" << "\n\nX koordinatini daxil edin: ";
		cin >> zerbeX;
		zerbeX--;
		cout << "\nY koordinatini daxil edin: ";
		cin >> zerbeY;
		zerbeY--;
		system("cls");
		if (zerbeX < 0 || zerbeX > 9)
		{
			system("cls");
			cout << "\nSehv X koordinati daxil etdiniz. Yeniden cehd edin!\n";
			continue;
		}
		if (zerbeY < 0 || zerbeY > 9)
		{
			system("cls");
			cout << "\nSehv Y koordinati daxil etdiniz. Yeniden cehd edin!\n";
			continue;
		}

		switch (xerite2[zerbeY][zerbeX])
		{
			system("cls");
		case '~': xerite2[zerbeY][zerbeX] = 'o';
			xerite3[zerbeY][zerbeX] = 'o';
			cout << "\nBosa getdi!!\n";

			break;
		case '#': oyuncuXal++;
			xerite2[zerbeY][zerbeX] = 'X';
			xerite3[zerbeY][zerbeX] = 'X';
			gemiYoxla(dusmenGemileri, xerite2, zerbeX, zerbeY);
			system("cls");
			cout << "\nEla! Dusmen gemisini vurdun!\n";
			break;
		default:
			system("cls");
			cout << "\nEyni yeri evvelceden vurmusunuz. Yeniden cehd edin!\n";
			continue;
			break;
		}
		xeriteGoster(xerite3);

		for (int i = 0; i < 5; i++)
		{
			if (dusmenGemileri[i].can == 0)
			{
				system("cls");
				cout << "\nBir dusmen gemisini mehv etdiniz!\n ";
				dusmenGemileri[i].can++;
			}
		}
		teslimOl(qelebeYoxla, meglubiyyetler);
		if (qelebeYoxla == false)
		{
			break;
		}

		bool yoxla = true;
		while (yoxla)
		{
			int randomX = rand() % 10;
			int randomY = rand() % 10;

			cout << "\nDusmen zerbeleri: " << randomX + 1 << ", " << randomY + 1;

			switch (xerite1[randomY][randomX])
			{
			case '~': xerite1[randomY][randomX] = 'o';
				xerite4[randomY][randomX] = 'o';

				cout << "\nDusmen bosa atdi!!\n";
				yoxla = false;
				break;
			case '#': dusmenXal++;
				xerite1[randomY][randomX] = 'X';
				xerite4[randomY][randomX] = 'X';
				gemiYoxla(oyuncuGemileri, xerite1, randomX, randomY);

				cout << "\nDusmen terefinden vuruldun!\n"; yoxla = false;
				break;
			default:
				system("cls");
				//cout << "\nDusmen istiqameti qarisdirdi. Yeniden cehd edir!\n";
				break;
			}

		}
		cout << "\nDusmenin zerbe endirdiyi yer. \n";
		xeriteGoster(xerite4);

		cout << "\nDusmenin zerbe endirdiyi yer. \n";
		xeriteGoster(xerite1);

		if (oyuncuXal == 17)
		{
			system("cls");
			cout << "\nTebrikler! Qalib geldiniz!\n";
			qelebeYoxla = false;
			qelebeler++;
		}
		if (dusmenXal == 17)
		{
			system("cls");
			cout << "\nTeessuf! Meglub oldun!\n";
			qelebeYoxla = false;
			meglubiyyetler++;
		}
		teslimOl(qelebeYoxla, meglubiyyetler);
	}
}

void gemiYoxla(donanma Gemiler[], char xerite[][10], int X, int Y)
{
	for (int i = 0; i < 5; i++)
	{
		int serhedYoxla = (10 - Gemiler[i].olcu);

		switch (Gemiler[i].istiqamet)
		{
		case 1:
			if (Gemiler[i].koordinatY > serhedYoxla)
			{
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					if (Gemiler[i].koordinatX == X && Gemiler[i].koordinatY == Y)
					{
						Gemiler[i].can--;
					}
					Gemiler[i].koordinatY--;
				}
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					Gemiler[i].koordinatY++;
				}
			}
			else
			{
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					if (Gemiler[i].koordinatX == X && Gemiler[i].koordinatY == Y)
					{
						Gemiler[i].can--;
					}
					Gemiler[i].koordinatY++;
				}
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					Gemiler[i].koordinatY--;
				}
			}
		case 2:
			if (Gemiler[i].koordinatX > serhedYoxla)
			{
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					if (Gemiler[i].koordinatX == X && Gemiler[i].koordinatY == Y)
					{
						Gemiler[i].can--;
					}
					Gemiler[i].koordinatX--;
				}
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					Gemiler[i].koordinatX++;
				}
			}
			else
			{
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					if (Gemiler[i].koordinatX == X && Gemiler[i].koordinatY == Y)
					{
						Gemiler[i].can--;
					}
					Gemiler[i].koordinatX++;
				}
				for (int n = 1; n <= Gemiler[i].olcu; n++)
				{
					Gemiler[i].koordinatX--;
				}
			}
			break;
		}
	}
}

void teslimOl(bool& qelebeYoxla, int& meglubiyyetler)
{
	bool yoxla = true;
	while (yoxla)
	{
		char teslimOl;
		cout << "\nDavam etmek ucun D duymesine, teslim olmaq ucun X duymesine basin: ";
		cin >> teslimOl;
		system("cls");
		switch (teslimOl)
		{
		case 'd': yoxla = false;
			break;
		case 'x': qelebeYoxla = false; yoxla = false;
			meglubiyyetler++;
			break;
		default: cout << "\nSadece D ve ya X duymesini sece bilersiniz.\n";

			break;
		}
	}
}