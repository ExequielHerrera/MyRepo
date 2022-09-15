#include <iostream>


#include "includes/JsonAnalizer/JsonAnalizer.h"
#include "includes/DictionaryData/DictionaryData.h"
#include<stdlib.h>
#include<fstream>

//Candidate: Herrera De Rosa, Exequiel.
//Technical questionnaire, GLOBANT Gaming Internship 2022.

using namespace std;

string readFile();



string readFile(){
    ifstream originalCode;

    string exitCode;
    string line;

    originalCode.open("/codes/validCode2",ios::in);

    if(originalCode.fail())
    {
        cout<<"An error occurred trying to open the file."<<endl;
        exit(1);
    }
    while(getline(originalCode,line)){
        exitCode = exitCode + line;
    }
    originalCode.close();
    exitCode = exitCode + "$"; //we include the End of File ($) character to the code.
    return exitCode;

}





int main()
{

    JsonAnalizer j;

    //we read the file.
    //string code = readFile();

    string code = "{\"a\" : true , \"b\" : {\"b1\" : \"hello\" , \"b2\" : 3.5 }  ,  \"c\" : 3}";

    //we set the code
    j.setJsonCode(code);

    //we get the dictionary

    list<DictionaryData> data = j.getDictionary();




    //showing the results

    if (!data.empty())
        cout<<"D i c t i o n a r y   -   R e s u l t s"<<'\n'<<endl;
    list<DictionaryData>::const_iterator Yter=data.begin();
    while (Yter!=data.end())
    {
        Yter->printData();
        Yter++;
    }


  return 0;
}
