//**********************************************************************
//Workshop : #8 (P2)
//File     : GeneratingList.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 11/20/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		bool luhnAlgorithm(const std::string& numString) const {
			size_t count = 0;
			int temp;

			for (size_t i = 0; i < numString.length(); i++)
			{
				temp = numString[i] - '0';
				if (i % 2 == 1) {

					temp *= 2;
					if (temp >= 10) {
						temp -= 9;
					}
				}
				count += temp;

			}
			return (count % 10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator += (const T* rawPtr) {
			list.push_back(*rawPtr);
		}

		void operator+=(std::unique_ptr<T> smartPtr) { 
			list.push_back(*smartPtr);
		}


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
