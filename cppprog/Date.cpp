#include "Date.h"
#include <iostream>
#include <conio.h>
//#include "PlaneEvent.h"

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay;
	return out;
}

std::ofstream & operator<<(std::ofstream &f, Date &date)
{	
	f << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay << std::endl;
	
	return f;
}

std::ifstream & operator>>(std::ifstream &f, Date &date)
{
	char c;
	f >> date.date.day;
	f >> c;
	f >> date.date.mounth;
	f >> c;
	f >> date.date.year;
	f >> c;
	f >> date.date.weekDay; 
	return f;
}

int main() {
	Date d = Date(12, "sadasd", 3, 1234);

	try {
		d.binWrite("i");
	}
	catch (int a) {
		std::cout << "¬веден файл с неверным расширением, надо использовать bin";
	}

	//std::cout << n.getEvent();
	_getch();
} 
