//**********************************************************************
//Workshop : #4 (P2)
//File     : ConfirmationSender.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {
		const Reservation** m_res{};
		size_t m_size{};

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& I);
		ConfirmationSender(ConfirmationSender&& I) noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator=(const ConfirmationSender& other);
		ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;
		ConfirmationSender& operator-=(const Reservation& reservation);
		ConfirmationSender& operator+=(const Reservation& reservation);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirm);

	};

}



#endif