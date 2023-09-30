//**********************************************************************
//Workshop : #2 (P2)
//File     : Timer.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 24/Sep/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include <iostream>
#include <iomanip>
#include "Timer.h"
  
namespace sdds {
	
	void Timer::start() {
		m_startTime = std::chrono::steady_clock::now();

	}
	long long Timer::stop() {
		m_endTime = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		return duration.count();
	}
	
}