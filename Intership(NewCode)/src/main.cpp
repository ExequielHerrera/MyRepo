#include <iostream>

#include "../includes/JsonAnalizer.h"
#include "../includes/DictionaryData.h"
#include<stdlib.h>
#include<fstream>







string readFile();



string readFile(string fileName){
    ifstream originalCode;

    string exitCode;
    string line;

    originalCode.open(fileName,ios::in);

    if(originalCode.fail())
    {
        std::cout<<"An error occurred trying to open the file."<<std::endl;
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

    string code = "{\"a\" : true , \"b\" : {\"b1\" : \"hello\" , \"b2\" : 3.5 }  ,  \"c\" : 3} $";

    //we set the code
    j.setJsonCode(code);

    //we get the dictionary

    list<DictionaryData> data = j.getDictionary();












    //showing the results

    if (!data.empty()){
            cout<<"D i c t i o n a r y   -   R e s u l t s"<<'\n'<<endl;
        }
    list<DictionaryData>::const_iterator Yter=data.begin();
    while (Yter!=data.end()){
        Yter->printData();
        Yter++;
    }




  return 0;
}
