//**********************************************************************
//Workshop : #4 (P2)
//File     : Reservation.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>

namespace sdds {
	class Reservation {
		std::string m_resId{};
		std::string m_resName{};
		std::string m_email{};
		size_t m_numOfpeople{};
		size_t m_day{};
		size_t m_hour{};

	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
	std::string trim(std::string& str);
}


#endif