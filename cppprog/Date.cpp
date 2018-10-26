#include "Header.h"
#include <iostream>
#include <conio.h>

//using namespace std;

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay;

	return out;
}

std::ofstream & operator<<(std::ofstream &f, Date &date)
{	
	f << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay;
	
	return f;
}

std::ifstream & operator>>(std::ifstream &f, Date &date)
{
	char c;
	f >> date.date.day;
	f >> date.date.day;
	f >> c;
	f >> date.date.mounth;
	f >> date.date.mounth;
	f >> c;
	f >> date.date.year;
	f >> date.date.year;
	f >> date.date.year;
	f >> date.date.year;
	f >> date.date.weekDay;
	return f;
}

int main() {
	Date d1 = Date(30, "Friday",9, 2018);
	Date d2 = Date(20, "Friday", 9, 2017);
	Date d3;
	Date d4;
	d3 = d2.comp(d1, d2);
	d3.setMounth(4);
	++d3;
	//std::cout << d1;

	std::ofstream o;
	std::ifstream i;

	i.open("i.txt", std::ios::binary);
	i >> d3;
	i.close();
	o.open("w.txt", std::ios::binary);
	o.write(reinterpret_cast<char*>(&d3), sizeof(d3));
	o.close();
	i.open("w.txt", std::ios::binary);
	i >> d4;
	i.close();
	std::cout << d4 << std::endl;
	std::cout << d3 << std::endl;
	//std::cout << d1-d2;
	_getch();
} 
