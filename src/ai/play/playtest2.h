#ifndef PLAYTEST2_H
#define PLAYTEST2_H

#include "play.h"
#include "QDebug"
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

class PlayTest2 : public Play
{
    Q_OBJECT
public:
    explicit PlayTest2(WorldModel *worldmodel, QObject *parent = 0);
    virtual void execute();
    virtual void initRole();
    virtual int enterCondition();
    //virtual Tactic* getTactic(int id);

private:
    TacticTest2 *tTest1;

};

#endif // PLAYTEST2_H
