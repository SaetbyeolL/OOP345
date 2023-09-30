// Name: Saetbyeol Lim
// Seneca Student ID: 149814212
// Seneca email: slim62@myseneca.ca
// Date of completion: 19th Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

	class Station {
		int m_stationID{};
		std::string m_itemName{};
		std::string m_stationDes{};
		size_t m_nextSN{};
		size_t m_numOfStockItem{};

		static size_t m_widthField;// class variable
		static size_t id_generator;// class variable

	public:

		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}

#endif