#ifndef STAYACTION_H
#define STAYACTION_H


#include "Action.h"

//This class makes it possible to move between the automata states without consuming the input character.


class StayAction : public Action
{
    public:
        StayAction(JsonAnalizer & jAnalizer);
        virtual ~StayAction();
        int executeAction(char & entry,int &it);

    protected:

    private:
};

#endif // STAYACTION_H
