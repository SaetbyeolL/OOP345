//**********************************************************************
//Workshop : #3 (P2)
//File     : Dictionary.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 2/10/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************

#include <iomanip>
#include "Dictionary.h"

using namespace std;  

namespace sdds {

    ostream& Dictionary::display(ostream& os) const {
        os << setw(20) << right << m_term << ": " << m_definition;
        return os;
    }

    bool Dictionary::operator==(const Dictionary other) const {
        return m_term == other.m_term && m_definition == other.m_definition;
    }

    ostream& operator<<(ostream& os, const Dictionary d) {
        return d.display(os);
    }

}
