#include "ErrorTratementAction.h"



int ErrorTratementAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){
    analizer.setError();
    return it;
}
