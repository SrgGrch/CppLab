#include "Header.h"
#include <iostream>
#include <conio.h>

int yearDay(Date date)
{
	int d = 0;
	for (int i = 0; i < date.date.mounth - 1; i++) d += date.mDays[i];
	d += date.date.day;
	if ((date.date.year % 4 == 0) && (date.date.year % 400 != 0) && (date.date.year % 100 == 0)) d++;
	return d;
}

int main() {
	Date d1 = Date(30, "Пятница",9, 2018);
	Date d2 = Date(12, "Пятница", 10, 2018);
	Date d3;
	d3 = d2.comp(d1, d2);
	d3.setMounth(4);
	++d3;
	std::cout << yearDay(d2);
	_getch();
} 
