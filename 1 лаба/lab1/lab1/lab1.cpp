
#include <iostream>
#include "Auxil.h"                            
#include <ctime>
#include <locale>


int  d = 0;
int fibo(int n)
{
	d++;
	if (n == 1 || n == 2) return (n - 1);
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    setlocale(LC_ALL, "rus");
	
	int cycle = 500000;
	int av1 = 0;
	double av2 = 0;
	clock_t t1 = 0;
	clock_t t2 = 0;
	

	auxil::start();     // старт генерации                     

	for (int i = 0; i < 6; i++)
	{
		t1 = clock();    // фиксация времени                         
		for (int i = 0; i < cycle; i++)
		{
			av1 += (double)auxil::iget(0, 100); // сумма случайных чисел 
			av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		}

		t2 = clock();   // фиксация времени                         

		
		std::cout << std::endl << "количество циклов:         " << cycle;
		std::cout << std::endl << "среднее значение (int):    " << av1 / cycle;
		std::cout << std::endl << "среднее значение (double): " << av2 / cycle;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "                  (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;
		cycle += 500000;
	}

	//3
		t1 = clock();///фиксация t
		for (int i = 0; i < 100; i++)
		{
			fibo(10);
		}
		t2 = clock();

		std::cout << std::endl << "количество циклов:         " << 100;
		std::cout << std::endl << "среднее значение (int):    " << av1 / 100;
		std::cout << std::endl << "среднее значение (double): " << av2 / 100;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "продолжительность (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << "\n\n";
		

	return 0;
}

