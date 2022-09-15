#include "ConcatenateKeyAction.h"

ConcatenateKeyAction::ConcatenateKeyAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

ConcatenateKeyAction::~ConcatenateKeyAction(){
}


int ConcatenateKeyAction::executeAction(char & entry,int &it){

    JsonAnalizer * analizer = Action::getJsonAnalizer();
    analizer->incrementDataKey(entry);
    return it+1;
}
