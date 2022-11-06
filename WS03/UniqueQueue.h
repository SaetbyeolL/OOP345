//**********************************************************************
//Workshop : #3 (P2)
//File     : UniqueQueue.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 2/10/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include<cmath>
#include "Queue.h"

namespace sdds {

	template <typename T>
	class UniqueQueue : public Queue<T, 100> {
	public:
		bool push(const T& item) {
			for (size_t i = 0; i < Queue<T, 100>::size(); i++) {
				if (Queue<T, 100>::operator[](i) == item) {
					return false;
				}
			}
			return Queue<T, 100>::push(item);
		}
	};

	template<>
	bool UniqueQueue<double>::push(const double& item) {
		for (size_t i = 0; i < Queue<double, 100>::size(); i++) {
			if (std::fabs(Queue<double, 100>::operator[](i) - item) <= 0.005) {
				return false;
			}
		}
		return Queue<double, 100>::push(item);
	}

}

#endif