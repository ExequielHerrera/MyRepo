#include "ErrorTratementAction.h"

ErrorTratementAction::ErrorTratementAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

ErrorTratementAction::~ErrorTratementAction()
{
    //dtor
}

int ErrorTratementAction::executeAction(char & entry,int &it){
    JsonAnalizer * analizer = Action::getJsonAnalizer();
    analizer->setError();
    return it;
}
