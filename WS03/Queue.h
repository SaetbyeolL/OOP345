//**********************************************************************
//Workshop : #3 (P2)
//File     : Queue.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 2/10/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iomanip>
#include<iostream>
#include "Dictionary.h"

namespace sdds {

	template <typename T, size_t CAPACITY>
	class Queue {
		T m_queue[CAPACITY]{};
		size_t m_count{};
		static T notInQueue;
	public:
		virtual bool push(const T& item) {
			bool result = false;
			if (m_count < CAPACITY) {
				m_queue[m_count] = item;
				m_count++;
				result = true;
			}
			return result;
		}
		virtual ~Queue() {}
		T pop() {
			T removedObject{};
			if (m_count > 0) {
				removedObject = m_queue[0];
				for (size_t i = 1; i < m_count; i++) {
					m_queue[i - 1] = m_queue[i]; 
				}
				m_count--;
			}
			return removedObject;
		}
		size_t size() const {
			return m_count;
		}
		std::ostream& display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (size_t i = 0; i < m_count; i++) {
				os << m_queue[i] << std::endl;
			}
			os << "----------------------" << std::endl;
			return os;
		}
		T operator[](size_t index) const {
			if (index < m_count && index >= 0) {

				return m_queue[index];
			}
			else {
				return notInQueue;
			}
		}
	};

	template<typename T, size_t CAPACITY>
	T Queue<T, CAPACITY>::notInQueue{};
	template<>
	Dictionary Queue<Dictionary, 100u>::notInQueue{
		"Empty Term", "Empty Substitute" };

}
#endif