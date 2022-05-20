#include "stdafx.h"
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levinshtein.h"
#include "MultyMatrix.h"

#define N 6
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

void Task1_2() {
	srand(time(NULL));
	/*char abc[25];
	char s1[300], s2[250];

	for (int i = 97, n = 0; i <= 122; ++i, ++n)
	{
		abc[n] = (char)i;
	}
	std::cout << "S1 = ";
	for (int i = 0; i < 300; i++)
	{
		s1[i] = abc[_rand(0, 25)];
		if (i % 100 == 0)
			std::cout << std::endl;
		std::cout << s1[i];
	}
	std::cout << std::endl << std::endl << "S2 =";

	for (int i = 0; i < 251; i++)
	{
		s2[i] = abc[_rand(0, 25)];
		if (i % 100 == 0)
			std::cout << std::endl;
		std::cout << s2[i];
	}
	std::cout << std::endl;*/
	char s1[4] = "ель";
	char s2[6] = "дрель";
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int lx = sizeof(s1);
	int ly = sizeof(s2);

	int S1_size[]{ 12, 15, 20, 30, 60, 150, 300 };
	int S2_size[]{ 10, 13, 17, 25, 50, 125, 250 };

	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----";
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---" << std::endl;
	for (int i = 0; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(S1_size[i], s1, S2_size[i], s2);
		t2 = clock();
		t3 = clock();
		levenshtein(S1_size[i], s1, S2_size[i], s2);
		t4 = clock();
		std::cout << std::right << std::setw(2) << S1_size[i] << "/" << std::setw(2) << S2_size[i]
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}
}
void Task5() {
	srand(time(NULL));
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int Mc[N + 1] = { 8, 11, 19, 22, 29, 39, 50}, Ms[N][N], r = 0, rd = 0;
	memset(Ms, 0, sizeof(int) * N * N);
	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();

	std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) " << std::endl;
	std::cout << std::endl << "затраченное время(сек):  " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << r;
	std::cout << std::endl << "\nматрица S";
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);
	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();
	std::cout << std::endl
		<< "-- расстановка скобок (динамичеое программирование) " << std::endl;
	std::cout << std::endl << "затраченное время(сек):  " << ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << rd;
	std::cout << std::endl << "\nматрица S";
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	//Task1_2();
	Task5();
	system("pause");
	return 0;
}