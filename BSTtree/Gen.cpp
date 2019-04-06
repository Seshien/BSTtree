#include "pch.h"
//mode 0 = losowe, 1 - rosnace, 2 - malej¹ce, 3 - A-ksztaltne, 4 - V-ksztaltne
std::vector<int> gen(int amount, int ranges, int rangee, int mode)
{
	if (rangee == 1000000)
		rangee = amount * 10;
	std::vector<int> data;
	int jump = 1, temp, start = ranges, end = rangee;
	switch (mode)
	{
	case 0:
		for (int i = 0; i < amount; i++)
		{
			temp = ranges + 1 + rand() % (rangee - ranges);
			data.push_back(inrange(temp, start, end));
		}
		break;
	case 1:
		if (rangee - ranges > amount)
			jump = (rangee - ranges) / amount;
		for (int i = 0; i < amount; i++)
		{
			temp = ranges + rand() % jump;
			data.push_back(inrange(temp, start, end));
			ranges += jump;
		}
		break;
	case 2:
		if (rangee - ranges > amount)
			jump = (rangee - ranges) / amount;
		for (int i = 0; i < amount; i++)
		{
			temp = rangee - rand() % jump;
			data.push_back(inrange(temp, start, end));
			rangee -= jump;
		}
		break;
	case 3:
		if (rangee - ranges > amount / 2)
			jump = ((rangee - ranges) * 2) / amount;
		for (int i = 0; i < amount / 2; i++)
		{
			temp = ranges + rand() % jump;
			data.push_back(inrange(temp, start, end));
			ranges += jump;
		}
		for (int i = amount / 2; i < amount; i++)
		{
			temp = rangee - rand() % jump;
			data.push_back(inrange(temp, start, end));
			rangee -= jump;
		}
		break;
	case 4:
		if (rangee - ranges > amount / 2)
			jump = ((rangee - ranges) * 2) / amount;
		for (int i = 0; i < amount / 2; i++)
		{
			temp = rangee - rand() % jump;
			data.push_back(inrange(temp, start, end));
			rangee -= jump;
		}
		for (int i = amount / 2; i < amount; i++)
		{
			temp = ranges + rand() % jump;
			data.push_back(inrange(temp, start, end));
			ranges += jump;
		}
		break;
	default:
		std::cout << "<<--- Error, mode not found. --->>" << std::endl;
		break;
	}
	return data;
}
int inrange(int number, int ranges, int rangee)
{
	if (number > rangee) return rangee;
	if (number < ranges) return ranges;
	return number;
}
