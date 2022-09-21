#include "JsonAnalizer.h"
#include "ConcatenateDataAction.h"
#include "ConcatenateKeyAction.h"
#include "ErrorTratementAction.h"
#include "DataReadyAction.h"
#include "StayAction.h"
#include "MoveAction.h"
#include "CheckReservedWordAction.h"
#include "AddContextAction.h"
#include "RemoveContextAction.h"




const string JsonAnalizer::RESERVED_TRUE = "true";

const string JsonAnalizer::RESERVED_FALSE= "false";



JsonAnalizer::JsonAnalizer()
{
    initializingAutomata();
    initializingActions();
    cleanAnalizer();
}

//we free the memory for having allocated the anonymous variables in the heap.
//making a delete on one pointer per action.
JsonAnalizer::~JsonAnalizer()
{
    delete actionMatrix[(int) States::S1][(int) AutomataStates::DIGIT];   //pointer to a1.
    delete actionMatrix[(int) States::S3][(int) AutomataStates::POINT];   //pointer to a2.
    delete actionMatrix[(int) States::S4][(int) AutomataStates::OTHERS];  //pointer to a3.
    delete actionMatrix[(int) States::S0][(int) AutomataStates::Q_MARK];  //pointer to a4.
    delete actionMatrix[(int) States::S6][(int) AutomataStates::E_OF_F];  //pointer to a5.
    delete actionMatrix[(int) States::S9][(int) AutomataStates::CLOSE_U]; //pointer to a6.
    delete actionMatrix[(int) States::S3][(int) AutomataStates::OPEN_U];  //pointer to a7.
    delete actionMatrix[(int) States::S0][(int) AutomataStates::OTHERS];  //pointer to a8.
    delete actionMatrix[(int) States::S6][(int) AutomataStates::CLOSE_U]; //pointer to a9.

    //freeDictionaryList();
}



//P R I V A T E     M E T H O D S



 //Initializing of the finite automata.

void JsonAnalizer::initializingAutomata()
{
    for (int i = 0 ; i <AMOUNT_OF_STATES ; i++)
    {
       for (int j = 0 ; j < AMOUNT_OF_CHARACTERS ; j++)
       {
            if (i==(int) States::S4 || i==(int) States::S8 || i==(int) States::S7 || i==(int) States::S5){
                finiteAutomata[i][j] = (int) States::S9;
            }
            else{
                finiteAutomata[i][j] = (int) States::S0;
            }
       }
    }

    finiteAutomata[(int) States::S0][(int) AutomataStates::Q_MARK] = (int) States::S1;
    finiteAutomata[(int) States::S0][(int) AutomataStates::SPACE] = (int) States::S0;

    finiteAutomata[(int) States::S1][(int) AutomataStates::Q_MARK] = (int) States::S2;
    finiteAutomata[(int) States::S1][(int) AutomataStates::DIGIT] = (int) States::S1;
    finiteAutomata[(int) States::S1][(int) AutomataStates::LETTER] = (int) States::S1;

    finiteAutomata[(int) States::S2][(int) AutomataStates::D_POINT] = (int) States::S3;
    finiteAutomata[(int) States::S2][(int) AutomataStates::SPACE] = (int) States::S2;

    finiteAutomata[(int) States::S3][(int) AutomataStates::Q_MARK] = (int) States::S5;
    finiteAutomata[(int) States::S3][(int) AutomataStates::SPACE] = (int) States::S3;
    finiteAutomata[(int) States::S3][(int) AutomataStates::DIGIT] = (int) States::S7;
    finiteAutomata[(int) States::S3][(int) AutomataStates::LETTER] = (int) States::S4;
    finiteAutomata[(int) States::S3][(int) AutomataStates::OPEN_U] = (int) States::S0;
    finiteAutomata[(int) States::S3][(int) AutomataStates::POINT] = (int) States::S8;

    finiteAutomata[(int) States::S4][(int) AutomataStates::LETTER] = (int) States::S4;

    finiteAutomata[(int) States::S5][(int) AutomataStates::Q_MARK] = (int) States::S9;
    finiteAutomata[(int) States::S5][(int) AutomataStates::DIGIT] = (int) States::S5;
    finiteAutomata[(int) States::S5][(int) AutomataStates::LETTER] = (int) States::S5;


    finiteAutomata[(int) States::S7][(int) AutomataStates::DIGIT] = (int) States::S7;
    finiteAutomata[(int) States::S7][(int) AutomataStates::POINT] = (int) States::S8;

    finiteAutomata[(int) States::S8][(int) AutomataStates::DIGIT] = (int) States::S8;

    finiteAutomata[(int) States::S9][(int) AutomataStates::CLOSE_U] = (int) States::S6;
    finiteAutomata[(int) States::S9][(int) AutomataStates::COMMA] = (int) States::S0;
    finiteAutomata[(int) States::S9][(int) AutomataStates::SPACE] = (int) States::S9;



    finiteAutomata[(int) States::S6][(int) AutomataStates::COMMA] = (int) States::S0;
    finiteAutomata[(int) States::S6][(int) AutomataStates::CLOSE_U] = (int) States::S6;
    finiteAutomata[(int) States::S6][(int) AutomataStates::SPACE] = (int) States::S6;
    finiteAutomata[(int) States::S6][(int) AutomataStates::E_OF_F] = (int) States::S0;
}



//Initializing of the action matrix.

void JsonAnalizer::initializingActions()
{


    ConcatenateKeyAction *a1 = new ConcatenateKeyAction();
    ConcatenateDataAction *a2 = new ConcatenateDataAction();
    CheckReservedWordAction* a3 = new CheckReservedWordAction();
    MoveAction * a4 = new MoveAction();


    StayAction * a5 = new StayAction();
    DataReadyAction *a6 = new DataReadyAction();
    AddContextAction *a7 = new AddContextAction();


    ErrorTratementAction *a8 = new ErrorTratementAction();
    RemoveContextAction *a9 = new RemoveContextAction();

    for (int i = 0 ; i <AMOUNT_OF_STATES ; i++)
    {
       for (int j = 0 ; j < AMOUNT_OF_CHARACTERS ; j++)
       {
            if (i==(int) States::S8 || i==(int) States::S5 || i==(int) States::S7){
                actionMatrix[i][j] = a5;
                }
                else
                {
                    if (i==(int) States::S4){
                        actionMatrix[i][j] = a3;
                    }
                    else{
                        actionMatrix[i][j] = a8;
                        }
                }

        }
    }

    actionMatrix[(int) States::S0][(int) AutomataStates::Q_MARK] = a4 ;
    actionMatrix[(int) States::S0][(int) AutomataStates::SPACE] = a4;

    actionMatrix[(int) States::S1][(int) AutomataStates::Q_MARK] = a4;
    actionMatrix[(int) States::S1][(int) AutomataStates::DIGIT] = a1;
    actionMatrix[(int) States::S1][(int) AutomataStates::LETTER] = a1;

    actionMatrix[(int) States::S2][(int) AutomataStates::D_POINT] = a4;
    actionMatrix[(int) States::S2][(int) AutomataStates::SPACE] = a4;

    actionMatrix[(int) States::S3][(int) AutomataStates::Q_MARK] = a4;
    actionMatrix[(int) States::S3][(int) AutomataStates::SPACE] = a4;
    actionMatrix[(int) States::S3][(int) AutomataStates::DIGIT] = a2;
    actionMatrix[(int) States::S3][(int) AutomataStates::LETTER] = a2;
    actionMatrix[(int) States::S3][(int) AutomataStates::OPEN_U] = a7;
    actionMatrix[(int) States::S3][(int) AutomataStates::POINT] = a2;

    actionMatrix[(int) States::S4][(int) AutomataStates::LETTER] = a2;

    actionMatrix[(int) States::S5][(int) AutomataStates::Q_MARK] = a4;
    actionMatrix[(int) States::S5][(int) AutomataStates::DIGIT] = a2;
    actionMatrix[(int) States::S5][(int) AutomataStates::LETTER] = a2;

    actionMatrix[(int) States::S7][(int) AutomataStates::DIGIT] = a2;
    actionMatrix[(int) States::S7][(int) AutomataStates::POINT] = a2;

    actionMatrix[(int) States::S8][(int) AutomataStates::DIGIT] = a2;


    actionMatrix[(int) States::S9][(int) AutomataStates::CLOSE_U] = a6;
    actionMatrix[(int) States::S9][(int) AutomataStates::COMMA] = a6;
    actionMatrix[(int) States::S9][(int) AutomataStates::SPACE] = a4;


    actionMatrix[(int) States::S6][(int) AutomataStates::CLOSE_U] = a9;
    actionMatrix[(int) States::S6][(int) AutomataStates::COMMA] = a4;
    actionMatrix[(int) States::S6][(int) AutomataStates::SPACE] = a4;
    actionMatrix[(int) States::S6][(int) AutomataStates::E_OF_F] = a5;
}


//Initializing of the class variables.

void JsonAnalizer::cleanAnalizer()
{
    actualState=3;
    //freeDictionaryList();
    dictionary.clear();
    reservedWords.clear();
    reservedWords.push_back(RESERVED_TRUE);
    reservedWords.push_back(RESERVED_FALSE);
    removeContext=false;
    error=false;
    amountOfRemoveContestToMake=0;
    amountOfActualContext=0;

}

void JsonAnalizer::freeDictionaryList()
{
    for (list<DictionaryData>::iterator i=dictionary.begin(); i!=dictionary.end(); i++)
    {
       delete  &*i;
    }
}


//Method that obtains the corresponding column number, using the mapping established in the class declaration.

int JsonAnalizer::getColumn(char character) const{
    if ((int) character ==(int) AsciiValues::ASCII_SPACE){ return (int) AutomataStates::SPACE;}
    if ((int) character ==(int) AsciiValues::ASCII_Q_MARK){ return (int) AutomataStates::Q_MARK;}
    if ((int) character ==(int) AsciiValues::ASCII_D_POINT ){ return (int) AutomataStates::D_POINT;}
    if ((int) character ==(int) AsciiValues::ASCII_OPEN_U) {return (int) AutomataStates::OPEN_U;}
    if ((int) character ==(int) AsciiValues::ASCII_POINT ) {return (int) AutomataStates::POINT;}
    if ((int) character ==(int) AsciiValues::ASCII_CLOSE_U ){ return (int) AutomataStates::CLOSE_U;}
    if ((int) character ==(int) AsciiValues::ASCII_COMMA ) {return (int) AutomataStates::COMMA;}
    if ((int) character ==(int) AsciiValues::ASCII_E_OF_F ) {return (int) AutomataStates::E_OF_F;}
    if (isdigit(character)>0) {return (int) AutomataStates::DIGIT;}
    if (isalpha(character)>0) {return (int) AutomataStates::LETTER;}
    return (int) AutomataStates::OTHERS;
}




//P U B L I C    M E T H O D S:


bool JsonAnalizer::isReservedWord(string & w)
{
    list<string>::const_iterator Yter=reservedWords.begin();
    while (Yter!=reservedWords.end())
    {
        if (*Yter==w){
            return true;}
        Yter++;
    }
    return false;

}

void JsonAnalizer::setError(){
    error = true;
}

//Get of the actual state of interpretation.

int JsonAnalizer::getActualState() const{
    return actualState;
}


//Set of the input code.

void JsonAnalizer::setJsonCode(string & code) {
   jsonCode = code;
}


//ActualData tratements.

void JsonAnalizer::setKeyActualData(string & k){
    actualData.setKey(k);

}
void JsonAnalizer::setValueActualData(string & d){
    actualData.setData(d);
}

void JsonAnalizer::incrementDataKey(char & k){
    actualData.incrementKey(k);
}

void JsonAnalizer::incrementDataValue(char & d){
    actualData.incrementData(d);

}

void JsonAnalizer::cleanData(){
    actualData.resetValues();
}


void JsonAnalizer::setNewContextAvailable(bool v){
    newContextAvailable=v;
}

void JsonAnalizer::setRemoveContext(bool v){
    removeContext=v;
    amountOfRemoveContestToMake++;
}


void JsonAnalizer::validateData(){
    DictionaryData *d = new DictionaryData(actualData.getKey(),actualData.getData());
    dictionary.push_back(*d);

}

string JsonAnalizer::getActualDataValue()
{
    return actualData.getData();
}

string JsonAnalizer::getActualDataKey()
{
    return actualData.getKey();
}


//This method is responsable for remove the current contexts, based on the number of requests so far.

string JsonAnalizer::updateContext(string & context){
    if (amountOfRemoveContestToMake > amountOfActualContext) //if there's more units to close than actual units, then its an error.
    {
        error = false;
        return "";
    }
    else
    {
        string newContext;
        int i = (int)context.length();

        while (amountOfRemoveContestToMake != 0)
        {
            i = i - 2;
            if (context.length() > 0)
            {
                while (context[i] != '.' && i != 0) {
                    i--;
                }
            }
            amountOfRemoveContestToMake--;
            amountOfActualContext--;
        }
        for (int j = 0; j < i; j++)
            newContext = newContext + context[j] + ".";
        return newContext;
    }

}


//Method based on lexical analysis, which will provide the requested dictionary.

list<DictionaryData> JsonAnalizer::getDictionary()
{

    //we clean the current state of the analizer.
    cleanAnalizer();



    int index = (int)jsonCode.length() + 1;
    //we create the list of characters that belong to the code.
    char* arr = new char[index];
    strcpy(arr, jsonCode.c_str());
    int it = 0;

    //we sets the context.

    string mainContext = getActualDataKey();
    string context = mainContext;
    bool done=false;

    while (!done) //while there's code to analize.
    {
        char actualCharacter = arr[it];
        if(actualState==(int) States::S0) //If we are in the start of a sentence.
        {
            if (removeContext){ //If we have to remove contexts.

                context = updateContext(context);
                removeContext=false;
            }
            if ((int)actualCharacter==(int)AsciiValues::ASCII_E_OF_F){ //If we have finished to analyze all the code without errors.

                    if (amountOfActualContext==amountOfRemoveContestToMake){
                        done=true;
                        return dictionary;}
                    else{
                        cout<<"ERROR: units not closed correcly"<<endl;
                        done=true;
                        return {};//Empty list.
                    }
                }
            if (newContextAvailable) //If we have a new context to add.
               {
                   context = actualData.getKey();
                    if (context!=mainContext){
                         context = context+ ".";}
                    newContextAvailable=false;
                    amountOfActualContext++;
                }

        setKeyActualData(context);
        }
        if (error){
            cout<<"ERROR: the code is not written correctly."<<endl;
            done=true;
            return {};//Empty list.
        }
        else //We have to move on the automata.
        {
            int column = getColumn(actualCharacter);
            if (actionMatrix[actualState][column]){ //If we have an action to execute.
                it = actionMatrix[actualState][column]->executeAction(actualCharacter,it,*this); //Execute it.
            }
            actualState = finiteAutomata[actualState][column]; //We move to the next state.

        }
    }
    return {};//Empty list.
}


