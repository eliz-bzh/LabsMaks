#include <iostream>

//Даны массивы A и B, состоящие из n элементов.
//Построить массив S, каждый элемент которого равен 
//сумме соответствующих элементов массивов A и B.

int* newArray(int* A, int* B, int n)// задача 1
{
	int* S = new int[n];
	for (int i = 0; i != n; i++)
	{
		*(S + i) = *(A + i) + *(B + i);
	}
	return S;
}

//Заданы два массива А(n) и В(n).
//Значения элементов сформировать случайным образом в диапазоне 0 - 50. 
//Подсчитать в каждом из них количество элементов, меньших значения Х(ввести с клавиатуры).
//Результаты вывести на экран – сформированные массивы и количество элементов.

int* fillArray(int* array, int size)
{
	std::cout <<  "Elements:" << std::endl;
	for (int i = 0; i != size; ++i)
	{
		*(array + i) = rand() % 51;
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
	return array;
}

void lessNumber(int* arr1, int* arr2, int n, int number)// задача 2
{
	arr1 = fillArray(arr1, n);
	arr2 = fillArray(arr2, n);
	int res1 = 0;
	int res2 = 0;
	for (int i = 0; i != n; i++)
	{
		if (*(arr1 + i) < number)
		{
			++res1;
		}
		if(*(arr2 + i) < number)
		{
			++res2;
		}
	}
	std::cout << "Amount of elements of the first array " << res1 << std::endl;
	std::cout << "Amount of elements of the second array " << res2 << std::endl;
}


//Сформировать элементы массива по следующему правилу х[0] = 0, x[1] = 1, 
//x[2] = x[0] + x[1], …..x[n] = x[n - 1] + x[n - 2].

void fiborachi(int* array, int size)// задача 3
{
	array[0] = 0;
	std::cout << array[0] << " ";
	array[1] = 1;
	std::cout << array[1] << " ";
	for (int i = 2; i != size; ++i)
	{
		*(array + i) = *(array + (i - 1)) + *(array + (i - 2));
		std::cout << *(array + i) << " ";
	}
}

//Дан массив A из n элементов и B из m элементов.
//Содержится ли наибольший элемент массива A в массиве B ?

int greaterEl(int* array, int size)
{
	int greaterEl = array[0];
	for (int i = 1; i != size; i++)
	{
		if (greaterEl < array[i]) 
		{
			greaterEl = array[i];
		}
	}
	return greaterEl;
}

bool contain(int* array, int* array1, int n, int m)// задача 4
{
	int greater = greaterEl(array, n);
	for (int i = 0; i < m; i++)
	{
		if (array1[i] == greater)
			return 1;
	}
	return 0;
}

int main()
{
	//задача 1
	/*int arr1_1[4] = { 1,2,3,4 };
	int arr2_1[4] = { 1,2,3,4 };
	int* res = newArray(arr1_1, arr2_1, 4);
	for (int i = 0; i < 4; i++)
	{
		std::cout << res[i] << std::endl;
	}*/

	//задача 2
	/*int arr1_2[5] = {};
	int arr2_2[5] = {};
	lessNumber(arr1_2, arr2_2, 5, 40);*/

	//задача 3
	/*int arr1_3[5] = {};
	fiborachi(array, 5);*/

	//задача 4
	int arr1_4[5] = { 1, 2, 3, 4, 5 };
	int arr2_4[8] = { 1, 2, 3, 4, 3, 2, 2, 2 };
	std::cout << contain(arr1_4, arr2_4, 5, 8) << std::endl;
}