#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <iomanip>
//������ namespace std;�� ������Ͽ��� �������� �ʴ´�


namespace sdds{
	class TennisLog {//manages a collection of matches


	};

	class TennisMatch{//contains data about a single match between two players
		//std::string m_tID{};
		char* m_tournamentID{ nullptr };
		char* m_tournamentName{ nullptr };
		unsigned int m_matchID{};//unsigned int = size_t
		char* m_winner{ nullptr };
		char* m_loser{ nullptr };
		void operator<<(const classMatch& obj1, classMatch& obj2);

	};


}

#endif

