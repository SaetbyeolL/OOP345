//**********************************************************************
//Workshop : #2 (P1)
//File     : TennisLog.h
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 24/Sep/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>

namespace sdds{

	struct TennisMatch{//contains data about a single match between two players
		
		std::string m_tournamentID{};
	    std::string m_tournamentName{};
		size_t m_matchID{};
	    std::string m_winner{};
	    std::string m_loser{};
	};
	std::ostream& operator<<(std::ostream& os, const TennisMatch& obj);

	class TennisLog {//manages a collection of matches and keep a count of how many are being store. 
		TennisMatch* m_collection{};
		size_t m_count{};
	public:
		TennisLog() {};
		TennisLog(const char* filename);
		void addMatch(const TennisMatch& obj);
		TennisLog findMatches(std::string player) const;
		TennisMatch& operator[](size_t) const;
		operator size_t()const;
		//rule of 5
		~TennisLog();
		TennisLog(const TennisLog& I);
		TennisLog& operator=(const TennisLog& other);
		TennisLog(TennisLog&& I) noexcept;
		TennisLog& operator=(TennisLog&& other) noexcept;
	};
}

#endif

