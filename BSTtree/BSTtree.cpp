
#include "pch.h"

int main()
{
	std::cout << "Witamy w symulatorze drzew binarnych." << std::endl;
	std::vector<int> num;
	int  temp=1;
	char choice;
	bool type=false,end=true;
	Tree t;
	while (end)
	{
		while (num.empty())
		{
			std::cout << "Musisz utworzyc tablice na ktorej bedziesz pracowal." << std::endl;
			std::cout << "Czy chcesz uzyc generatora? [y/n]" << std::endl;
			std::cin >> choice;

			if (choice == 'y')
			{
				std::cout << "Prosze wybrac ilosc elementow do wygenerowania." << std::endl;
				std::cin >> temp;
				num = gen(temp);
			}

			else
			{
				std::cout << "Podaj liczby! Wpisz -1 by zakonczyc." << std::endl;
				std::cin >> temp;
				while (temp != -1)
				{
					num.push_back(temp);
					std::cin >> temp;
				}
			}

			if (!(num.empty()))
			{
				std::cout << "Wybierz typ drzewa. [to do]" << std::endl;
				t.createNonAVL(num);
			}

		}
		std::cout << "Tablica istnieje. Wybierz czynnosc z listy." << std::endl;
		std::cout << "Wypisz: max[m], szukana[s]" << std::endl;
		std::cout << "Manipulacja nodami: usun[u], usun kilka[k], dodaj[d], usun cale(postOrder)[c]." << std::endl;
		std::cout << "Wyswietlenie drzewa: inOrder[i], preOrder[p], od podanego node[n]." << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 's':
			std::cin >> temp;
			if (t.findValue(temp) != nullptr)
				std::cout << "Znaleziono szukana wartosc" << std::endl;
			else
				std::cout << "Nie znaleziono szukanej wartosci" << std::endl;
			break;
		case 'm':
			t.findMax();
			break;
		case 'i':
			t.inOrder();
			break;
		case 'p':
			t.preOrder();
			break;
		case 'n':
			std::cin >> temp;
			t.showSubTree(temp);
			break;
		default:
			end = false;
			break;
		}
	}





}
