#include "DataReadyAction.h"

DataReadyAction::DataReadyAction(JsonAnalizer & jAnalizer) : Action(jAnalizer)
{
    //ctor
}

DataReadyAction::~DataReadyAction()
{
    //dtor
}


int DataReadyAction::executeAction(char & entry,int &it){

    JsonAnalizer * analizer = Action::getJsonAnalizer();
    if ((int) entry== analizer->ASCII_E_OF_F)
        return it; //This action dont consumes the EofF, allowing the automata to finish the evaluation.
    else
    {
        analizer->validateData();
        analizer->cleanData();
        if ((int) entry == analizer->ASCII_CLOSE_U)
            analizer->setRemoveContext(true);
        return it+1;
    }
}
