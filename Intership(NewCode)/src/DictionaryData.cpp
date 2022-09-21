#include "DictionaryData.h"

const string DictionaryData::MAIN_UNIT= "";

DictionaryData::DictionaryData()
{
    resetValues();
}

DictionaryData::DictionaryData(string k,string d)
{
    key=k;
    data=d;
}

DictionaryData::~DictionaryData()
{

}

string DictionaryData::getKey() const{
    return key;
}

string DictionaryData::getData() const{
    return data;
}

void DictionaryData::setKey(string& k){
    key=k;
}

void DictionaryData::setData(string& d){
    data=d;
}

void DictionaryData::incrementKey(char& k){
    key = key + k;
}

void DictionaryData::incrementData(char& d){
    data = data + d;
}

void DictionaryData::resetValues(){
    key="";
    data="";
}

void DictionaryData::printData() const{
    cout<<key<<" = "<<data<<endl;
}
