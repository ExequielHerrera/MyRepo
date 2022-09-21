#include "ConcatenateDataAction.h"


int ConcatenateDataAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){

    analizer.incrementDataValue(entry);
    return it+1;
}
