#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "../Action/Action.h"

//Class that consume the entry character.

class MoveAction : public Action
{
    public:
        MoveAction(JsonAnalizer & jAnalizer);
        virtual ~MoveAction();
        int executeAction(char & entry,int &it);

    protected:

    private:
};

#endif // MOVEACTION_H
