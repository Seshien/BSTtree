#pragma once
#include "pch.h"
#define amountt 16
//Zmierz czasy wykonywania nastêpuj¹cych operacji na obu drzewach: tworzenie drzewa (bez czasu sortowania), 
//wyszukiwanie elementu o minimalnej wartoœci, wypisywanie wszystkich elementów drzewa (in-order), równowa¿enia drzewa BST.
struct _times
{
	double timeBC = -1;
	double timeBM = -1;
	double timeBI = -1;
	double timeBB = -1;
	double timeAC = -1;
	double timeAM = -1;
	double timeAI = -1;
	double timeAB = 0;
};
class Tester
{
public:
	Tester() {};
	void doTests();
	void test();

private:
	void createFile();
	size_t _testNum[amountt] = { 10,50,100,200,500,1000,2000,5000,10000,20000,50000,100000,200000,300000,400000,500000};
	int progress = 0;
	_times times[10];
	double time[7][10];
	void getData(double sum[], double sumo[]);
	void createFileTemp(double sum[], double sumo[]);
};