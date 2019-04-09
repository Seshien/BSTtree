
#include "pch.h"

int main()
{
	std::cout << "<--- Witamy w symulatorze drzew binarnych. --->" << std::endl;
	std::vector<int> num;
	int  temp=1;
	char choice;
	bool type=false,end=true;
	Tree t;
	while (end)
	{
		std::cout << "<-------------------------------------------------------------->" << std::endl;
		while (!(t.existTree()))//To do dla Macieja
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
				num.clear();
				std::cout << "Podaj liczby! Wpisz -1 by zakonczyc." << std::endl;
				std::cin >> temp;
				while (temp != -1)
				{
					num.push_back(temp);
					std::cin >> temp;
				}
			}

			if (!(t.existTree()))
			{
				std::cout << "Czy chcesz utworzyc drzewo AVL? [y/n]" << std::endl;
				std::cin >> choice;
				if (choice == 'y')
					t.createAVL(num);
				else
					t.createNonAVL(num);
				//t.deleteNode(5); //A co to jest?
			}

		}
		std::cout << "<-------------------------------------------------------------->" << std::endl;
		std::cout << "Tablica istnieje. Wybierz czynnosc z listy." << std::endl;
		std::cout << "<-------------------------------------------------------------->" << std::endl;
		std::cout << "Wypisz: max[m], szukana[s]" << std::endl;
		std::cout << "Manipulacja nodami: usun[u], usun kilka[k], dodaj[d], usun cale(postOrder)[c]." << std::endl;
		std::cout << "Wyswietlenie drzewa: inOrder[i], preOrder[p], od podanego node[n]." << std::endl;
		std::cin >> choice;
		switch (choice)
		{

		case 's':
			std::cout << "Podaj szukana wartosc." << std::endl;
			std::cin >> temp;
			if (t.findValue(temp).second != nullptr)
				std::cout << "Znaleziono szukana wartosc." << std::endl;
			else
				std::cout << "Nie znaleziono szukanej wartosci." << std::endl;
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
		case 'u':
			std::cout << "Podaj wartosc do usuniecia." << std::endl;
			std::cin >> temp;
			t.deleteNode(temp);
			break;
		case 'k':
			std::cout << "Podaj wartosci do usuniecia. Wpisz -1 by zakonczyc." << std::endl;
			std::cin >> temp;
			num.clear();
			while (temp != -1)
			{
				num.push_back(temp);
				std::cin >> temp;
			}
			t.deleteManyNodes(num);
			break;
		case 'd':
			std::cout << "Podaj wartosc do dodania." << std::endl;
			std::cin >> temp;
			t.addNode(temp);
			break;
		case 'n':
			std::cout << "Podaj korzen szukanego poddrzewa." << std::endl;
			std::cin >> temp;
			t.showSubTree(temp);
			break;
		case 'c':
			t.postOrderDelete();
			break;
		default:
			end = false;
			break;
		}
	}





}
