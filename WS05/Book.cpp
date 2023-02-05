#include "Book.h"

using namespace std;
std::string m_author{};
std::string m_title{};
std::string m_countryOfPub{};
size_t m_yearOfPub{};
double m_price{};
std::string m_des{};
sdds::Book::Book(const std::string& strBook) {

}
const std::string& sdds::Book::title() const {
	return m_title;
}
const std::string& sdds::Book::country() const {
	return m_countryOfPub;
}
const size_t& sdds::Book::year() const {
	return m_yearOfPub;
}
double& sdds::Book::price() {
	return m_price;
}

std::ostream& sdds::operator<<(std::ostream& os, const Book& book) {
	
}
