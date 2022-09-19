#include "RemoveContextAction.h"



int RemoveContextAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){
    analizer.setRemoveContext(true);
    return it+1;
}
