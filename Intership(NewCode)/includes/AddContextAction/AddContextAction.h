#pragma once

#include "Action.h"


//This action tells the interpreter to load a new unit context.


class AddContextAction : public Action
{
    public:
        AddContextAction() = default;
        ~AddContextAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};

