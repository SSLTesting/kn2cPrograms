#ifndef PLAYSTOP_H
#define PLAYSTOP_H

#include "play.h"
#include "QDebug"

class PlayStop : public Play
{
    Q_OBJECT
public:
    explicit PlayStop(WorldModel *worldmodel, QObject *parent = 0);
    virtual void execute();
    //virtual Tactic* getTactic(int id);
    virtual int enterCondition();

private:
    int numberOfDef;
    TacticGoalie*   tGolie;
    TacticDefender* tDefenderLeft;
    TacticDefender* tDefenderRight;
    TacticDefender* tDefenderMid;
    TacticStop* tStopMid;
    TacticStop* tStopLeft;
    TacticStop* tStopRight;

    virtual void initRole();
    void setTactics(int index);
};

#endif // PLAYSTOP_H
