//**********************************************************************
//Workshop : #4 (P2)
//File     : Restaurant.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include "Restaurant.h"

using namespace std;

namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		m_size = cnt;
		m_res = new Reservation * [m_size];
		for (size_t i = 0; i < m_size; i++) {
			m_res[i] = new Reservation(*(reservations[i]));
		}
	}
	size_t Restaurant::size() const {
		return m_size;
	}
	Restaurant::Restaurant(const Restaurant& I) {
		*this = I;
	}
	Restaurant& Restaurant::operator=(const Restaurant& other){
		if (this!= &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_res[i];
			}
			delete[] m_res;
			m_size = other.m_size;
			m_res = new Reservation * [m_size];
			for (size_t i = 0; i < m_size; i++) {
				m_res[i] = new Reservation(*(other.m_res[i]));
			}
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_res[i];
			}
			delete[] m_res;
			m_res = other.m_res;
			other.m_res = nullptr;
			m_size = other.m_size;
			other.m_size = 0;
			
		}
		return *this;
	}
	Restaurant::~Restaurant() {
		for (size_t i = 0; i < m_size; i++) {
			delete m_res[i];
		}
		delete[] m_res;
	}
	Restaurant::Restaurant(Restaurant&& I) noexcept {
		*this = move(I);
	}
	std::ostream& operator <<(std::ostream& os, const Restaurant& res) {
		static size_t num = 0;
		num++;

		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << num << ")" << endl;
		os << "--------------------------" << endl;

		if (res.size() > 0) {
			for (size_t i = 0; i < res.size(); i++) {
				os << *(res.m_res[i]);
			}
		}
		else {
			os << "This restaurant is empty!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}

}
