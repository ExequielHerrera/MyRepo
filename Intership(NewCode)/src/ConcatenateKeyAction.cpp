#include "ConcatenateKeyAction.h"


int ConcatenateKeyAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){

    analizer.incrementDataKey(entry);
    return it+1;
}
