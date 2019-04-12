#include "pch.h"
void Tester::createFile()
{
	char wait;
	std::fstream file;
	file.open("data.txt", std::ios::out);
	std::string line;
	line = "Wielkosc drzewa;Czas tworzenia;Czas znalezienia min;Czas inOrder;Czas zbalansowania;Drzewo AVL;Czas tworzenia;Czas znalezienia min;Czas inOrder;Czas zbalansowania\n";
	file << line;
	file.close();
}
void Tester::doTests()
{
	createFile();
	for (progress; progress < amountt; progress++)
		test();

}
void Tester::test()
{
	std::cout << "--------------- Test dla " << _testNum[progress] << " liczb. ---------------" << std::endl;
	Tree bst;
	std::vector<int> num = gen(_testNum[progress]);
	auto begin = std::chrono::high_resolution_clock::now();
	bst.createNonAVL(num);
	auto end = std::chrono::high_resolution_clock::now();
	double us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeBC = us / 1e6;

	begin = std::chrono::high_resolution_clock::now();
	bst.findMin();
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeBM = us / 1e6;

	begin = std::chrono::high_resolution_clock::now();
	bst.inOrder();
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeBI = us / 1e6;

	begin = std::chrono::high_resolution_clock::now();
	bst.balance();
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeBB = us / 1e6;
	bst.postOrderDelete();


	Tree avl;
	//mergeSort(num);
	begin = std::chrono::high_resolution_clock::now();
	avl.createAVL(num);
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeAC = us / 1e6;

	begin = std::chrono::high_resolution_clock::now();
	avl.findMin();
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeAM = us / 1e6;

	begin = std::chrono::high_resolution_clock::now();
	avl.inOrder();
	end = std::chrono::high_resolution_clock::now();
	us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	times[progress].timeAI = us / 1e6;

	//begin = std::chrono::high_resolution_clock::now();
	//avl.balance();
	//end = std::chrono::high_resolution_clock::now();
	//us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	//times[progress].timeAB = us / 1e6;
	getData();
	std::cout << "--------------- Test zakonczony" << std::endl;
}

void Tester::getData()
{
	std::fstream file;
	file.open("data.txt", std::ios::app);
	std::string line;
	line = std::to_string(_testNum[progress]) + ";" + std::to_string(times[progress].timeBC) + ";" + std::to_string(times[progress].timeBM) + ";" + std::to_string(times[progress].timeBI) + ";" + std::to_string(times[progress].timeBB)
		+ ";;" + std::to_string(times[progress].timeAC) + ";" + std::to_string(times[progress].timeAM) + ";" + std::to_string(times[progress].timeAI) + ";" + std::to_string(times[progress].timeAB) + "\n";
	file << line;
	file.close();
	return;

}