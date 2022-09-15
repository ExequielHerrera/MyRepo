#include "MoveAction.h"

MoveAction::MoveAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

MoveAction::~MoveAction()
{
    //dtor
}

int MoveAction::executeAction(char & entry,int &it){
    return it+1;
}
