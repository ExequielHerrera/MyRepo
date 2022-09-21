#include "../JsonAnalizer/JsonAnalizer.h"
#include "../ConcatenateDataAction/ConcatenateDataAction.h"
#include "../ConcatenateKeyAction/ConcatenateKeyAction.h"
#include "../ErrorTratementAction/ErrorTratementAction.h"
#include "../DataReadyAction/DataReadyAction.h"
#include "../StayAction/StayAction.h"
#include "../MoveAction/MoveAction.h"
#include "../CheckReservedWordAction/CheckReservedWordAction.h"
#include "../AddContextAction/AddContextAction.h"
#include "../RemoveContextAction/RemoveContextAction.h"



const string JsonAnalizer::RESERVED_TRUE = "true";

const string JsonAnalizer::RESERVED_FALSE = "false";




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
    delete actionMatrix[S1][DIGIT];   //pointer to a1.
    delete actionMatrix[S3][POINT];   //pointer to a2.
    delete actionMatrix[S4][OTHERS];  //pointer to a3.
    delete actionMatrix[S0][Q_MARK];  //pointer to a4.
    delete actionMatrix[S6][E_OF_F];  //pointer to a5.
    delete actionMatrix[S9][CLOSE_U]; //pointer to a6.
    delete actionMatrix[S3][OPEN_U];  //pointer to a7.
    delete actionMatrix[S0][OTHERS];  //pointer to a8.
    delete actionMatrix[S6][CLOSE_U]; //pointer to a9.

    //freeDictionaryList();
}



//P R I V A T E     M E T H O D S



 //Initializing of the finite automata.

void JsonAnalizer::initializingAutomata()
{
    for (int i = 0; i < AMOUNT_OF_STATES; i++)
    {
        for (int j = 0; j < AMOUNT_OF_CHARACTERS; j++)
        {
            if (i == S4 || i == S8 || i == S7 || i == S5)
                finiteAutomata[i][j] = S9;
            else
                finiteAutomata[i][j] = S0;
        }
    }

    finiteAutomata[S0][Q_MARK] = S1;
    finiteAutomata[S0][SPACE] = S0;

    finiteAutomata[S1][Q_MARK] = S2;
    finiteAutomata[S1][DIGIT] = S1;
    finiteAutomata[S1][LETTER] = S1;

    finiteAutomata[S2][D_POINT] = S3;
    finiteAutomata[S2][SPACE] = S2;

    finiteAutomata[S3][Q_MARK] = S5;
    finiteAutomata[S3][SPACE] = S3;
    finiteAutomata[S3][DIGIT] = S7;
    finiteAutomata[S3][LETTER] = S4;
    finiteAutomata[S3][OPEN_U] = S0;
    finiteAutomata[S3][POINT] = S8;

    finiteAutomata[S4][LETTER] = S4;

    finiteAutomata[S5][Q_MARK] = S9;
    finiteAutomata[S5][DIGIT] = S5;
    finiteAutomata[S5][LETTER] = S5;


    finiteAutomata[S7][DIGIT] = S7;
    finiteAutomata[S7][POINT] = S8;

    finiteAutomata[S8][DIGIT] = S8;

    finiteAutomata[S9][CLOSE_U] = S6;
    finiteAutomata[S9][COMMA] = S0;
    finiteAutomata[S9][SPACE] = S9;



    finiteAutomata[S6][COMMA] = S0;
    finiteAutomata[S6][CLOSE_U] = S6;
    finiteAutomata[S6][SPACE] = S6;
    finiteAutomata[S6][E_OF_F] = S0;
}



//Initializing of the action matrix.

void JsonAnalizer::initializingActions()
{


    ConcatenateKeyAction* a1 = new ConcatenateKeyAction(*this);
    ConcatenateDataAction* a2 = new ConcatenateDataAction(*this);
    CheckReservedWordAction* a3 = new CheckReservedWordAction(*this);
    MoveAction* a4 = new MoveAction(*this);


    StayAction* a5 = new StayAction(*this);
    DataReadyAction* a6 = new DataReadyAction(*this);
    AddContextAction* a7 = new AddContextAction(*this);


    ErrorTratementAction* a8 = new ErrorTratementAction(*this);
    RemoveContextAction* a9 = new RemoveContextAction(*this);

    for (int i = 0; i < AMOUNT_OF_STATES; i++)
    {
        for (int j = 0; j < AMOUNT_OF_CHARACTERS; j++)
        {
            if (i == S8 || i == S5 || i == S7)
                actionMatrix[i][j] = a5;
            else
            {
                if (i == S4)
                    actionMatrix[i][j] = a3;
                else
                    actionMatrix[i][j] = a8;
            }

        }
    }

    actionMatrix[S0][Q_MARK] = a4;
    actionMatrix[S0][SPACE] = a4;

    actionMatrix[S1][Q_MARK] = a4;
    actionMatrix[S1][DIGIT] = a1;
    actionMatrix[S1][LETTER] = a1;

    actionMatrix[S2][D_POINT] = a4;
    actionMatrix[S2][SPACE] = a4;

    actionMatrix[S3][Q_MARK] = a4;
    actionMatrix[S3][SPACE] = a4;
    actionMatrix[S3][DIGIT] = a2;
    actionMatrix[S3][LETTER] = a2;
    actionMatrix[S3][OPEN_U] = a7;
    actionMatrix[S3][POINT] = a2;

    actionMatrix[S4][LETTER] = a2;

    actionMatrix[S5][Q_MARK] = a4;
    actionMatrix[S5][DIGIT] = a2;
    actionMatrix[S5][LETTER] = a2;

    actionMatrix[S7][DIGIT] = a2;
    actionMatrix[S7][POINT] = a2;

    actionMatrix[S8][DIGIT] = a2;


    actionMatrix[S9][CLOSE_U] = a6;
    actionMatrix[S9][COMMA] = a6;
    actionMatrix[S9][SPACE] = a4;


    actionMatrix[S6][CLOSE_U] = a9;
    actionMatrix[S6][COMMA] = a4;
    actionMatrix[S6][SPACE] = a4;
    actionMatrix[S6][E_OF_F] = a5;
}


//Initializing of the class variables.

void JsonAnalizer::cleanAnalizer()
{
    actualState = 3;
    //freeDictionaryList();
    dictionary.clear();
    reservedWords.clear();
    reservedWords.push_back(RESERVED_TRUE);
    reservedWords.push_back(RESERVED_FALSE);
    removeContext = false;
    error = false;
    amountOfRemoveContestToMake = 0;
    amountOfActualContext = 0;

}

void JsonAnalizer::freeDictionaryList()
{
    for (list<DictionaryData>::iterator i = dictionary.begin(); i != dictionary.end(); i++)
    {
        delete&* i;
    }
}


//Method that obtains the corresponding column number, using the mapping established in the class declaration.

int JsonAnalizer::getColumn(char character) const {
    if ((int)character == ASCII_SPACE) return SPACE;
    if ((int)character == ASCII_Q_MARK) return Q_MARK;
    if ((int)character == ASCII_D_POINT) return D_POINT;
    if ((int)character == ASCII_OPEN_U) return OPEN_U;
    if ((int)character == ASCII_POINT) return POINT;
    if ((int)character == ASCII_CLOSE_U) return CLOSE_U;
    if ((int)character == ASCII_COMMA) return COMMA;
    if ((int)character == ASCII_E_OF_F) return E_OF_F;
    if (isdigit(character) > 0) return DIGIT;
    if (isalpha(character) > 0) return LETTER;
    return OTHERS;
    return 0;
}




//P U B L I C    M E T H O D S:


bool JsonAnalizer::isReservedWord(string w)
{
    list<string>::const_iterator Yter = reservedWords.begin();
    while (Yter != reservedWords.end())
    {
        if (*Yter == w)
            return true;
        Yter++;
    }
    return false;

}

void JsonAnalizer::setError() {
    error = true;
}

//Get of the actual state of interpretation.

int JsonAnalizer::getActualState() const {
    return actualState;
}


//Set of the input code.

void JsonAnalizer::setJsonCode(string code) {
    jsonCode = code;
}


//ActualData tratements.

void JsonAnalizer::setKeyActualData(string k) {
    actualData.setKey(k);

}
void JsonAnalizer::setValueActualData(string d) {
    actualData.setData(d);
}

void JsonAnalizer::incrementDataKey(char k) {
    actualData.incrementKey(k);
}

void JsonAnalizer::incrementDataValue(char d) {
    actualData.incrementData(d);

}

void JsonAnalizer::cleanData() {
    actualData.resetValues();
}


void JsonAnalizer::setNewContextAvailable(bool v) {
    newContextAvailable = v;
}

void JsonAnalizer::setRemoveContext(bool v) {
    removeContext = v;
    amountOfRemoveContestToMake++;
}


void JsonAnalizer::validateData() {
    DictionaryData* d = new DictionaryData(actualData.getKey(), actualData.getData());
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

string JsonAnalizer::updateContext(string context){
    if (amountOfRemoveContestToMake>amountOfActualContext) //if there's more units to close than actual units, then its an error.
    {
        error=false;
        return "";
    }
    else
    {
        string newContext;
        int i = (int) context.length();

        while (amountOfRemoveContestToMake!=0)
        {
            i = i-2;
            if (context.length() > 0)
            {
                while (context[i] != '.' && i != 0) {
                    i--;
                }
            }
            amountOfRemoveContestToMake--;
            amountOfActualContext--;
        }
        for (int j = 0 ; j < i; j++)
        newContext = newContext +context[j]+".";
        return newContext;
    }

}


//Method based on lexical analysis, which will provide the requested dictionary.

list<DictionaryData> JsonAnalizer::getDictionary()
{
    //we clean the current state of the analizer.
    cleanAnalizer();

    int index = (int) jsonCode.length()+1;
    //we create the list of characters that belong to the code.
    char* arr = new char[index];
	strcpy(arr, jsonCode.c_str());
    int it = 0;

    //we sets the context.

    string mainContext = getActualDataKey();
    string context = mainContext;

    while (true) //while there's code to analize.
    {

        char actualCharacter = arr[it];
        if(actualState==S0) //If we are in the start of a sentence.
        {
            if (removeContext) //If we have to remove contexts.
            {
                context = updateContext(context);
                removeContext=false;
            }
      
            if ((int)actualCharacter==ASCII_E_OF_F) //If we have finished to analyze all the code without errors.
                {
                
                    if (amountOfActualContext==amountOfRemoveContestToMake)
                       return dictionary;
                    else
                    {
                        cout<<"ERROR: units not closed correcly"<<endl;
                        return {};//Empty list.
                    }
                }
            if (newContextAvailable) //If we have a new context to add.
               {
                   context = actualData.getKey();
                    if (context!=mainContext)
                         context = context+ ".";
                    newContextAvailable=false;
                    amountOfActualContext++;
                }

        setKeyActualData(context);
        }
        if (error)
        {
            cout<<"ERROR: the code is not written correctly."<<endl;
            return {};//Empty list.
        }
        else //We have to move on the automata.
        {
            int column = getColumn(actualCharacter);
            if (actionMatrix[actualState][column]) //If we have an action to execute.
            {
                it = actionMatrix[actualState][column]->executeAction(actualCharacter,it); //Execute it.
            }
            actualState = finiteAutomata[actualState][column]; //We move to the next state.

        }
    }
}


