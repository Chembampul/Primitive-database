#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct storage
{
	char* name;
	float price;
	int number;
	float percent_of_allowance;
};

int fl = 0;

int correctInt()
{
	rewind(stdin);
	int i = 0, checker = 0, number = 0;
	char* str = (char*)malloc(255);
	char* string = (char*)malloc(255);
	do {
		if (checker)
			printf("Неверное значение, повторите попытку\n");

		fgets(str, 255, stdin);
		
		str[strlen(str) - 1] = '\0';
		number = atoi(str);
		itoa(number, string, 10);
		checker = 1;
	} while (strcmp(str, string) != 0);
	return number;
}

void input(struct storage* Base_of_products, int* number_of_products)
{
	
	fl = 1;

	do {
		rewind(stdin);

		(*number_of_products)++;
		int ind = (*number_of_products) - 1;

		if (*number_of_products > 1)
		{
			Base_of_products[ind].name = (char*)malloc(sizeof(char));
		}

		printf("Наименование товара\t");
		Base_of_products[ind].name = (char*)malloc(255 * sizeof(char));
		fgets(Base_of_products[ind].name, 255, stdin);
		
		Base_of_products[ind].name[strlen(Base_of_products[ind].name) - 1] = '\0';
		rewind(stdin);
		printf("\nЦена товара\t");
		while (!scanf("%f", &Base_of_products[ind].price))
		{
			printf("Неверный формат ввода\n");
			rewind(stdin);

		}
		while (Base_of_products[ind].price <= 0)
		{
			printf("Значение может быть только положительным, повторите ввод\n");

			scanf("%f", &Base_of_products[ind].price);
		}
		rewind(stdin);
		printf("\nКоличество товара\t");
		Base_of_products[ind].number = correctInt();
		while (Base_of_products[ind].number < 0)
		{
			printf("Значение не может быть отрицательным, повторите ввод\n");

			scanf("%d", &(Base_of_products[ind].number));
		}
		printf("\nПроцент надбавки на товар\t");
		while (!scanf("%f", &Base_of_products[ind].percent_of_allowance))
		{
			printf("Неверный формат ввода\n");
			rewind(stdin);

		}
		while (Base_of_products[ind].percent_of_allowance < 0)
		{
			printf("Значение не может быть отрицательным, повторите ввод\n");

			scanf("%f", &Base_of_products[ind].percent_of_allowance);
		}

		system("CLS");
		rewind(stdin);
		puts("Добавить ещё один товар?\nВведите Y\nИли нажмите Enter, чтобы продолжить");
	} while (getchar() == 'Y');
	rewind(stdin);
}

void output(struct storage* Base_of_products, int* number_of_products)
{

	system("CLS");
	if (fl == 0)
	{
		printf("Введите данные в структуру\n");
		return;
	}
	printf("%-30.30s%-30.30s%-30.30s%-30.30s\n", "Наименование товара", "Цена товара", "Количество товара", "Процент надбавки на товар");
	for (int i = 0; i < *number_of_products; i++)
	{
		printf("%-30s%-30.3lf%-30d%-30.3lf\n", Base_of_products[i].name, Base_of_products[i].price, Base_of_products[i].number, Base_of_products[i].percent_of_allowance);
	}
}

void edit(struct storage* Base_of_products, int* number_of_products)
{
	int n, c, edit_int;
	float edit_float;
	system("CLS");
	if (fl == 0)
	{
		printf("Введите данные в структуру\n");
		return;
	}
	printf("\nВведите номер изменяемой структуры:\n");
	n = correctInt();

	while (n<1 || n> * number_of_products)
	{
		printf("Товара с данным номером не существует, повторите ввод\n");

		while (!scanf("%d", &n))
		{
			printf("Неверный формат ввода\n");
			rewind(stdin);
		}
	}
	printf("Выберите, что вы хотите редактировать:\n1 - Наименование товара\n2 - Цену товара\n3 - Количество товара\n");
	printf("4 - Процент надбавки на товар\n");
	c = correctInt();

	while (c < 1 || c>4)
	{
		printf("Нет введённой функции, повторите ввод\n");

		while (!scanf("%d", &c))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
	}
	switch (c)
	{
	case 1:
		free(Base_of_products[n - 1].name);

		printf("Новое наименование изменяемого товара:\t");
		Base_of_products[n - 1].name = (char*)malloc(255 * sizeof(char));
		fgets(Base_of_products[n - 1].name, 255, stdin);

		break;
	case 2:
		printf("Новая цена изменяемого товара:\t");
		while (!scanf("%f", &edit_float))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
		while (edit_float <= 0)
		{
			printf("Значение может быть только положительным, повторите ввод\n");

			while (!scanf("%f", &edit_float))
			{
				printf("Неверный формат ввода, повторите попытку\n");
				rewind(stdin);
			}
		}
		Base_of_products[n - 1].price = edit_float;
		break;
	case 3:
		printf("новое количество изменяемого товара:\t");
		edit_int = correctInt();

		while (edit_int < 0)
		{
			printf("Значение не может быть отрицательным, повторите ввод\n");

			while (!scanf("%d", &edit_int))
			{
				printf("Неверный формат ввода, повторите попытку\n");
				rewind(stdin);
			}
		}
		Base_of_products[n - 1].number = edit_int;
		break;
	case 4:
		printf("Новый процент надбавки изменяемого товара:\t");
		while (!scanf("%f", &edit_float))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
		while (edit_float < 0)
		{
			printf("Значение не может быть отрицательным, повторите ввод\n");
			rewind(stdin);
			while (!scanf("%f", &edit_float))
			{
				printf("Неверный формат ввода, повторите попытку\n");
				rewind(stdin);
			}
		}
		Base_of_products[n - 1].percent_of_allowance = edit_float;
		break;
	default:
		printf("\nНеверное значение\n");
		break;
	}

}
void search_name(struct storage* Base_of_products, int number_of_products)
{
	system("CLS");
	int flg = 0;
	char* str;
	printf("Введите название товара\n");
	str = (char*)malloc(255 * sizeof(char));

	fgets(str, 255, stdin);

	system("CLS");
	printf("Найденные товары\n");
	for (int i = 0; i < number_of_products; i++)
	{
		if (strcmp(Base_of_products[i].name, str) == 0)
		{
			flg = 1;

			printf("%d. Наименование товара: %s", i + 1, Base_of_products[i].name);
			printf("\tЦена %d товара: %.2f", i + 1, Base_of_products[i].price);
			printf("\tКоличество %d товара: %d", i + 1, Base_of_products[i].number);
			printf("\tПроцент надбавки на %d товар: %.2f\n", i + 1, Base_of_products[i].percent_of_allowance);
			printf("\n");
		}
	}
	if (flg == 0)
	{
		printf("Товар с заданным названием не найден\n");
	}
}



void search_price(struct storage* Base_of_products, int number_of_products)
{
	system("CLS");
	int flg = 0;
	float b;
	printf("Введите цену товара\n");
	while (!scanf("%f", &b))
	{
		printf("Неверный формат ввода\n");

	}
	while (b < 0)
	{
		printf("Значение может быть только положительным, повторите ввод\n\n");

		scanf("%f", &b);
	}
	printf("Найденные товары\n");
	for (int i = 0; i < number_of_products; i++)
	{
		if (Base_of_products[i].price == b)
		{
			flg = 1;
			printf("%d. Наименование товара: %s", i + 1, Base_of_products[i].name);
			printf("\tЦена %d товара: %.2f", i + 1, Base_of_products[i].price);
			printf("\tКоличество %d товара: %d", i + 1, Base_of_products[i].number);
			printf("\tПроцент надбавки на %d товар: %.2f\n", i + 1, Base_of_products[i].percent_of_allowance);
			printf("\n");
		}
	}
	if (flg == 0)
	{
		printf("Товар с заданной ценой не найден\n");
	}
}

void search_number(struct storage* Base_of_products, int number_of_products)
{
	system("CLS");
	int flg = 0;
	int b;
	printf("Введите количество товара\n");
	b = correctInt();
	while (b < 0)
	{
		printf("Значение может быть только положительным, повторите ввод\n\n");

		while (!scanf("%d", &b))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);

		}
	}
	printf("Найденные товары\n");
	for (int i = 0; i < number_of_products; i++)
	{
		if (Base_of_products[i].number == b)
		{
			flg = 1;
			printf("%d. Наименование товара: %s", i + 1, Base_of_products[i].name);
			printf("\tЦена %d товара: %.2f", i + 1, Base_of_products[i].price);
			printf("\tКоличество %d товара: %d", i + 1, Base_of_products[i].number);
			printf("\tПроцент надбавки на %d товар: %.2f\n", i + 1, Base_of_products[i].percent_of_allowance);
			printf("\n");
		}
	}
	if (flg == 0)
	{
		printf("Товар с заданным количеством не найден\n");
	}
}

void search_percent(struct storage* Base_of_products, int number_of_products)
{
	system("CLS");
	int flg = 0;
	float b;
	printf("Введите процент надбавки товара\n");
	while (!scanf("%f", &b))
	{
		printf("Неверный формат ввода\n");

	}
	while (b < 0)
	{
		printf("Значение может быть только положительным, повторите ввод\n\n");

		scanf("%f", &b);
	}
	printf("Найденные товары\n");
	for (int i = 0; i < number_of_products; i++)
	{
		if (Base_of_products[i].percent_of_allowance == b)
		{
			flg = 1;
			printf("%d. Наименование товара: %s", i + 1, Base_of_products[i].name);
			printf("\tЦена %d товара: %.2f", i + 1, Base_of_products[i].price);
			printf("\tКоличество %d товара: %d", i + 1, Base_of_products[i].number);
			printf("\tПроцент надбавки на %d товар: %.2f\n", i + 1, Base_of_products[i].percent_of_allowance);
			printf("\n");
		}
	}
	if (flg == 0)
	{
		printf("Товар с заданным процентом надбавки не найден\n\n");
	}
}




void search_one(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	if (fl == 0)
	{
		printf("Введите данные в структуру\n");
		return;
	}
	int choose;
	void (*search[4])(storage*, int);
	do
	{
		printf("Введите параметр поиска\n");
		printf("1 - по имени\n2 - по цене\n3 - по количеству\n4 - по проценту\n0 - возврат в меню\n");

		choose = correctInt();
		while (choose < 1 || choose > 4)
		{
			printf("Неверный формат ввода");

			while (!scanf("%d", &choose))
			{
				printf("Неверный формат ввода, повторите попытку\n");
				rewind(stdin);
			}
		}
		if (choose == 0)
		{
			return;
		}
		search[0] = search_name;
		search[1] = search_price;
		search[2] = search_number;
		search[3] = search_percent;
		search[choose - 1](Base_of_products, *number_of_products);
	} while (choose != 0);
}



void sort_name(struct storage* Base_of_products, int number_of_products)
{
	storage tmp;
	for (int i = 0; i < number_of_products - 1; i++)
	{
		for (int j = number_of_products - 1; j > i; j--)
		{
			if (strcmp(Base_of_products[i].name, Base_of_products[j].name) > 0)
			{
				tmp = Base_of_products[i];
				Base_of_products[i] = Base_of_products[j];
				Base_of_products[j] = tmp;
			}
		}
	}
}

void sort_price(struct storage* Base_of_products, int number_of_products)
{
	storage tmp;
	for (int i = 0; i < number_of_products - 1; i++)
	{
		for (int j = number_of_products - 1; j > i; j--)
		{
			if (Base_of_products[i].price > Base_of_products[j].price)
			{
				tmp = Base_of_products[i];
				Base_of_products[i] = Base_of_products[j];
				Base_of_products[j] = tmp;
			}
		}
	}
}

void sort_number(struct storage* Base_of_products, int number_of_products)
{
	storage tmp;
	for (int i = 0; i < number_of_products - 1; i++)
	{
		for (int j = number_of_products - 1; j > i; j--)
		{
			if (Base_of_products[i].number > Base_of_products[j].number)
			{
				tmp = Base_of_products[i];
				Base_of_products[i] = Base_of_products[j];
				Base_of_products[j] = tmp;
			}
		}
	}
}

void sort_percent(struct storage* Base_of_products, int number_of_products)
{
	storage tmp;
	for (int i = 0; i < number_of_products - 1; i++)
	{
		for (int j = number_of_products - 1; j > i; j--)
		{
			if (Base_of_products[i].percent_of_allowance > Base_of_products[j].percent_of_allowance)
			{
				tmp = Base_of_products[i];
				Base_of_products[i] = Base_of_products[j];
				Base_of_products[j] = tmp;
			}
		}
	}
}



void sort(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	if (fl == 0)
	{
		printf("Введите данные в структуру\n");
		return;
	}
	int choose;
	do
	{
		printf("Введите параметр сортировки\n1 - по названию\n2 - по цене\n3 - по количеству\n4 - по проценту надбавки\n");
		printf("0 - возврат в меню\n");
		choose = correctInt();

		while (choose < 0 || choose > 4)
		{
			printf("Неверный формат ввода\n");

			while (!scanf("%d", &choose))
			{
				printf("Неверный формат ввода\n");
				rewind(stdin);
			}
		}
		if (choose == 0)
		{
			return;
		}
		void(*sort[4])(storage*, int);
		sort[0] = sort_name;
		sort[1] = sort_price;
		sort[2] = sort_number;
		sort[3] = sort_percent;
		sort[choose - 1](Base_of_products, *number_of_products);
	} while (choose != 0);
}

void delete_name(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	char* str;
	printf("Введите наименование товара для удаления\n");
	str = (char*)malloc(255 * sizeof(char));

	fgets(str, 255, stdin);
	rewind(stdin);
	str[strlen(str) - 1] = '\0';


	if (*number_of_products == 1)
	{
		Base_of_products = (storage*)realloc(Base_of_products, sizeof(storage) * (*number_of_products)--);
		Base_of_products[0].name = (char*)malloc(sizeof(char));
	}
	else
	{
		int s = 0;
		for (int i = 0;i < *number_of_products;i++)
		{
			if (strcmp(Base_of_products[i].name, str) == 0)
			{
				s++;
				for (int j = i;j < *number_of_products - 1;j++)
				{
					Base_of_products[j] = Base_of_products[j + 1];
				}
			}
		}
		(*number_of_products) -= s;
	}
	free(str);

}

void delete_price(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	float tmp;
	printf("Введите цену товара для удаления\n");
	while (!scanf("%f", &tmp))
	{
		printf("Неверный формат ввода\n");
		rewind(stdin);
	}
	while (tmp <= 0)
	{
		printf("Цена может быть только положительной, повторите ввод\n");

		while (!scanf("%f", &tmp))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
	}
	
	if (*number_of_products == 1)
	{
		Base_of_products = (storage*)realloc(Base_of_products, sizeof(storage) * (*number_of_products)--);
		Base_of_products[0].name = (char*)malloc(sizeof(char));
	}
	else
	{
		int s = 0;
		for (int i = 0;i < *number_of_products;i++)
		{
			if (Base_of_products[i].price == tmp)
			{
				s++;
				for (int j = i;j < *number_of_products - 1;j++)
				{
					Base_of_products[j] = Base_of_products[j + 1];
				}
			}
		}
		(*number_of_products) -= s;
	}




}

void delete_number(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	int tmp;
	printf("Введите количество товара для удаления\n");
	tmp = correctInt();
	while (tmp < 0)
	{
		printf("Количество не может быть отрицательным, повторите ввод\n");

		while (!scanf("%d", &tmp))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
	}
	if (*number_of_products == 1)
	{
		Base_of_products = (storage*)realloc(Base_of_products, sizeof(storage) * (*number_of_products)--);
		Base_of_products[0].name = (char*)malloc(sizeof(char));
	}
	else
	{
		int s = 0;
		for (int i = 0;i < *number_of_products;i++)
		{
			if (Base_of_products[i].price == tmp)
			{
				s++;
				for (int j = i;j < *number_of_products - 1;j++)
				{
					Base_of_products[j] = Base_of_products[j + 1];
				}
			}
		}
		(*number_of_products) -= s;
	}
}
void delete_percent(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	float tmp;
	printf("Введите процент надбавки товара для удаления\n");
	while (!scanf("%f", &tmp))
	{
		printf("Неверный формат ввода\n");
		rewind(stdin);
	}
	while (tmp < 0)
	{
		printf("Процент не может быть отрицательным, повторите ввод\n");

		while (!scanf("%f", &tmp))
		{
			printf("Неверный формат ввода, повторите попытку\n");
			rewind(stdin);
		}
	}
	if (*number_of_products == 1)
	{
		Base_of_products = (storage*)realloc(Base_of_products, sizeof(storage) * (*number_of_products)--);
		Base_of_products[0].name = (char*)malloc(sizeof(char));
	}
	else
	{
		int s = 0;
		for (int i = 0;i < *number_of_products;i++)
		{
			if (Base_of_products[i].price == tmp)
			{
				s++;
				for (int j = i;j < *number_of_products - 1;j++)
				{
					Base_of_products[j] = Base_of_products[j + 1];
				}
			}
		}
		(*number_of_products) -= s;
	}
}
void delete_struct(struct storage* Base_of_products, int* number_of_products)
{
	int choose;
	system("CLS");
	if (fl == 0)
	{
		printf("Введите данные в структуру\n");
		return;
	}

	do
	{
		printf("Введите параметр удаления\n1 - по названию\n2 - по цене\n3 - по количеству\n4 - по проценту надбавки\n");
		printf("0 - возврат в меню\n");
		choose = correctInt();

		while (choose < 0 || choose > 4)
		{
			printf("Неверный формат ввода, повторите ввод\n");

			while (!scanf_s("%d", &choose))
			{
				printf("Неверный формат ввода\n");
				rewind(stdin);
			}
		}
		if (choose == 0)
		{
			return;
		}
		void(*delete_struct[4])(storage*, int*);
		delete_struct[0] = delete_name;
		delete_struct[1] = delete_price;
		delete_struct[2] = delete_number;
		delete_struct[3] = delete_percent;
		delete_struct[choose - 1](Base_of_products, number_of_products);
	} while (choose != 0);
}

void coincidence_name(struct storage* Base_of_products, int* number_of_products)
{
	system("CLS");
	char* str;
	int flg = 0, n;
	printf("Искать соответствие с:\n");
	str = (char*)malloc(255 * sizeof(char));

	fgets(str, 255, stdin);

	system("CLS");
	n = strlen(str);
	printf("Найденные товары:\n");
	for (int i = 0; i < *number_of_products; i++)
	{
		if (strncmp(str, Base_of_products[i].name, n - 1) == 0)
		{
			flg = 1;
			printf("%d. Наименование товара: %s", i + 1, Base_of_products[i].name);
			printf("\tЦена %d товара: %.2f", i + 1, Base_of_products[i].price);
			printf("\tКоличество %d товара: %d", i + 1, Base_of_products[i].number);
			printf("\tПроцент надбавки на %d товар: %.2f\n", i + 1, Base_of_products[i].percent_of_allowance);
			printf("\n");
		}
	}
	if (flg == 0)
	{
		printf("Совпадений не найдено\n");
	}
}




void partial_coincidence(struct storage* Base_of_products, int* number_of_products)
{
	int choose;
	do
	{
		printf("Введите параметр совпадения\n1 - по названию\n");
		printf("0 - возврат в меню\n");
		while (!scanf("%d", &choose))
		{
			printf("Неверный формат ввода\n");
			rewind(stdin);
		}
		while (choose < 0 || choose > 1)
		{
			printf("Неверный формат ввода, повторите ввод\n");

			while (!scanf("%d", &choose))
			{
				printf("Неверный формат ввода\n");
				rewind(stdin);
			}
		}
		if (choose == 0)
		{
			return;
		}
		void(*partial_coincidence[4])(storage*, int*);
		partial_coincidence[0] = coincidence_name;
		partial_coincidence[choose - 1](Base_of_products, number_of_products);
	} while (choose != 0);
}

void menu(struct storage* Base_of_products, int* number_of_products)
{
	int choose;
	void (*menu[7])(storage*, int*);
	do
	{
		printf("1 - ввести данные\n2 - вывести данные\n3 - редактировать выбранную структуру\n");
		printf("4 - поиск в товара по параметру\n5 - сортировка\n6 - удаление по параметру\n");
		printf("7 - частичное совпадение\n0 - выход\n");
		choose = correctInt();

		while (choose < 0 || choose > 7)
		{
			printf("Нет такой команды\n");

			while (!scanf("%d", &choose))
			{
				printf("Неверный формат ввода, повторите попытку\n");
				rewind(stdin);
			}
		}
		if (choose == 0)
		{
			return;
		}
		menu[0] = input;
		menu[1] = output;
		menu[2] = edit;
		menu[3] = search_one;
		menu[4] = sort;
		menu[5] = delete_struct;
		menu[6] = partial_coincidence;
		menu[choose - 1](Base_of_products, number_of_products);
	} while (choose!=0);
}
