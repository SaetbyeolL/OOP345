//**********************************************************************
//Workshop : #7 (P2)
//File     : CrimeStatistics.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 11/11/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef CRIMESTATISTICS_H
#define CRIMESTATISTICS_H
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include<list>

namespace sdds {
	struct Crime {
		std::string m_province{};
		std::string m_district{};
		std::string m_crime{};
		size_t m_numOfCase{};
		size_t m_year{};
		size_t m_resolved{};
	};
	class CrimeStatistics {

		std::vector<Crime> m_crimeCollection;

	public: 
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const;
		void sort(std::string fieldName);
		void cleanList();
		bool inCollection(const std::string& crime) const;
		std::list<Crime> getListForProvince(const std::string& province) const;


	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif

