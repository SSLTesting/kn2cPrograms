#ifndef PLAYFREEKICKOPP_H
#define PLAYFREEKICKOPP_H

#include "play.h"
#include "man2man.h"
#include<QSerialPort>
struct  Position_Evaluation{
    double goalAngle;
    int count;
    int id;
    double goalDis;
    double ballDis;
    double score;
};
struct marking_player{
    int ourID;
    int oppID;
};

class PlayFreeKickOpp : public Play
{
    Q_OBJECT
public:
    explicit PlayFreeKickOpp(WorldModel *worldmodel, QObject *parent = 0);
    virtual void execute();
    virtual int enterCondition();

private:
    int ourkickerId,oppKickerId;
    TacticGoalie*   tGolie;
    TacticDefender* tDefenderLeft;
    bool leftDefender=true;
    TacticDefender* tDefenderRight;
    bool rightDefender=true;
    TacticAttacker* tAttackerMid;
    bool midAttacker=true;
    TacticAttacker* tAttackerLeft;
    bool leftAttacker=true;
    TacticAttacker* tAttackerRight;
    bool rightAttacker=true;
protected:
    virtual void initRole();

private:
    void pressing();
    void setTactics(int index);
    void setPositions();
    void setPlayer2Keep(int ourR,int oppR);
    bool isInsideTriangle(Vector2D pos,Vector2D vertex1);
    QList<marking_player*>findmarking(Position_Evaluation posEval[],int oppNum);
    QList<marking_player*>man2man;
    void findKickerIDs();
    void positionKicker();
};

#endif // PLAYFREEKICKOPP_H
