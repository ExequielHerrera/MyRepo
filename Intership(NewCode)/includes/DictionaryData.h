#pragma once

#include <string>
#include <iostream>


//Class that stores the information of the dictionary data

using namespace std;
class DictionaryData
{
    public:
        DictionaryData();
        DictionaryData(string k,string d);
        ~DictionaryData();

        string getKey() const;
        string getData() const;

        void setKey(string &k);
        void setData(string &d);

        void incrementKey(char &k);
        void incrementData(char &d);

        void printData() const;
        void resetValues();

        static const string MAIN_UNIT;


    private:
        string key;
        string data;
};


