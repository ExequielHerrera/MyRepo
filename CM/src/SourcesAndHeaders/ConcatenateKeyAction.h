#ifndef CONCATENATEKEYACTION_H
#define CONCATENATEKEYACTION_H
#include "Action.h"


//Class that concatenates the characters of both the keys and the values ​​of the dictionary data.


class ConcatenateKeyAction: public Action
{
    public:
        ConcatenateKeyAction(JsonAnalizer & jAnalizer);
        virtual ~ConcatenateKeyAction();
        int executeAction(char & entry,int &it);
    protected:

    private:
};

#endif // CONCATENATEKEYACTION_H
