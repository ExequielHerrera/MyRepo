#include "../Action/Action.h"

Action::Action(JsonAnalizer & jAnalizer)
{
    analizer=&jAnalizer;
}

Action::~Action()
{
    //dtor
}

JsonAnalizer* Action::getJsonAnalizer()
{
    return analizer;
}
