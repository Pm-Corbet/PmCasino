// Test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <random>
using namespace std;

int miser(int * money) {
	int mise = 0;
	while (mise < 1 or mise > *money)
	{
		cout << "Choisissez votre mise : ";
		cin >> mise;
	}
	return mise;
}

void roulette(int * money)
{
	cout << "Bienvenue au jeu de la roulette !\n";
	int mise = miser(money);

	int choice = -1;
	while (choice < 1 or choice > 2)
	{
		cout << "Sur quoi vous souhaitez parier ?\n1. Pair/Impair\n2. Numéro";
		cin >> choice;
	}
	int number = rand() % (100 - 0 + 1);
	if (choice == 1)
	{
		int numero = -1;
		while (numero < 1 or numero > 2)
		{
			cout << "Sur quoi pariez-vous ?\n1. Pair\n2. Impair";
			cin >> numero;
		}
		if ((number % 2 == 0 and numero == 1) or (number % 2 == 1 and numero == 2))
		{
			*money += mise * 1.2;
			cout << "La boule tourne...\n et s'arrête sur le " << number << ".\nVous gagnez: " << mise * 1.2 << "$ !\n";
		}
		else
		{
			*money -= mise;
			cout << "La boule tourne...\n et s'arrête sur le " << number << " C'est perdu...";
		}
	}
	else
	{
		int numero = -1;
		while (numero < 0 and numero > 100)
		{
			cin >> numero;
		}
		if (number == numero)
		{
			*money += mise * 5;
			cout << "La boule tourne...\n et s'arrête sur le " << number << " C'est votre numéro !!!\nVous gagnez: " << mise*5 << "$ !\n";

		}
	}
}

void intalea(int * money)
{
	cout << "Bienvenue au jeu du nombre aléatoire !\n";

	int mise = miser(money);

	int number = rand() % (100 - 0 + 1);
	int answer = -1;
	int attempt = 0;
	while (number != answer)
	{
		cout << "Entrez une valeur entre 0 et 100: ";
		attempt++;
		cin >> answer;
		if (answer > number)
		{
			cout << "Ce nombre est trop grand !\n";
		}
		else if (answer < number)
		{
			cout << "Ce nombre est trop petit !\n";
		}
		if (attempt == 5)
		{
			break;
		}
	}
	if (number == answer)
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