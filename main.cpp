#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include "Header.h"
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	struct storage* Base_of_products = (struct storage*)malloc(sizeof(storage));
	Base_of_products[0].name = (char*)malloc(sizeof(char));
	int number_of_products = 0;
	if (Base_of_products == NULL)
	{
		return 0;
	}
	menu(Base_of_products, &number_of_products);
	return 0;
}
