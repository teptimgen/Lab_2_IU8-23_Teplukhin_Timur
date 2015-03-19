/// Отключение warning-оповещений
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/// Объявление нового имени для беззнакового типа int
typedef unsigned int uint;
/// Объявление нового имени для беззнакового типа char
typedef unsigned char uchar;

/**\param uchar_array − адрес буфера назначения
 * \param first − индекс первого элемента
 * \param last − индекс последнего элемента
 * \return uchar_array - отсортированный массив
 */
/// Функция func__quick_sort() − точка входа в функцию быстрой сортировки
uchar* func__quick_sort(uchar *uchar_array, uint first, uint last)
{
	///> Алгоритм функции
	///- Объявление буферной переменной buf и переменной mid для медианы входного массива
	uchar buf, mid = uchar_array[(first + last) / 2];
	///- Объявление индексовых переменных
	uint i = first, j = last;
	///- Реализация алгоритма быстрой сортировки
    do
	{
        while (uchar_array[i] < mid) i++;
        while (uchar_array[j] > mid) j--;
        if(i <= j)
		{
            if (uchar_array[i] > uchar_array[j])
			{
				buf = uchar_array[i]; uchar_array[i] = uchar_array[j];
				uchar_array[j] = buf;
			}
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) func__quick_sort(uchar_array, i, last);
    if (first < j) func__quick_sort(uchar_array, first, j);

	///- Возврат значения - отсортированный массив
	return uchar_array;
}

/// Функция main() − точка входа в программу.
int main()
{
	///> Алгоритм функции
	///- Объявление переменной n (размер массива) и индексовых переменных
	uint n, i, j;

	///- Информационное сообщение программы "Введите количество элементов массива"
	printf("Enter number of array elements: ");
	///- Ввод с клавиатуры размерности массива
	scanf("%d", &n);

	///- Объявление массива размерности n
	uchar *uchar_array = (uchar *)malloc(n*sizeof(uchar));
	///- Информационное сообщение программы "Первоначальный массив"
	printf("\nInitial array.\n");
	///- Цикл заполнения массива генератором псевдослучайных чисел
	for (uint i = 0; i < n; i++)
	{
		///- Генерирование числа для i-го элемента массива
		uchar_array[i] = rand();
		///- Информационное сообщение программы - вывод i-го элемента массива
		printf("%d ", uchar_array[i]);
	}

	///- Вызов функции func__quick_sort()
	uchar_array=func__quick_sort(uchar_array, 0, n-1);

	///- Информационное сообщение программы "Отсортированный массив"
	printf("\n\nSorted array.\n");
	///- Цикл вывода элементов отсортированного массива на экран
	for (i = 0; i < n; i++)
		///- Информационное сообщение программы - вывод i-го элемента отсортированного массива
		printf("%d ", uchar_array[i]);

	///- Пауза в работе программы
	_getch();
	///- Возврат значения - завершение работы программы
	return 0;
}
