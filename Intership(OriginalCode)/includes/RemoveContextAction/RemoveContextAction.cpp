#include "RemoveContextAction.h"

RemoveContextAction::RemoveContextAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

RemoveContextAction::~RemoveContextAction()
{
    //dtor
}

int RemoveContextAction::executeAction(char & entry,int &it){
    JsonAnalizer * analizer = Action::getJsonAnalizer();
    analizer->setRemoveContext(true);
    return it+1;
}
