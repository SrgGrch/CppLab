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
	Date d1 = Date(30, "Friday",9, 2018);
	Date d2 = Date(20, "Friday", 9, 2017);
	Date d3;
	Date d4;
	Date d5;
	PlaneEvent p = PlaneEvent(30, "Friday", 9, 2018, "adasdasd");
	//PlaneEvent n = PlaneEvent(30, "Friday", 9, 2018, "adasdasd");

	p.binWrite("PE.bin");
	//p.binRead("PE.bin");
	std::cout << p.getEvent();
	_getch();
} 
