//**********************************************************************
//Workshop : #4 (P2)
//File     : Restaurant.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Reservation.h"

namespace sdds {
	class Restaurant {

		size_t m_size{};
		Reservation** m_res{};

	public:
		size_t size() const;
		Restaurant() {}
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& I);
		Restaurant& operator=(const Restaurant& other);
		Restaurant(Restaurant&& I) noexcept;
		Restaurant& operator=(Restaurant&& other) noexcept;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
	};
}

#endif