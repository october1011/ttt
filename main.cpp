#include <iostream>
#include <Windows.h>
#include <algorithm>

#include "data.h"
#include "io.h"
#include "helpfunction.h"
#include "ciklegame.h"


int main() {

	setlocale(LC_ALL, "ru");

	
	
	PLAYER c{};
	Field field;
	
	init(field);
	print(field);
	human(field);
	print(field);
	
	
	ai(field);
	print(field);
	human(field);
	print(field);
	ai(field);
	print(field);
	human(field);
	print(field);
	ai(field);
	print(field);

	winchk(field, c); // первый косяк точно в этой функции,потому что не выдает победителя 
	std::cout << " Функция отработала\n";

	isdraw(field);

	return 0;
}