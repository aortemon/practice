#define _CRT_SECURE_NO_WARNINGS 

#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <istream>
#include <Windows.h>
#include <locale.h>
using namespace std;


int main() {
	setlocale(LC_CTYPE, "Rus");
	char name[250];
	string s;
	cout << "enter the name of the file \n";
	cin.getline(name, 250);
	FILE* f;
	f = fopen(name, "r");
	int size;
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	//fseek(f, 0, SEEK_SET);
	char buf(size);

	while (!feof(f)) {
		fread(&buf, sizeof(buf), 1, f);
		if (isalpha(buf)) cout << " " << buf << "\n";
	}
	system("pause");
	return 0;
}