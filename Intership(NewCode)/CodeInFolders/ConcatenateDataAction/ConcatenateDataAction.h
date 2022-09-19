#pragma once

#include "Action.h"


//Class that concatenates the characters of both the keys and the values ​​of the dictionary data.


class ConcatenateDataAction : public Action
{
    public:
        ConcatenateDataAction() = default;
        ~ConcatenateDataAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};


