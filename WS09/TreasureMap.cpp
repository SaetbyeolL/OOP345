//**********************************************************************
//Workshop : #9 (P2)
//File     : TreasureMap.cpp
//Full Name : Saetbyeol Lim
//Student ID# : 149814212
//Email : slim62@myseneca.ca
//Date : 11/25/2022 
//Comment :
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.

// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"
#include <functional>
#include <thread>
#include <future>

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 00; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            
            std::ofstream of(filename, std::ios::binary);

            if (of) {
                of.write(reinterpret_cast < char* > (&rows), sizeof(size_t));
                of.write(reinterpret_cast<char*>(&colSize), sizeof(size_t));

                for (size_t i = 0; i < rows; i++) {
                    of.write(map[i].c_str(), map[i].size());
                }
            }
            else {
                    throw std::string("Invalid file name!");
            }
            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        // END TODO

        std::ifstream ifs(filename, std::ios::binary);

        ifs.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
        ifs.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));

        map = new std::string[rows];
        char* temp = new char[30];
        for (size_t i = 0; i < rows; i++)
        {
            ifs.read(temp, 30);
            map[i].append(temp, 30);
        }
        delete[] temp;

    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        //size_t count = 0;

        //// TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i){
        //    count += digForTreasure(map[i], mark);
        //}

        //return count;

        std::string string1 = map[0] + map[1] + map[2];
        std::string string2 = map[3] + map[4] + map[5];
        std::string string3 = map[6] + map[7] + map[8];
        std::string string4 = map[9] + map[10] + map[11];

        auto f = bind(digForTreasure, std::placeholders::_1, mark);

        std::packaged_task<size_t(std::string)> task1(f);
        std::packaged_task<size_t(std::string)> task2(f);
        std::packaged_task<size_t(std::string)> task3(f);
        std::packaged_task<size_t(std::string)> task4(f);

        std::future<size_t> future1 = task1.get_future();
        std::future<size_t> future2 = task2.get_future();
        std::future<size_t> future3 = task3.get_future();
        std::future<size_t> future4 = task4.get_future();

        std::thread thread1(std::move(task1), string1);
        std::thread thread2(std::move(task2), string2);
        std::thread thread3(std::move(task3), string3);
        std::thread thread4(std::move(task4), string4);

        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();

        size_t total = future1.get() + future2.get() + future3.get() + future4.get();

        return total;

    }
}