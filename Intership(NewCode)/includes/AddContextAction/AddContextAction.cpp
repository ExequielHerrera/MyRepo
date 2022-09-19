#include "AddContextAction.h"
#include <list>


int AddContextAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){
    analizer.setNewContextAvailable(true);
    return it+1;
}
