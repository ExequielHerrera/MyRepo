#ifndef CHECKRESERVEDWORDACTION_H
#define CHECKRESERVEDWORDACTION_H
#include "Action.h"


//This class controls that the value of a possible reserved word is validated within the language


class CheckReservedWordAction : public Action
{
    public:
        CheckReservedWordAction(JsonAnalizer & jAnalizer);
        virtual ~CheckReservedWordAction();
        int executeAction(char & entry,int & it);

    protected:

    private:
};

#endif // CHECKRESERVEDWORDACTION_H
