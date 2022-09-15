#ifndef ADDCONTEXTACTION_H
#define ADDCONTEXTACTION_H
#include "Action.h"


//This action tells the interpreter to load a new unit context.


class AddContextAction : public Action
{
    public:
        AddContextAction(JsonAnalizer & jAnalizer);
        virtual ~AddContextAction();
        int executeAction(char & entry,int & it);

    protected:

    private:
};

#endif // ADDCONTEXTACTION_H
