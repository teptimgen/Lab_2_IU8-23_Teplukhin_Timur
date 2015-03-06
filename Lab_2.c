#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//###########################################################################
typedef unsigned int uint;
typedef unsigned char uchar;
//###########################################################################
uchar* func__quick_sort(uchar *uchar_array, uint first, uint last)
{
    uchar buf, x = uchar_array[(first + last) / 2];
	uint i = first, j = last;
	//-----------------------------------------------------------------------
    do
	{
        while (uchar_array[i] < x) i++;
        while (uchar_array[j] > x) j--;
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
	//-----------------------------------------------------------------------
    if (i < last) func__quick_sort(uchar_array, i, last);
    if (first < j) func__quick_sort(uchar_array, first, j);
	//-----------------------------------------------------------------------
	return uchar_array;
}
//###########################################################################
int main()
{
	uint n, i, j;
	//-----------------------------------------------------------------------
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	//-----------------------------------------------------------------------
	uchar *uchar_array = (uchar *)malloc(n*sizeof(uchar));
	printf("\nInitial array.\n");
	for (uint i = 0; i < n; i++)
	{
		uchar_array[i] = rand();
		printf("%d ", uchar_array[i]);
	}
	//-----------------------------------------------------------------------
	uchar_array=func__quick_sort(uchar_array, 0, n-1);
	//-----------------------------------------------------------------------
	printf("\n\nSorted array.\n");
	for (i = 0; i < n; i++) printf("%d ", uchar_array[i]);
	//-----------------------------------------------------------------------
	_getch();
	return 0;
}
//###########################################################################
