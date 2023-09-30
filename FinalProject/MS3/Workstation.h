// Name: Saetbyeol Lim
// Seneca Student ID: 149814212
// Seneca email: slim62@myseneca.ca
// Date of completion: 27th Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#define _CRT_SECURE_NO_WARNINGS

#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {

	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {

		std::deque<CustomerOrder> m_orders; //double ended queue
		Workstation* m_pNextStation{ nullptr };

	public:
		Workstation(const std::string& str);
		~Workstation();
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		//the object cannot be copied or moved
		Workstation(const Workstation& src) = delete;
		Workstation(Workstation&& src) = delete;
		Workstation& operator=(const Workstation& src) = delete;
		Workstation& operator=(Workstation&& src) = delete;
	};
}

#endif
