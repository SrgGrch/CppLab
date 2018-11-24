#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Date
{
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
	//DateS date;
	DateS date;
private:

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

	virtual void binWrite(std::string name);
	virtual void binRead(std::string name);

	friend std::ostream& operator<<(std::ostream &out, const Date &date);
	friend std::ofstream& operator<<(std::ofstream &f, Date & date);
	friend std::ifstream& operator>>(std::ifstream &f, Date & date);
	Date& operator++();       // Prefix increment operator.  
	Date operator++(int);     // Postfix increment operator.  
	int operator-(Date d); // кол-во дней между двумя датами

	operator int();
};


Date::Date() {
}

inline int Date::dateToDays()
{
	int days = 0;
	days = date.day;
	for (int i = 0; i < date.mounth - 1; i++) {
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

inline void Date::binWrite(std::string name)
{
	if (name.find(".bin") == std::string::npos) throw 1;
	else {
		std::ofstream o;
		o.open(name, std::ios::binary);
		o.write((char*)&(this->date), sizeof(this->date));
		o.close();
	}
}

inline void Date::binRead(std::string name)
{
	if (name.find(".bin") == std::string::npos) throw 1;
	else {
		std::ifstream i;
		i.open(name, std::ios::binary);
		i.read((char*)&(this->date), sizeof(this->date));
		i.close();
	}
}

inline Date & Date::operator++()
{
	if (date.day + 1 <= mDays[date.mounth - 1]) date.day++;
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
	return dateToDays() - d.dateToDays() > 0 ? dateToDays() - d.dateToDays() : d.dateToDays() - dateToDays();
}

inline Date::operator int()
{
	return dateToDays();
}

class DateEvent : public Date
{
	struct DateE {
		int day;
		std::string weekDay;
		int mounth;
		int year;
		std::string event;

		DateE(int _day, std::string _weekDay, int _mounth, int _year, std::string _event) :
			day(_day),
			weekDay(_weekDay),
			mounth(_mounth),
			year(_year),
			event(_event)
		{};

		DateE() {};
	};
public:
	DateEvent() : Date() {}
	DateEvent(int _day, std::string _weekDay, int _mounth, int _year, std::string _event) : Date(_day, _weekDay, _mounth, _year), event(_event) {}
	DateEvent(int _day, int _mounth, int _year) : Date(_day, "sd", _mounth, _year), event("asdas") {}

	std::string getEvent();
	void setEvent(std::string _event);
	void binWrite(std::string name) {
		DateE d = DateE(this->getDay(), this->getWeekDay(), this->getMounth(), this->getYear(), event);
		std::ofstream o;
		o.open(name, std::ios::binary);
		o.write((char*)&(d), sizeof(d));
		o.close();
	};

	void binRead(std::string name) {
		std::ifstream i;
		DateE d;
		i.open(name, std::ios::binary);
		i.read((char*)&(d), sizeof(d));
		i.close();
		*this = DateEvent(d.day, d.mounth, d.year);
	};

private:
	std::string event;
};

std::string DateEvent::getEvent()
{
	return event;
}

void DateEvent::setEvent(std::string _event)
{
	event = _event;
}

