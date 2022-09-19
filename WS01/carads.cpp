//**********************************************************************
//Workshop : #1 (P1)
//File     : carads.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 18/9/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

double g_taxrate=0.0;
double g_discount=0.0;

namespace sdds {

	Cars::Cars() {};

	void listArgs(int argc, char* argv[]) {

		cout << "Command Line:" <<endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; i++) {
			cout << setw(3) << setfill(' ') << right << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n" << endl;
	}

	std::istream& Cars::read(std::istream& is) {

		string string;
		char promotion;

		if (is) {
			is >> m_used;
			is.ignore();
			getline(is, string, ',');
			delete[] m_brand;
			m_brand = new char[string.length() + 1];
			strcpy(m_brand, string.c_str());
			is.getline(m_model, 14, ',');
			is >> m_year;
			is.ignore();
			is >> m_price;
			is.ignore();
			is >> promotion;
			if (promotion == 'Y') {
				m_flagDiscount = true;
			}
			else {
				m_flagDiscount = false;
			}
			is.ignore();
		}
		return is;
	}

	void Cars::display(bool reset) const { 

		static int COUNTER = 0;

		if (reset == true) {
			COUNTER = 0;
		}
		COUNTER++;

		if (m_brand[0] != '\0') {
			cout << left << setw(2) << COUNTER << ". " << left << setw(10) << m_brand << "| " << setw(15) << m_model << "| " << m_year << " |" << setw(12) << right << fixed << setprecision(2) << m_price * (1 + g_taxrate) << "|";
			if (m_flagDiscount) {
				cout << setw(12) << right << m_price * (1 - g_discount) * (1 + g_taxrate);
			}
		}
		else {
			cout << setw(2) << left << COUNTER << ". " << "No car";
		}
		cout << endl;
	}

	char Cars::getStatus() const {
		return m_used;
	}


	//part2

	Cars::Cars(const Cars& other) {
		*this = other;
	}
 
	Cars& Cars::operator=(const Cars& other) {
		if (this != &other) {
			delete[] m_brand;
			m_brand = nullptr;
			m_brand = new char[strlen(other.m_brand) + 1];
			strcpy(m_brand, other.m_brand);
			strcpy(m_model, other.m_model);
			m_year = other.m_year;
			m_price = other.m_price;
			m_used = other.m_used;
			m_flagDiscount = other.m_flagDiscount;
		}
		return *this;
	}
		Cars::~Cars() {
			delete[] m_brand;
		}

		std::istream& operator >>(std::istream& is, Cars& car) {
			car.read(is);
			return is;
		}

		Cars::operator bool() const {
			return m_used == 'N';
		}

		void operator >> (const Cars& car1, Cars& car2) {
			car2 = car1;
		}
}







