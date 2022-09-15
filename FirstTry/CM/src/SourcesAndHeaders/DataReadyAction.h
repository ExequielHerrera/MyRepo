#ifndef DATAREADYACTION_H
#define DATAREADYACTION_H
#include "Action.h"

//This class is responsible for registering a new entry on the list of directories


class DataReadyAction : public Action
{
    public:
        DataReadyAction(JsonAnalizer & jAnalizer);
        virtual ~DataReadyAction();
        int executeAction(char & entry,int &it);

    protected:

    private:

};

#endif // DATAREADYACTION_H
