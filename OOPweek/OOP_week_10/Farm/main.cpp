#include <iostream>
#include <string>
#include <time.h>
#include "Cow.h"
#include "Sheep.h"
#include "Donkey.h"
#include "Farm.h"

using namespace std;

void printFarm(Farm* f[], int n);
void menu();
void feed(Farm* f[], int n);
void milk(Farm* f[], int n);
void breed(Farm* f[], int n);

void main()
{
	srand(time(0));
	Farm *F[50];
	int choose = -1;
	int n = 0;
	while (choose != 0)
	{
		menu();
		cout << "nhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int choose2;
			cout << "1. bo" << endl;
			cout << "2. cuu" << endl;
			cout << "3. lua" << endl;
			cin >> choose2;
			switch (choose2)
			{
			case 1:
			{
				F[n] = new Cow();
			}; break;
			case 2:
			{
				F[n] = new Sheep();
			}; break;
			case 3:
			{
				F[n] = new Donkey();
			}; break;
			}
			n++;
		}; break;
		case 2:
		{
			feed(F, n);
		}; break;
		case 3:
		{
			milk(F, n);
		}; break;
		case 4:
		{
			breed(F, n);
		}; break;
		case 5:
		{
			printFarm(F, n);
		}; break;
		}
	}
}
void printFarm(Farm* f[], int n)
{
	for (int i = 0; i < n; i++)
	{
		f[i]->printInfo();
	}
}
void menu()
{
	cout << "- Happy Farm -" << endl;
	cout << "1. them dong vat" << endl;
	cout << "2. cho an" << endl;
	cout << "3. vat sua" << endl;
	cout << "4. cho de" << endl;
	cout << "5. in trang trai" << endl;
	cout << "0. thoat" << endl;
}
void feed(Farm* f[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		f[i]->setFull();
	}
	cout << "da cho an" << endl;
}
void milk(Farm* f[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		f[i]->setMilk();
	}
	cout << "vat xong" << endl;
}
void breed(Farm* f[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		f[i]->setBreed();
	}
	cout << "de xong" << endl;
}
