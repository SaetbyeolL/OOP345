#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
	public: 
		SpellChecker(const char* filename);

	};

}

#endif

