//**********************************************************************
//Workshop : #8 (P2)
//File     : WritingRecord.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 11/20/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		EmployeeWage* rPtr;
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {

				if (emp[i].id == sal[j].id) {
					rPtr = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						rPtr->rangeValidator();
					}
					catch (const string& exception){
						delete rPtr;
						throw exception;
					}

					if (emp.luhnAlgorithm(emp[i].id)) {
						activeEmp += rPtr;
					}
					delete rPtr;
				}
			}
		}
		return activeEmp;

	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		unique_ptr<EmployeeWage> smartPtr;

		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {

				if (emp[i].id == sal[j].id) {
					smartPtr = make_unique<EmployeeWage>(emp[i].name, sal[j].salary);
					smartPtr->rangeValidator();
					if (emp.luhnAlgorithm(emp[i].id)) {
						activeEmp += move(smartPtr);
					}
				}
			}
		}
		return activeEmp;
	}
}
