#include "playfreekickopp.h"

PlayFreeKickOpp::PlayFreeKickOpp(WorldModel *worldmodel, QObject *parent) :
    Play("PlayFreeKickOpp", worldmodel, parent)
{
    tGolie=new TacticGoalie(wm);
    tDefenderLeft=new TacticDefender(wm);
    tDefenderRight=new TacticDefender(wm);
    tAttackerLeft=new TacticAttacker(wm);
    tAttackerMid=new TacticAttacker(wm);
    tAttackerRight=new TacticAttacker(wm);
}

int PlayFreeKickOpp::enterCondition()
{
    if(wm->cmgs.theirFreeKick() || wm->cmgs.theirDirectKick())
    {
        if(wm->gs_last != wm->gs)
        {
            //rolesIsInit = false;
            //go2ThePositions = false;

          //  waitTimer->start(10);
        }
        //        else
        //        {
        //            rolesIsInit = conditionChanged();
        //        }
        return 100;
    }
    else
    {
        return 0;
    }
          return 3000;
}
void PlayFreeKickOpp::initRole()
{
    QList<int> ourActivePlayer=wm->kn->ActiveAgents();
    ourActivePlayer.removeOne(wm->ref_goalie_our);
    wm->ourRobot[wm->ref_goalie_our].Role=AgentRole::Golie;
    switch(ourActivePlayer.length()){
    case 1:
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerLeft;
        break;
    case 2:
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerRight;
        break;
    case 3:
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderRight;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerLeft;
        break;
    case 4:
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderRight;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerMid;
        break;
    case 5:
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderRight;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::DefenderLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerLeft;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerMid;
        wm->ourRobot[ourActivePlayer.takeFirst()].Role=AgentRole::AttackerRight;
        break;
    }
}

bool PlayFreeKickOpp::isInsideTriangle(Vector2D pos, Vector2D vertex1){
    bool firstCon=false;
    bool secondCon=false;
    if((vertex1.x-Field::ourGoalPost_L.x)!=0 && pos.y<(vertex1.y-Field::ourGoalPost_L.y)/(vertex1.x-Field::ourGoalPost_L.x)*(pos.x-vertex1.x)+vertex1.y)
        firstCon=true;
    if((vertex1.x-Field::ourGoalPost_R.x)!=0 && pos.y>(vertex1.y-Field::ourGoalPost_R.y)/(vertex1.x-Field::ourGoalPost_R.x)*(pos.x-vertex1.x)+vertex1.y)
        secondCon=true;
    return firstCon && secondCon;
}
QList<marking_player*> PlayFreeKickOpp::findmarking(Position_Evaluation posEval[],int oppNum){
    double temp;
    int tempID;
    QList<marking_player*> man2man;
    for(int i=0;i<oppNum;i++){
        for(int j=i;j<oppNum;j++){
            if(posEval[i].score<posEval[j].score){
                temp=posEval[j].score;
                posEval[j].score=posEval[i].score;
                posEval[i].score=temp;
                tempID=posEval[j].id;
                posEval[j].id=posEval[i].id;
                posEval[i].id=tempID;
            }
        }
    }
    man2man.append(new marking_player);
    man2man.append(new marking_player);
    man2man.at(0)->oppID=posEval[0].id;
    man2man.at(0)->ourID=tAttackerLeft->getID();
    man2man.at(1)->oppID=posEval[1].id;
    man2man.at(1)->ourID=tAttackerRight->getID();
    if(posEval[2].score==posEval[1].score){
        man2man.append(new marking_player);
        man2man.at(2)->oppID=posEval[2].id;
        man2man.at(2)->ourID=tDefenderLeft->getID();
    }
    if(posEval[3].score==posEval[2].score && posEval[3].score==posEval[1].score){
        man2man.append(new marking_player);
        man2man.at(3)->oppID=posEval[3].id;
        man2man.at(3)->ourID=tDefenderRight->getID();
    }
    return man2man;
}

void PlayFreeKickOpp::pressing()
{
   QList<int> oppPlayer=wm->kn->ActiveOppAgents();
   QList<int> ourPlayer=wm->kn->ActiveAgents();
   oppPlayer.removeOne(wm->ref_goalie_opp);
   ourPlayer.removeOne(ourkickerId);
   oppPlayer.removeOne(oppKickerId);
   ourPlayer.removeOne(wm->ref_goalie_our);
   int count=0;
   Position_Evaluation  posEval[oppPlayer.length()];
   //find distance to goal and ball
   for(int i=0;i<oppPlayer.length();i++){
       posEval[i].goalDis=wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(Field::ourGoalCenter);
       posEval[i].ballDis=wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc);
       posEval[i].id=oppPlayer.at(i);
   }
   for(int i=0;i<oppPlayer.length();i++){
       Segment2D segment1(wm->oppRobot[oppPlayer.at(i)].pos.loc,Field::ourGoalPost_L);
       Segment2D segment2(wm->oppRobot[oppPlayer.at(i)].pos.loc,Field::ourGoalPost_R);
       posEval[i].goalAngle=abs(segment1.direction().radian()-segment2.direction().radian());
       for(int j=0;j<ourPlayer.length();j++){
           if(isInsideTriangle(wm->oppRobot[ourPlayer.at(j)].pos.loc,wm->ourRobot[ourPlayer.at(i)].pos.loc))
               count++;
       }
       posEval[i].count=count;
   }
   for(int i=0;i<oppPlayer.length();i++){
       if(count<=1){
           if(posEval[i].ballDis<2000)
               posEval[i].score+=100;
           else posEval[i].score+=30;
           if(posEval[i].goalDis<3000)
               posEval[i].score+=200;
           else posEval[i].score+=60;
       }
       else if(count>1)
           posEval[i].score=0;
   }
   for(int i=0;i<oppPlayer.length();i++){
       qDebug()<<i<<" : "<<posEval[i].score;
       qDebug()<<"ID"<<oppPlayer.at(i);
   }
   man2man=findmarking(posEval,oppPlayer.length());
   for(int i=0;i<man2man.length();i++){
       setPlayer2Keep(man2man.at(i)->ourID,man2man.at(i)->oppID);
   }
}

void PlayFreeKickOpp::setTactics(int RobotID)
{
    switch(wm->ourRobot[RobotID].Role){
    case AgentRole::AttackerLeft:
        tactics[RobotID]=tAttackerLeft;
        break;
    case AgentRole::AttackerMid:
        tactics[RobotID]=tAttackerMid;
        break;
    case AgentRole::AttackerRight:
        tactics[RobotID]=tAttackerRight;
        break;
    case AgentRole::DefenderLeft:
        tactics[RobotID]=tDefenderLeft;
        break;
    case AgentRole::DefenderRight:
        tactics[RobotID]=tDefenderRight;
        break;
    case AgentRole::Golie:
        tactics[RobotID]=tGolie;
        break;
    }
}

void PlayFreeKickOpp::setPositions()
{
    Position leftDefPos,rightDefPos,goaliePos;
    int leftID = -1, rightID = -1 , midID = -1;
    bool leftNav, rightNav;

    if( wm->ourRobot[previousLeftID].Role != AgentRole::DefenderLeft )
        previousLeftID = -1;

    if( wm->ourRobot[previousRightID].Role != AgentRole::DefenderRight )
        previousRightID = -1;

    if( (wm->ourRobot[tDefenderLeft->getID()].Role == AgentRole::DefenderLeft) && (leftChecker < PresenceCounter) )
    {
        leftID = tDefenderLeft->getID();
        this->previousLeftID = tDefenderLeft->getID();;
    }

    if( wm->ourRobot[tDefenderRight->getID()].Role == AgentRole::DefenderRight && (rightChecker < PresenceCounter) )
    {
        rightID = tDefenderRight->getID();
        this->previousRightID = tDefenderRight->getID();;
    }

    if( leftChecker > PresenceCounter || leftID == -1 )
        midID = rightID;

    if( rightChecker > PresenceCounter  || rightID == -1)
        midID = leftID;

    zonePositions(leftID,rightID,midID,goaliePos,leftDefPos,leftNav,rightDefPos,rightNav);

    tDefenderLeft->setIdlePosition(leftDefPos);
    tDefenderLeft->setUseNav(leftNav);
    tDefenderRight->setIdlePosition(rightDefPos);
    tDefenderRight->setUseNav(rightNav);

    if( leftID != -1)
    {
        if( (wm->ourRobot[leftID].Status != AgentStatus::FollowingBall ) && (wm->ourRobot[leftID].pos.loc - leftDefPos.loc).length() > 250 )
            leftChecker++;
        else
            leftChecker = 0;
    }
    else
    {
        if( !haltedRobotIsInField(previousLeftID) )
            leftChecker = 0;
    }

    if( rightID != -1)
    {
        if( (wm->ourRobot[rightID].Status != AgentStatus::FollowingBall ) && (wm->ourRobot[rightID].pos.loc - rightDefPos.loc).length() > 250 )
            rightChecker++;
        else
            rightChecker = 0;
    }
    else
    {
        if( !haltedRobotIsInField(previousRightID) )
            rightChecker = 0;
    }

    tGolie->setIdlePosition(goaliePos);
    Vector2D inter1,inter2;
    Circle2D circle1(wm->oppRobot[man2man.at(1)->oppID].pos.loc,50);
    Segment2D seg1(wm->oppRobot[man2man.at(1)->oppID].pos.loc,Field::ourGoalCenter);
    circle1.intersection(seg1,&inter1,&inter2);
    tAttackerRight->setIdlePosition(inter1);
    Vector2D inter3,inter4;
    Circle2D circle2(wm->oppRobot[man2man.at(0)->oppID].pos.loc,50);
    Segment2D seg2(wm->oppRobot[man2man.at(0)->oppID].pos.loc,Field::ourGoalCenter);
    circle2.intersection(seg2,&inter3,&inter4);
    tAttackerLeft->setIdlePosition(inter3);
   if(man2man.length()>=3){
       Vector2D inter5,inter6;
       Circle2D circle3(wm->oppRobot[man2man.at(2)->oppID].pos.loc,50);
       Segment2D seg3(wm->oppRobot[man2man.at(2)->oppID].pos.loc,Field::ourGoalCenter);
       circle3.intersection(seg3,&inter5,&inter6);
       tDefenderLeft->setIdlePosition(inter5);
       if(man2man.length()==4){
           Vector2D inter1,inter2;
           Circle2D circle1(wm->oppRobot[man2man.at(3)->oppID].pos.loc,50);
           Segment2D seg1(wm->oppRobot[man2man.at(3)->oppID].pos.loc,Field::ourGoalCenter);
           circle1.intersection(seg1,&inter1,&inter2);
           tDefenderRight->setIdlePosition(inter1);
       }
    }
   man2man.clear();
   positionKicker();
}
void PlayFreeKickOpp::findKickerIDs(){
    QList<int> oppPlayer=wm->kn->ActiveOppAgents();
    double minDist=wm->oppRobot[oppPlayer.at(0)].pos.loc.dist(wm->ball.pos.loc);
    for(int i=0;i<oppPlayer.length();i++){
        if(minDist>wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc)){
            minDist=wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc);
            oppKickerId=oppPlayer.at(i);
        }
    }
    ourkickerId=tAttackerMid->getID();
}

void PlayFreeKickOpp::positionKicker(){
    Vector2D inter1,inter2;
    Line2D seg(wm->ball.pos.loc,wm->oppRobot[oppKickerId].pos.loc);
    Circle2D circle(wm->ball.pos.loc,700);
    circle.intersection(seg,&inter1,&inter2);
    if(inter1.x<inter2.x)
        tAttackerMid->setIdlePosition(inter1);
    else tAttackerMid->setIdlePosition(inter2);
}

void PlayFreeKickOpp::setPlayer2Keep(int ourR, int oppR)
{
    switch(wm->ourRobot[ourR].Role){
    case AgentRole::DefenderLeft:
        tDefenderLeft->setPlayerToKeep(oppR);
        break;
    case AgentRole::DefenderRight:
        tDefenderRight->setPlayerToKeep(oppR);
        break;
    case AgentRole::AttackerLeft:
        tAttackerRight->setPlayerToKeep(oppR);
    case AgentRole::AttackerRight:
        tAttackerRight->setPlayerToKeep(oppR);
        break;
    }
}

void PlayFreeKickOpp::execute()
{
    QList<int> ourActivePlayer=wm->kn->ActiveAgents();
    for(int i=0;i<ourActivePlayer.length();i++){
        wm->ourRobot[ourActivePlayer.at(i)].Status=AgentStatus::Idle;
    }
    initRole();
    for(int i=0;i<ourActivePlayer.length();i++){
        setTactics(ourActivePlayer.at(i));
    }
    findKickerIDs();
    pressing();
    setPositions();

}
