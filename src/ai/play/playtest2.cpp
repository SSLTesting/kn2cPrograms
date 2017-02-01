#include "playtest2.h"

PlayTest2::PlayTest2(WorldModel *worldmodel, QObject *parent) :
    Play("PlayTest2", worldmodel, parent)
{
    tTest1 = new TacticTest2(wm);
}

int PlayTest2::enterCondition()
{
    return 0;
}


void PlayTest2::initRole()
{

}


void PlayTest2::execute()
{
}

