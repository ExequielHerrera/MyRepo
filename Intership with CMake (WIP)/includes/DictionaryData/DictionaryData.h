#ifndef DICTIONARYDATA_H
#define DICTIONARYDATA_H
#include <string>
#include <iostream>

using namespace std;

//Class that stores the information of the dictionary data

class DictionaryData
{
    public:
        DictionaryData();
        DictionaryData(string k,string d);
        virtual ~DictionaryData();

        string getKey() const;
        string getData() const;

        void setKey(string k);
        void setData(string d);

        void incrementKey(char k);
        void incrementData(char d);

        void printData() const;
        void resetValues();

        static const string MAIN_UNIT;

    protected:

    private:
        string key;
        string data;
};

#endif // DICTIONARYDATA_H
