//**********************************************************************
//Workshop : #4 (P2)
//File     : ConfirmationSender.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 9/Oct/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
//**********************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "ConfirmationSender.h"
using namespace std;

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& I) {
		*this = I;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& I) noexcept {
		*this = move(I);
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] m_res;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
		if (this != &other) {
			delete[] m_res;
			m_size = other.m_size;
			m_res = new const Reservation * [m_size];
			for (size_t i = 0; i < m_size; i++)
			{
				m_res[i] = other.m_res[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
		if (this != &other) {
			delete[] m_res;
			m_size = other.m_size;
			other.m_size = 0;
			m_res = other.m_res;
			other.m_res = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool exist = false;
		
		if (m_size > 0) {
			
			for (size_t i = 0; i < m_size ; i++)
			{
				if (m_res[i] == &res) {
					exist = true;
				}
			}
			if (!exist) {
				const Reservation** temp = m_res;
				m_res = new const Reservation * [m_size + 1];
				for (size_t i = 0; i < m_size; i++)
				{
					m_res[i] = temp[i];
				}
				m_res[m_size] = &res;
				m_size++;
				delete[] temp;
			}
		}
		else {
			m_res = new const Reservation * [1];
			m_res[0] = &res;
			m_size++;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		int exist = -1;
		int index = 0;
		if (m_size > 0) {
			for (size_t i = 0; i < m_size && exist==-1; i++)
			{
				if (m_res[i] == &res) {
					exist = i;
				}
			}
			if (exist != -1) {
				const Reservation** temp = m_res;
				m_res = new const Reservation * [m_size - 1];
				for (int i = 0; i < (int)m_size - 1; i++, index++)
				{
					if (index == exist) {
						index++;
					}
					m_res[i] = temp[index];
				}
				m_size--;
				delete[] temp;
			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirm) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (confirm.m_size > 0) {
			for (size_t i = 0; i < confirm.m_size; i++)
			{
				os << *(confirm.m_res[i]);
			}
		}
		else {
			os << "There are no confirmations to send!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}

