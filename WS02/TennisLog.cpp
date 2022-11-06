//**********************************************************************
//Workshop : #2 (P1)
//File     : TennisLog.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 24/Sep/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include "TennisLog.h"
#include<fstream>
#include<iomanip>

using namespace std;

namespace sdds {
	TennisMatch empty;

	std::ostream& operator<<(std::ostream& os, const TennisMatch& obj) {
		if (obj.m_tournamentID == "") {
			os << "Empty Match";
		}
		else {
			os << setw(20) << right << setfill('.') << "Tourney ID" << " : " << setw(30) << left << obj.m_tournamentID << endl;
			os << setw(20) << right << "Match ID" << " : " << setw(30) << left << obj.m_matchID << endl;
			os << setw(20) << right << "Tourney" << " : " << setw(30) << left << obj.m_tournamentName << endl;
			os << setw(20) << right << "Winner" << " : " << setw(30) << left << obj.m_winner << endl;
			os << setw(20) << right << "Loser" << " : " << setw(30) << left << obj.m_loser << endl;
			os << setfill(' ');
		}
		return os;
	}

	TennisLog::TennisLog(const char* filename) {
		ifstream is(filename);
		string temp;
		size_t lineCount = 0;
		getline(is, temp);
		while (is) {
			getline(is, temp);
			if (is) lineCount++;
		}
		m_count = lineCount;
		m_collection = new TennisMatch[m_count];
		is.clear();
		is.seekg(0);
		getline(is, temp);

		for(size_t i=0;i<m_count;i++){
			getline(is, m_collection[i].m_tournamentID, ',');
			getline(is, m_collection[i].m_tournamentName, ',');
			is >> m_collection[i].m_matchID;
			is.ignore();
			getline(is, m_collection[i].m_winner, ',');
			getline(is, m_collection[i].m_loser);
		}
	}

	void TennisLog::addMatch(const TennisMatch& obj) {
		TennisMatch* temp = m_collection;
		m_collection = new TennisMatch[++m_count];
		for (size_t i = 0; i < m_count - 1; i++){
			m_collection[i] = temp[i];
		}
		m_collection[m_count - 1] = obj;
		delete[] temp;
	}


	TennisLog TennisLog::findMatches(std::string player) const {
		TennisLog found;

		for (size_t i = 0; i < m_count; i++) {
			if (m_collection[i].m_winner ==player || m_collection[i].m_loser == player) {
				found.addMatch(m_collection[i]);
			}
		}
		return found;
	}

	TennisMatch& TennisLog::operator[](size_t index) const {
		
		if (m_count > 0) {
			return m_collection[index % m_count];
		}
		else {
			return empty;
		}
	}

	TennisLog::operator size_t() const{
		return m_count;
	}

	//rule of 3
	TennisLog::~TennisLog() {
		delete[] m_collection;
	}

	TennisLog::TennisLog(const TennisLog& I) {
		*this = I;
	}

	TennisLog& TennisLog::operator=(const TennisLog& other) {
		if (this != &other) {
			delete[] m_collection;
			m_count = other.m_count;
			m_collection = new TennisMatch[m_count];
			for (size_t i = 0; i < m_count; i++)
			{
				m_collection[i] = other.m_collection[i];
			}
		}
		return *this;
	}

	/// ////////part 2
	TennisLog::TennisLog(TennisLog&& I) noexcept {
		*this = std::move(I);
	}
	TennisLog& TennisLog::operator=(TennisLog&& other) noexcept {
		if (this != &other) {
			delete[] m_collection;
			m_count = other.m_count;
			m_collection = other.m_collection;
			other.m_collection = nullptr;
			other.m_count = 0;
		}
		return *this;
	}

}