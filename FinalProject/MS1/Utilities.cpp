// Name: Saetbyeol Lim
// Seneca Student ID: 149814212
// Seneca email: slim62@myseneca.ca
// Date of completion: 19th Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
using namespace std;

namespace sdds {

	char Utilities::m_delimiter{}; // static variable initialization


	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {

		return m_widthField;
	}

	void trim(string& string) { //helper function
		if (string.length() > 0) {
			size_t begin = string.find_first_not_of(' ');
			size_t end = string.find_last_not_of(' ');
			if (begin < 0) {
				string = "";
			}
			else {
				string = string.substr(begin, end - begin + 1);
			}
		}
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		int nextTokenPos;
		string token;
		string string = str.substr(next_pos);


		if (str[next_pos] == m_delimiter || next_pos >= str.length()) {
			more = false;
			throw invalid_argument("Delimiter is found!");
		}
		else {
			if ((nextTokenPos = string.find_first_of(m_delimiter)) != -1) {

				token = string.substr(0, nextTokenPos);
				trim(token);
				next_pos += (nextTokenPos + 1);
				more = true;
			}
			else {
				token = string;
				trim(token);
				more = false;
			}
		}

		if (m_widthField < token.length()) {
			setFieldWidth(token.length());
		}

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {

		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {

		return m_delimiter;
	}


}