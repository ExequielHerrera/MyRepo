#include "StayAction.h"

StayAction::StayAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

StayAction::~StayAction()
{
    //dtor
}

int StayAction::executeAction(char & entry,int &it){
    return it;
}
