//**********************************************************************
//Workshop : #2 (P2)
//File     : Timer.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 24/Sep/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
#include <string>
  
const unsigned int maxNumofEvents = 10;

namespace sdds {
	class Timer {
		
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;

	public:
		void start();
		long long stop();
	};
}

#endif