#include "AddContextAction.h"
#include <list>

AddContextAction::AddContextAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

AddContextAction::~AddContextAction()
{
    //dtor
}

int AddContextAction::executeAction(char & entry,int &it){

    JsonAnalizer * analizer = Action::getJsonAnalizer();
    analizer->setNewContextAvailable(true);
    return it+1;
}
