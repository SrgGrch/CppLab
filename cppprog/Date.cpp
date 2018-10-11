#include "Header.h"
#include <iostream>
#include <conio.h>


int main() {
	Date d1 = Date(28, "Пятница",9, 2018);
	Date d2 = Date(20, "Пятница", 2, 2018);
	Date d3;
	d3 = d2.comp(d1, d2);
	d3.setMounth(4);
	_getch();
} 
