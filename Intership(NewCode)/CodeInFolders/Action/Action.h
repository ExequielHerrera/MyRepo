#pragma once


#include <iostream>
#include "../JsonAnalizer/JsonAnalizer.h"



//Parent class of the semantic actions of the interpreter.
//Each of its children will implement the definition of different actions to complement the operation of the finite automata.



class Action
{
    public:
        Action() = default;
        virtual ~Action() = default;
        virtual int executeAction(char & entry,int &it, JsonAnalizer & analizer) = 0; //semantic action in transitions.
        JsonAnalizer* getJsonAnalizer();
};
