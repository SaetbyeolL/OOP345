// Name: Saetbyeol Lim
// Seneca Student ID: 149814212
// Seneca email: slim62@myseneca.ca
// Date of completion: 26th Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<iomanip>
#include <vector>
#include <utility>
#include <iomanip>
#include"Station.h"
#include "Utilities.h"

namespace sdds {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name{}; 
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{ nullptr };
		static size_t m_widthField; //class variable
	public:
		CustomerOrder();
		CustomerOrder(const std::string& token); 
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};


}
#endif
