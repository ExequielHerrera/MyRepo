#include "CheckReservedWordAction.h"


int CheckReservedWordAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){

    string word = analizer.getActualDataValue();
    string out;
    for (int i = 0; i < word.length(); i++)
    {
        out = out + (char)tolower(word.at(i));
    }
    if (!analizer.isReservedWord(out))
    {
        analizer.setError();
    }
    else
    {
        analizer.setValueActualData(word);
    }
    return it;
}

