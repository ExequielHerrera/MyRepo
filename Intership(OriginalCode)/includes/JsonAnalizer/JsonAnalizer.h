#ifndef JSONANALIZER_H
#define JSONANALIZER_H

#include <iostream>
#include <list>
#include "../DictionaryData/DictionaryData.h"


class Action; //Advance declaration of the class Action.



using namespace std;


//Main class of the resolution.
//It's responsable of creating the finite automata and executing each of the semantic actions in order to obtain the desired dictionary.



class JsonAnalizer
{
    public:

        //public methods.

        JsonAnalizer();
        virtual ~JsonAnalizer();


        void printAutomata() const;
        void setJsonCode(string code);
        void addContext(string newContext);
        void setKeyActualData(string k);
        void setValueActualData(string d);
        void validateData();
        void incrementDataKey(char k);
        void incrementDataValue(char d);
        void cleanData();
        void setError();
        void setNewContextAvailable(bool v);
        void setRemoveContext(bool v);


        int getActualState() const;
        bool getContextSwitch();
        bool isReservedWord(string w);
        string getActualDataKey();
        string getActualDataValue();
        string updateContext(string context);



        list<DictionaryData> getDictionary(); //Main function that solves the problem and delivers the desired output


        //Constants definitions.

          // State const for the automata.
        static const int S0 = 0;
        static const int S1 = 1;
        static const int S2 = 2;
        static const int S3 = 3;
        static const int S4 = 4;
        static const int S5 = 5;
        static const int S6 = 6;
        static const int S7 = 7;
        static const int S8 = 8;
        static const int S9 = 9;

        //Value of the dimentions

        static const int AMOUNT_OF_STATES = 10;
        static const int AMOUNT_OF_CHARACTERS = 11;

        //Character const for the automata.

        static const int SPACE =0;
        static const int Q_MARK=1;
        static const int D_POINT =2;
        static const int DIGIT=3;
        static const int LETTER =4;
        static const int OPEN_U=5;
        static const int POINT =6;
        static const int CLOSE_U =7;
        static const int COMMA=8;
        static const int E_OF_F = 9;
        static const int OTHERS = 10;

        //ASCII const for the characters.

        static const int ASCII_SPACE =32;
        static const int ASCII_Q_MARK=34;
        static const int ASCII_D_POINT =58;
        static const int ASCII_OPEN_U=123;
        static const int ASCII_POINT =46;
        static const int ASCII_CLOSE_U =125;
        static const int ASCII_COMMA =44;
        static const int ASCII_E_OF_F =36;


        //Reserved words
        static const string RESERVED_TRUE;
        static const string RESERVED_FALSE;




    protected:



    private:


        //Private variables


        int finiteAutomata[AMOUNT_OF_STATES][AMOUNT_OF_CHARACTERS];
        Action *actionMatrix[AMOUNT_OF_STATES][AMOUNT_OF_CHARACTERS];

        string jsonCode;
        bool error;
        bool newContextAvailable;
        bool removeContext;

        list<DictionaryData> dictionary;
        list<string> reservedWords;

        int actualState;
        int amountOfRemoveContestToMake;
        int amountOfActualContext;
        DictionaryData actualData;


        //Private methods
        int getColumn(char character) const;
        void cleanAnalizer();
        void initializingAutomata();
        void initializingActions();
        void freeDictionaryList();



};

#endif // JSONANALIZER_H
