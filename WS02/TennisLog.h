#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <iomanip>
//앞으론 namespace std;는 헤더파일에서 선언하지 않는다


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

