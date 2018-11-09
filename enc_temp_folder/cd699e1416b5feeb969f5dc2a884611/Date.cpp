#include "Header.h"
#include <iostream>
#include <conio.h>

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay;
	return out;
}

std::ofstream & operator<<(std::ofstream &f, Date &date)
{	
	f << date.date.day << "." << date.date.mounth << "." << date.date.year << " - " << date.date.weekDay;
	//f.write((char*)&(date.date), sizeof(date.date));
	
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
	//f.read((char*)&(date.date), sizeof(date.date));
	return f;
}

int main() {
	Date d1 = Date(30, "Friday",9, 2018);
	Date d2 = Date(20, "Friday", 9, 2017);
	Date d3;
	Date d4;
	
	std::ofstream out;
	out.open("o.txt");

	out << d2;
	out.close();
	std::ifstream inp;
	inp.open("o.txt");
	inp >> d3;
	inp.close();
	std::cout << d3;
/*
	d2.binWrite("o");
	
	d4.binRead("o");	
	
	std::cout << d2 << ' ' << d4;*/
		
	_getch();
} 
