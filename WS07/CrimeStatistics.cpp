//*************//**********************************************************************
//Workshop : #7 (P2)
//File     : CrimeStatistics.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 11/11/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include "CrimeStatistics.h"
using namespace std;

namespace sdds {

	void trim(string& temp) {
		if (temp.length() > 0) {
			int begin = temp.find_first_not_of(' ');
			int end = temp.find_last_not_of(' ');
			if (begin == -1) {
				temp = "";
			}
			else {
				temp = temp.substr(begin, end - begin + 1);
			}
		}
	}
	sdds::CrimeStatistics::CrimeStatistics(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "filename is incorrect";}
		Crime crimeInfo;
		string crimeTemp;
		do {
			getline(file, crimeTemp);
			if (file) {
				crimeInfo.m_province = crimeTemp.substr(0, 25);
				trim(crimeInfo.m_province);

				crimeInfo.m_district = crimeTemp.substr(25, 25);
				trim(crimeInfo.m_district);

				crimeInfo.m_crime = crimeTemp.substr(50, 25);
				trim(crimeInfo.m_crime);

				crimeInfo.m_year = stoi(crimeTemp.substr(75, 5));
				crimeInfo.m_numOfCase = stoi(crimeTemp.substr(80, 5));
				crimeInfo.m_resolved = stoi(crimeTemp.substr(85, 5));

				m_crimeCollection.push_back(crimeInfo);
			}
		} while (file);
		file.close();
	}
	void sdds::CrimeStatistics::display(std::ostream& out) const {
		int totalCases = 0;
		int resolvedCases = 0;

		auto collectionDisplay = [&](Crime crime) {
			totalCases += crime.m_numOfCase;
			resolvedCases += crime.m_resolved;
			out << crime << endl;
		};
		for_each(m_crimeCollection.begin(), m_crimeCollection.end(), collectionDisplay);
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                 Total Crimes: ";
		cout << setw(6) << totalCases << " |" << endl;
		cout << "|                                                         Total Resolved Cases: ";
		cout << setw(6) << resolvedCases << " |" << endl;
	}
	void CrimeStatistics::sort(std::string fieldName) {
		std::sort(m_crimeCollection.begin(), m_crimeCollection.end(), [&](const Crime& c1, const Crime& c2) {
			if (fieldName == "Province")	return c1.m_province < c2.m_province;
			else if (fieldName == "Crime") return c1.m_crime < c2.m_crime;
			else if (fieldName == "Cases") return c1.m_numOfCase < c2.m_numOfCase;
			else if (fieldName == "Resolved") return c1.m_resolved < c2.m_resolved;
			else return c1.m_province < c2.m_province;
			});
	}
	void CrimeStatistics::cleanList() {
		Crime temp;
		replace_if(m_crimeCollection.begin(), m_crimeCollection.end(), [&temp](const Crime& crime) {
			temp = crime;
			temp.m_crime = "";
			return crime.m_crime == "[None]";
			}, temp);
	}
	bool CrimeStatistics::inCollection(const std::string& crime) const{

		return any_of(m_crimeCollection.begin(), m_crimeCollection.end(),
			[&crime](const Crime& c) {return c.m_crime == crime; });
	}
	std::list<Crime> CrimeStatistics::getListForProvince(const std::string& province) const {
		std::list<Crime> listOfCrime(m_crimeCollection.size());
		auto iterator = copy_if(m_crimeCollection.begin(), m_crimeCollection.end(),
			listOfCrime.begin(),[&province](const Crime& crime) {
				return crime.m_province == province;
			});
		int size = std::distance(listOfCrime.begin(), iterator);
		listOfCrime.resize(size); 
		return listOfCrime;
	}
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << setw(21) << left << theCrime.m_province << " | "
			<< setw(15) << left << theCrime.m_district << " | "
			<< setw(20) << left << theCrime.m_crime << " | "
			<< setw(6) << right << theCrime.m_year << " | "
			<< setw(4) << theCrime.m_numOfCase << " | "
			<< setw(3) << theCrime.m_resolved << " |" ;
		return out;
	}
}

