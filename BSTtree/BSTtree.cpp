
#include "pch.h"

int main()
{
    std::cout << "Podaj liczby! Wpisz -1 by zakonczyc.\n"; 
	std::vector<int> num;
	int  temp=1;
	std::cin >> temp;
	while (1)
	{
		num.push_back(temp);
		std::cin >> temp;
		if (temp == -1) break;
	}
	Tree t(num);
	t.inOrder();
	t.preOrder();

}
