#include "CheckReservedWordAction.h"
#include <algorithm>
#include <cctype>
#include <string>

CheckReservedWordAction::CheckReservedWordAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

CheckReservedWordAction::~CheckReservedWordAction()
{
    //dtor
}

int CheckReservedWordAction::executeAction(char & entry,int &it){

    JsonAnalizer * analizer = Action::getJsonAnalizer();
    string word = analizer->getActualDataValue();
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (!analizer->isReservedWord(word))
        {
            analizer->setError();
        }
    else
        {
            analizer->setValueActualData(word);
        }
    return it;
}

