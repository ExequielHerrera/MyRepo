#include "DataReadyAction.h"


int DataReadyAction::executeAction(char & entry,int &it, JsonAnalizer & analizer){

    if ((int) entry == (int) AsciiValues::ASCII_E_OF_F){
            return it; //This action dont consumes the EofF, allowing the automata to finish the evaluation.
        }
    else
    {
        analizer.validateData();
        analizer.cleanData();
        if ((int) entry == (int) AsciiValues::ASCII_CLOSE_U){
                analizer.setRemoveContext(true);
            }
        return it+1;
    }
}
