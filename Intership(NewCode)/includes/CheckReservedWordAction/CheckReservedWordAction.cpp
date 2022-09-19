#include "CheckReservedWordAction.h"
#include<bits/stdc++.h>


int CheckReservedWordAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){

    string word = analizer.getActualDataValue();
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (!analizer.isReservedWord(word)){
            analizer.setError();
        }
    else{
            analizer.setValueActualData(word);
        }
    return it;
}

