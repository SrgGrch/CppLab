	#include "Header.h"
	#include <iostream>
	#include <conio.h>


	int main() {
		Date d1 = Date(28, "Пятница",9, 2018);
		Date d2 = Date(20, "Пятница", 2, 2018);
		d2.setDay(30);
		if (d2.getMounth() == 2) d2.setDay(9);
		Date d3 = d2.comp(d1, d2);
		int days = d2.dateToDays();
		std::cout << d3.getDay() << '.' << d3.getMounth() << '.' << d3.getYear();
		_getch();
	} 
