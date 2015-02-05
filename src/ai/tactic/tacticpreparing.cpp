#include "tacticpreparing.h"


TacticPreparing::TacticPreparing(WorldModel *worldmodel, QObject *parent) :
    Tactic("TacticPreparing", worldmodel, parent)
{
    kickPermision = false;
    kickIt = false;
}

RobotCommand TacticPreparing::getCommand()
{
    RobotCommand rc;
    if(!wm->ourRobot[id].isValid) return rc;

    if( kickPermision )
    {
        rc.fin_pos.loc = Vector2D(0,0);
        rc.fin_pos.dir = 0;

        if(wm->ball.pos.loc.x > 0 && wm->ball.pos.loc.x < Field::MaxX/2)
        {
            rc.fin_pos = wm->kn->AdjustKickPoint(wm->ball.pos.loc,Field::oppGoalCenter);
            rc.useNav = true;

            if( (wm->ourRobot[this->id].pos.loc-wm->ball.pos.loc).length() < 175 )
                rc.useNav = false;
            Position Temp;
            Temp.loc = wm->ourRobot[this->id].pos.loc + wm->ourRobot[this->id].vel.loc * 0.015 ;
            if( wm->kn->CanKick(wm->ourRobot[this->id].pos,wm->ball.pos.loc) )
            {
                rc.kickspeedx = 250;
                kickIt = true;
            }
        }
    }
    else
    {
        rc.fin_pos = queuePos;
    }

    rc.maxSpeed = 0.5;
    rc.isBallObs = true;
    rc.isKickObs = true;

    return rc;
}
