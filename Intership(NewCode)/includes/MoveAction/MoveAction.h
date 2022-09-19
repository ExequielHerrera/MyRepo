#pragma once

#include "Action.h"

//Class that consume the entry character.

class MoveAction : public Action
{
    public:
        MoveAction() = default;
        ~MoveAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};


