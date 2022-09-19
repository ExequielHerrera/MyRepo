#pragma once

#include <iostream>
#include <list>
#include "DictionaryData.h"
#include <vector>


class Action; //Advance declaration of the class Action.


//Main class of the resolution.
//It's responsable of creating the finite automata and executing each of the semantic actions in order to obtain the desired dictionary.




//C O N S T    D E F I N I T I O N

//values of the automata states

enum class AutomataStates   {SPACE=0,
                            Q_MARK=1,
                            D_POINT =2,
                            DIGIT=3,
                            LETTER =4,
                            OPEN_U=5,
                            POINT =6,
                            CLOSE_U =7,
                            COMMA=8,
                            E_OF_F = 9,
                            OTHERS = 10
                            };


//ASCII const for the characters.

enum class AsciiValues     {ASCII_SPACE =32,
                            ASCII_Q_MARK=34,
                            ASCII_D_POINT =58,
                            ASCII_OPEN_U=123,
                            ASCII_POINT =46,
                            ASCII_CLOSE_U =125,
                            ASCII_COMMA =44,
                            ASCII_E_OF_F =36
                            };


enum class States  {S0 = 0,
                    S1 = 1,
                    S2 = 2,
                    S3 = 3,
                    S4 = 4,
                    S5 = 5,
                    S6 = 6,
                    S7 = 7,
                    S8 = 8,
                    S9 = 9};

        //C O N S T   C L A S S E S    D E F I N I T I O N



class JsonAnalizer
{
    public:

        //public methods.

        JsonAnalizer();
        ~JsonAnalizer();


        void printAutomata() const;
        void setJsonCode(string &code);
        void addContext(string & newContext);
        void setKeyActualData(string & k);
        void setValueActualData(string & d);
        void validateData();
        void incrementDataKey(char & k);
        void incrementDataValue(char & d);
        void cleanData();
        void setError();
        void setNewContextAvailable(bool v);
        void setRemoveContext(bool v);


        int getActualState() const;
        bool getContextSwitch();
        bool isReservedWord(string & w);
        string getActualDataKey();
        string getActualDataValue();
        string updateContext(string & context);



        list<DictionaryData> getDictionary(); //Main function that solves the problem and delivers the desired output


        //Dimensions
        static const int AMOUNT_OF_STATES = 10;
        static const int AMOUNT_OF_CHARACTERS = 11;


        //Reserved words
        static const string RESERVED_TRUE;
        static const string RESERVED_FALSE;


    private:


        //Private variables


        int finiteAutomata[AMOUNT_OF_STATES][AMOUNT_OF_CHARACTERS];
        Action *actionMatrix[AMOUNT_OF_STATES][AMOUNT_OF_CHARACTERS];

        string jsonCode;
        bool error;
        bool newContextAvailable;
        bool removeContext;

        list<DictionaryData> dictionary;

        //vector<DictionaryData> dictionary;

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


