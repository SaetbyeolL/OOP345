#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>

namespace sdds {
	
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_countryOfPub{};
		size_t m_yearOfPub{};
		double m_price{};
		std::string m_des{};
		
	public: 
		Book() {};
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};


}

#endif