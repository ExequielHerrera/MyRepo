#ifndef ERRORTRATEMENTACTION_H
#define ERRORTRATEMENTACTION_H

#include "Action.h"

//Class that informs the interpreter that the error occurred


class ErrorTratementAction : public Action
{
    public:
        ErrorTratementAction(JsonAnalizer & jAnalizer);
        virtual ~ErrorTratementAction();
        int executeAction(char & entry,int &it);

    protected:

    private:
};

#endif // ERRORTRATEMENTACTION_H
