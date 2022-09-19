#pragma once

#include "Action.h"


//This class indicates to the interpreter that a context was unnested.


class RemoveContextAction : public Action
{
    public:
        RemoveContextAction() = default;
        ~RemoveContextAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};

