// Name: Saetbyeol Lim
// Seneca Student ID: 149814212
// Seneca email: slim62@myseneca.ca
// Date of completion: 27th Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include "Workstation.h"

namespace sdds {

	class LineManager {
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation{};

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif