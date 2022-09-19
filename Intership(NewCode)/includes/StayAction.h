#pragma once

#include "Action.h"

//This class makes it possible to move between the automata states without consuming the input character.


class StayAction : public Action
{
    public:
        StayAction() = default;
        ~StayAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};

