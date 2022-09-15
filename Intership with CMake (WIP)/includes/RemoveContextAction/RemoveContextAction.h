#ifndef REMOVECONTEXTACTION_H
#define REMOVECONTEXTACTION_H

#include "../Action/Action.h"
#include "../JsonAnalizer/JsonAnalizer.h"


//This class indicates to the interpreter that a context was unnested.


class RemoveContextAction : public Action
{
    public:
        RemoveContextAction(JsonAnalizer & jAnalizer);
        virtual ~RemoveContextAction();
        int executeAction(char & entry,int &it);

    protected:

    private:
};

#endif // REMOVECONTEXTACTION_H
