#pragma once

#include "Action.h"


//This class controls that the value of a possible reserved word is validated within the language


class CheckReservedWordAction : public Action
{
    public:
        CheckReservedWordAction() = default;
        ~CheckReservedWordAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};

