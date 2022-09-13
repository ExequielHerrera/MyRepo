#ifndef CONCATENATEDATAACTION_H
#define CONCATENATEDATAACTION_H
#include "Action.h"


//Class that concatenates the characters of both the keys and the values ​​of the dictionary data.


class ConcatenateDataAction : public Action
{
    public:
        ConcatenateDataAction(JsonAnalizer & jAnalizer);
        virtual ~ConcatenateDataAction();
        int executeAction(char & entry,int & it);
    protected:

    private:
};

#endif // CONCATENATEDATAACTION_H
