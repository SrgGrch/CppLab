#pragma once
#include <string>
class Date
{
	friend int yearDay(Date date);
	struct DateS {
		int day;
		std::string weekDay;
		int mounth;
		int year;

		DateS(int _day, std::string _weekDay, int _mounth, int _year) :
			day(_day),
			weekDay(_weekDay),
			mounth(_mounth),
			year(_year)
		{};

		DateS() {};
	};
private:
	DateS date;
	int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	Date(int _day, std::string _weekDay, int _mounth, int _year);
	Date();
	~Date();

	Date comp(Date date1, Date date2);
	int dateToDays();
	int getDay();
	int getMounth();
	int getYear();
	std::string getWeekDay();
	void setDay(int d);
	void setMounth(int m);
	void setYear(int y);
	void setWeekDay(std::string s);
	void nextDay();

	Date& operator++();       // Prefix increment operator.  
	Date operator++(int);     // Postfix increment operator.  
	int operator - (Date d); // кол-во дней между двумя датами

	operator int();
};


Date::Date() {

}

inline int Date::dateToDays()
{
	int days = 0;
	days = date.day;
	for (int i = 0; i < date.mounth-1; i++) {
		days += mDays[i];
	}
	days += date.year * 365 + date.year / 4 - date.year / 100 + date.year / 400;
	return days;
}

Date::Date(int _day, std::string _weekDay, int _mounth, int _year)
{
	date = DateS(_day, _weekDay, _mounth, _year);

}

Date::~Date()
{
}

Date Date::comp(Date date1, Date date2)
{

	if (date1.dateToDays() < date2.dateToDays()) return date2;
	return date1;
}

inline int Date::getDay()
{
	return date.day;
}

inline int Date::getMounth()
{
	return date.mounth;
}

inline int Date::getYear()
{
	return date.year;
}

inline std::string Date::getWeekDay()
{
	return date.weekDay;
}

inline void Date::setDay(int d)
{
	date.day = d;
}

inline void Date::setMounth(int m)
{
	date.mounth = m;
}

inline void Date::setYear(int y)
{
	date.year = y;
}

inline void Date::setWeekDay(std::string s)
{
	date.weekDay = s;
}

inline void Date::nextDay()
{
	if (date.day + 1 <= mDays[date.mounth]) date.day++;
	else if (date.mounth < 12) { date.day = 1; date.mounth++; }
	else { date.day = 1; date.mounth = 1; date.year++; }
}

inline Date & Date::operator++()
{
	if (date.day + 1 <= mDays[date.mounth-1]) date.day++;
	else if (date.mounth < 12) { date.day = 1; date.mounth++; }
	else { date.day = 1; date.mounth = 1; date.year++; }
	return *this;
}

inline Date Date::operator++(int)
{
	Date temp = *this;
	++*this;
	return temp;
}

inline int Date::operator-(Date d)
{
	return dateToDays() - d.dateToDays() > 0? dateToDays() - d.dateToDays(): d.dateToDays() - dateToDays();
}

inline Date::operator int()
{
	return dateToDays();
}


