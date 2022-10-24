// Test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit...

#include <iostream>
#include <string>
#include <random>
using namespace std;

int bet(int * money) {
	int betValue = 0;
	while (betValue < 1 or betValue > *money)
	{
		cout << "Choisissez votre mise : ";
		cin >> betValue;
	}
	return betValue;
}

void roulette(int * money)
{
	cout << "Bienvenue au jeu de la roulette !\n";
	int betValue = bet(money);

	int choice = -1;
	while (choice < 1 or choice > 2)
	{
		cout << "Sur quoi vous souhaitez parier ?\n1. Pair/Impair\n2. Numéro";
		cin >> choice;
	}
	int randNumber = rand() % (100 - 0 + 1);
	if (choice == 1)
	{
		int betValue = -1;
		while (betValue < 1 or betValue > 2)
		{
			cout << "Sur quoi pariez-vous ?\n1. Pair\n2. Impair";
			cin >> betValue;
		}
		if ((randNumber % 2 == 0 and betValue == 1) or (randNumber % 2 == 1 and betValue == 2))
		{
			*money += betValue * 1.2;
			cout << "La boule tourne...\n et s'arrête sur le " << randNumber << ".\nVous gagnez: " << betValue * 1.2 << "$ !\n";
		}
		else
		{
			*money -= betValue;
			cout << "La boule tourne...\n et s'arrête sur le " << randNumber << " C'est perdu...";
		}
	}
	else
	{
		int betNumber = -1;
		while (betNumber < 0 and betNumber > 100)
		{
			cin >> betNumber;
		}
		if (randNumber == betNumber)
		{
			*money += betValue * 5;
			cout << "La boule tourne...\n et s'arrête sur le " << randNumber << " C'est votre numéro !!!\nVous gagnez: " << betValue *5 << "$ !\n";
		}
	}
}

void intalea(int * money)
{
	cout << "Bienvenue au jeu du nombre aléatoire !\n";

	int mise = bet(money);

	int randNumber = rand() % (100 - 0 + 1);
	int number = -1;
	int attempt = 0;
	while (number != randNumber)
	{
		cout << "Entrez une valeur entre 0 et 100: ";
		attempt++;
		cin >> randNumber;
		if (randNumber > number)
		{
			cout << "Ce nombre est trop grand !\n";
		}
		else if (randNumber < number)
		{
			cout << "Ce nombre est trop petit !\n";
		}
		if (attempt == 5)
		{
			break;
		}
	}
	if (number == randNumber)
	{
		*money += mise * (0.2 * (6 - attempt));
		cout << "Bravo vous avez trouvé en " << attempt << " essais !\n";
	}
	else
	{
		*money -= mise;
		cout << "Perdu ! Vous n'avez plus d'essais restants... Vous perdez votre mise...\n";
	}
	
}

int main()
{
	srand(time(NULL));
	cout << "Bienvenue au PmCasino !\n";
	int mode = -1;
	int money = 100;
	while (mode != 3)
	{
		
		if (money > 0)
		{
			cout << "Vous avez " << money << "$.\nChoisissez votre jeu:\n1. Jeu du nombre aléatoire\n2. Jeu de la roulette\n3. Quitter\n";
			cin >> mode;
			if (mode == 1)
			{
				intalea(&money);
			}
			else if (mode == 2)
			{
				roulette(&money);
			}
		}
		else
		{
			cout << "Vous êtes ruinés... Vous n'avez plus d'argent... ";
			break;
		}	
	}
}