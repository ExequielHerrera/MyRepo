#include "CheckReservedWordAction.h"


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
    string out;
    for (int i = 0; i < word.length(); i++)
    {
        out = out + (char) tolower(word.at(i));
    }
    if (!analizer->isReservedWord(out))
        {
            analizer->setError();
        }
    else
        {
            analizer->setValueActualData(word);
        }
    return it;
}

