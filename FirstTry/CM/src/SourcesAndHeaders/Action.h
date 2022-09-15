#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include "JsonAnalizer.h"


//Parent class of the semantic actions of the interpreter.
//Each of its children will implement the definition of different actions to complement the operation of the finite automata.


using namespace std;

class Action
{
    public:
        Action(JsonAnalizer & jAnalizer);
        virtual ~Action();
        virtual int executeAction(char & entry,int &it) = 0; //semantic action in transitions.
        JsonAnalizer* getJsonAnalizer();

    protected:

    private:
        JsonAnalizer *analizer;
};

#endif // ACTION_H
