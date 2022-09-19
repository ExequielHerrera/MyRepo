#pragma once

#include "Action.h"

//Class that informs the interpreter that the error occurred


class ErrorTratementAction : public Action
{
    public:
        ErrorTratementAction() = default;
        ~ErrorTratementAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};

