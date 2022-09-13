#include "ConcatenateDataAction.h"

ConcatenateDataAction::ConcatenateDataAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

ConcatenateDataAction::~ConcatenateDataAction()
{
    //dtor
}
int ConcatenateDataAction::executeAction(char & entry,int &it){

    JsonAnalizer * analizer = Action::getJsonAnalizer();
    analizer->incrementDataValue(entry);
    return it+1;
}
