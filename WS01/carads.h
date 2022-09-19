//**********************************************************************
//Workshop : #1 (P1)
//File     : carads.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 18/9/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>
#include <iomanip>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	void listArgs(int argc, char* argv[]);

	class Cars {
		char* m_brand{ nullptr }; 
		char m_model[15]{};
		int m_year{};
		double m_price{};
		char m_used{};
		bool m_flagDiscount{}; // a boolean flag indicating whether or not the car is on promotion discount

	public: 
		Cars();
		~Cars();
		Cars(const Cars& I);
		Cars& operator=(const Cars& other);
		std::istream& read(std::istream& is); 
		void display(bool reset) const;
		char getStatus() const;//a query that returns if the car is new or used.
		operator bool () const;
	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}



#endif