#pragma once

#include "Action.h"

//This class is responsible for registering a new entry on the list of directories


class DataReadyAction : public Action
{
    public:
        DataReadyAction() = default;
        ~DataReadyAction() = default;
        int executeAction(char & entry,int &it, JsonAnalizer & analizer);
};
