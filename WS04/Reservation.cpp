//**********************************************************************
//Workshop : #4 (P2)
//File     : Reservation.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include "Reservation.h"
#include <string>
#include <iostream>

using namespace std;

namespace sdds {

	Reservation::Reservation() {
	};

	void Reservation::update(int day, int time) {
		m_day = day;
		m_hour = time;
	}

	Reservation::Reservation(const std::string& res) {
		std::string temp = res;
		size_t startPos = 0;
		size_t endPosID = temp.find(':');
		size_t endPos = 0;

		//ID delimiter
		string id = temp.substr(startPos, endPosID);
		id = trim(id);
		temp.erase(startPos, endPosID + 1);

		//name delimiter
		endPos = temp.find(',');
		string name = temp.substr(startPos, endPos);
		name = trim(name);
		temp.erase(startPos, endPos + 1);

		//email delimiter
		endPos = temp.find(',');
		string email = temp.substr(startPos, endPos);
		email = trim(email);
		temp.erase(startPos, endPos + 1);


		//number of people delimiter// string to int
		endPos = temp.find(',');
		size_t people = std::stoi(temp);
		temp.erase(startPos, endPos + 1);

		// day of reservation delimiter
		endPos = temp.find(',');
		size_t day = std::stoi(temp);
		temp.erase(startPos, endPos + 1);

		// time of reservation delimiter
		size_t time = std::stoi(temp);

		m_resId = id;
		m_resName = name;
		m_email = email;
		m_numOfpeople = people;
		m_day = day;
		m_hour = time;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res) {
		int HOUR = res.m_hour;

		os << "Reservation " << std::setw(10) << std::right << res.m_resId << ": " << std::setw(20) << std::right << res.m_resName << "  " << std::setw(20) << std::left << "<" + res.m_email + ">" << "    ";
		
		if (HOUR >= 6 && HOUR <= 9)
			os << "Breakfast on day " << res.m_day << " @ " << HOUR << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		else if (HOUR >= 11 && HOUR <= 15)
			os << "Lunch on day " << res.m_day << " @ " << HOUR << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		else if (HOUR >= 17 && HOUR <= 21)
			os << "Dinner on day " << res.m_day << " @ " << HOUR << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		else
			os << "Drinks on day " << res.m_day << " @ " << HOUR << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		return os;
	}

	std::string trim(std::string& str) {
		size_t start = str.find_first_not_of(' ');
		size_t end = str.find_last_not_of(' ');
		return str.substr(start, end - start + 1);
	}

}