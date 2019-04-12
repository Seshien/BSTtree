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
	int i;
	for (i=0; i <= 10; i++)
	{
		std::cout << "--------------- Test dla " << _testNum[progress] << " liczb. ---------------" << std::endl;
		Tree bst;
		std::vector<int> num = gen(_testNum[progress]);
		auto begin = std::chrono::high_resolution_clock::now();
		bst.createNonAVL(num);
		auto end = std::chrono::high_resolution_clock::now();
		double us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[0][i] = us / 1e6;
		std::cout << "------------- Drzewo utworzone -------------" << std::endl;


		begin = std::chrono::high_resolution_clock::now();
		bst.findMin();
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[1][i] = us / 1e6;

		begin = std::chrono::high_resolution_clock::now();
		bst.inOrder();
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[2][i] = us / 1e6;

		begin = std::chrono::high_resolution_clock::now();
		bst.balance();
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[3][i] = us / 1e6;
		bst.postOrderDelete();


		Tree avl;
		//mergeSort(num);
		begin = std::chrono::high_resolution_clock::now();
		avl.createAVL(num);
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[4][i] = us / 1e6;
		std::cout << "------------- Drzewo utworzone -------------" << std::endl;


		begin = std::chrono::high_resolution_clock::now();
		avl.findMin();
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[5][i] = us / 1e6;

		begin = std::chrono::high_resolution_clock::now();
		avl.inOrder();
		end = std::chrono::high_resolution_clock::now();
		us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		time[6][i] = us / 1e6;
	}
	//begin = std::chrono::high_resolution_clock::now();
	//avl.balance();
	//end = std::chrono::high_resolution_clock::now();
	//us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	//times[progress].timeAB = us / 1e6;
	double sum[] = { 0,0,0,0,0,0,0 };

	for (i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sum[i] += time[i][j];
		}
		sum[i] /= 10.0;
	}
	double sumo[] = { 0,0,0,0,0,0,0 };
	for (i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sumo[i] += (sum[i] - time[i][j])*(sum[i] - time[i][j]);
		}
		sumo[i] /= 10.0;
	}

	getData(sum, sumo);
	std::cout << "--------------- Test zakonczony ---------------" << std::endl;

}
void Tester::getData(double sum[], double sumo[])
{
	std::fstream file;
	file.open("data.txt", std::ios::app);
	std::string line;
	line = std::to_string(_testNum[progress]) + ";" + std::to_string(sum[0]) + ";" + std::to_string(sum[1]) + ";" + std::to_string(sum[2]) + ";" + std::to_string(sum[3])
		+ ";;" + std::to_string(sum[4]) + ";" + std::to_string(sum[5]) + ";" + std::to_string(sum[6]) + ";0" 
		+ ";" + std::to_string(sumo[0]) + ";" + std::to_string(sumo[1]) + ";" + std::to_string(sumo[2]) + ";" + std::to_string(sumo[3])
		+ ";;" + std::to_string(sumo[4]) + ";" + std::to_string(sumo[5]) + ";" + std::to_string(sumo[6]) + ";0"
		+ "\n";
	file << line;
	file.close();
	return;

}