#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Header.h"

#define MATRIX_SIZE 5

struct product {
	int bar;
	char name[50];
	unsigned int price;
	unsigned short sale;
};

struct receipt {
	int bar;
	int lot;
};

struct product search(int bar, struct product matrix[MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		if (bar == matrix[i].bar) return matrix[i];
	}
	struct product  ret = {-1, "NONE", 0, 0};
	return ret;
}

void create_receipt(struct product* matrix, struct receipt* rec, int length) {
	printf("\n\n\n---------================== CHECKOUT RECEIPT ==================---------");
	printf("\nBarcode Name                    Price       Lot    Amount        Sale");
	printf("\n---------======================================================---------\n");
	double total = 0, sale = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			if (rec[i].bar == matrix[j].bar) {
				printf("%d\t%-10.15s\t\t%-5.d RUB * %-2.d   =  %-5.d RUB     %-3.2lf RUB\n", matrix[j].bar, matrix[j].name, matrix[j].price, rec[i].lot, rec[i].lot * matrix[j].price, (float)matrix[j].sale / 100 * rec[i].lot * matrix[j].price);
				total += matrix[j].price * rec[i].lot * (1 - ((float)matrix[j].sale) / 100);
				sale += matrix[j].price * rec[i].lot * ((float)matrix[j].sale) / 100;
				break;
			}
		}
	}
	printf("\n---------======================================================---------\n");
	printf("Summary cost w/o sale: %.2lf RUB\nSale: %.2lf RUB\n\nTOTAL COST: %.2lf RUB\n\n\n", total + sale, sale, total);

}


int add_to_receipt(int bar, struct receipt* rec, int length) {
	for (int i = 0; i < length; i++) {
		if (bar == rec[i].bar) {
			rec[i].lot++;
			return length;
		}
	}
	struct receipt* ptr;
	length++;
	do ptr = (receipt*)realloc(rec, length * sizeof(receipt)); while (ptr == 0);
	rec = ptr;
	rec[length-1].bar = bar;
	rec[length-1].lot = 1;
	return length;
}


int main() {
	setlocale(LC_CTYPE, "RU");
	struct product matrix[MATRIX_SIZE] = {
		1000, "Чай", 100, 5,
		1001, "Кофе", 200, 5,
		1002, "Печенье Мария", 300, 15,
		1003, "Конфеты Буревестник", 700, 20,
		1004, "Сахар", 100, 50
	};
	int bar;
	struct product cur{};
	struct receipt* rec{};
	rec = (receipt*)malloc(2*sizeof(receipt));
	int length = 1;
	while (true) {
		printf("\nScan the bar: ");
		scanf_s("%d", &bar);
		if (bar == -1) {
			create_receipt(matrix, rec, length);
			break;
		}
		cur = search(bar, matrix);
		if (cur.bar == -1) {
			printf("Barcode %d is undefined", bar);
			continue;
		}
		else {
			printf("%-8.d%-10.15s\t\t%-5.d RUB * 1    = %-5.dRUB\t\t%d\%", cur.bar, cur.name, cur.price, cur.price, cur.sale);
			length = add_to_receipt(bar, rec, length);
		}
	}
}