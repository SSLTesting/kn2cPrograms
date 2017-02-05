#include "playkickoffopp.h"
#include<QList>
#include<tactic/tacticattacker.h>
#include<math.h>
PlayKickoffOpp::PlayKickoffOpp(WorldModel *worldmodel, QObject *parent) :
    Play("PlayKickoffOpp", worldmodel, parent)
{
    tGolie=new TacticGoalie(wm);
    tAttackerLeft=new TacticAttacker(wm);
    tAttackerMid=new TacticAttacker(wm);
    tAttackerRight=new TacticAttacker(wm);
    tDefenderLeft=new TacticDefender(wm);
    tDefenderRight=new TacticDefender(wm);

}

int PlayKickoffOpp::enterCondition()
{
   /* if(wm->cmgs.theirKickoff())
        return 100;
    else
        return 0;*/
    return 3000;
}

void PlayKickoffOpp::initRole()
{
    QList<int> ourCurrentPlayers=wm->kn->ActiveAgents();
    ourCurrentPlayers.removeOne(wm->ref_goalie_our);
    wm->ourRobot[wm->ref_goalie_our].Role=AgentRole::Golie;
    switch(ourCurrentPlayers.length()){
        case 1:
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderLeft;
            break;
        case 2:
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderLeft;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderRight;
            break;
        case 3:
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderLeft;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderRight;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerMid;
            break;
        case 4:
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderLeft;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderRight;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerMid;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerLeft;
            break;
        case 5:
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderLeft;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::DefenderRight;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerMid;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerLeft;
            wm->ourRobot[ourCurrentPlayers.takeFirst()].Role=AgentRole::AttackerRight;
            break;

    }
}
void PlayKickoffOpp::setTactics(int index)
{
    switch(wm->ourRobot[index].Role){
        case AgentRole::Golie:
            tactics[index]=tGolie;
            break;
        case AgentRole::AttackerLeft:
            tactics[index]=tAttackerLeft;
            break;
        case AgentRole::AttackerMid:
            tactics[index]=tAttackerMid;
            break;
        case AgentRole::AttackerRight:
            tactics[index]=tAttackerRight;
            break;
        case AgentRole::DefenderLeft:
            tactics[index]=tDefenderLeft;
            break;
        case AgentRole::DefenderRight:
            tactics[index]=tDefenderRight;
            break;
    }
}
int PlayKickoffOpp::maximumGoalChanceID(QList<int> oppPlayer){
    QList<int> ourPlayer=wm->kn->ActiveAgents();
    QList<int> RobotTriangle;
    ourPlayer.removeOne(wm->ref_goalie_our);
    ourPlayer.removeOne(tAttackerMid->getID());
    ourPlayer.removeOne(tAttackerRight->getID());
    oppPlayer.removeOne(wm->ref_goalie_opp);
    oppPlayer.removeOne(kickerId);
    double maxAngle=0;
    int count=0;
    int maxCount=0;
    int maxId;
    for(int i=0;i<oppPlayer.length();i++){
        Segment2D segment1(wm->oppRobot[oppPlayer.at(i)].pos.loc,Field::ourGoalPost_L);
        Segment2D segment2(wm->oppRobot[oppPlayer.at(i)].pos.loc,Field::ourGoalPost_R);
        for(int j=0;j<ourPlayer.length();j++){
            if(isInsideTriangle(wm->ourRobot[ourPlayer.at(j)].pos.loc,wm->oppRobot[oppPlayer.at(i)].pos.loc)){
                RobotTriangle.append(ourPlayer.at(j));
            }
        }
        for(int y=Field::ourGoalPost_R.y;y<Field::ourGoalPost_L.y;y+=10){
            Vector2D loc(Field::MinX,y);
            Segment2D seg(wm->oppRobot[oppPlayer.at(i)].pos.loc,loc);
            bool value=true;
            for(int j=0;j<RobotTriangle.length();j++){
                Circle2D circle(wm->ourRobot[RobotTriangle.at(j)].pos.loc,ROBOT_RADIUS);
                Vector2D inter1,inter2;
                circle.intersection(seg,&inter1,&inter2);
                if((inter1.x!=0 && inter1.y!=0) || (inter2.x!=0 && inter2.y!=0))
                    value=false;
            }
            if(value)
                count++;
        }
        if((maxAngle<abs(segment1.direction().radian()-segment2.direction().radian()) || maxCount<count)
                && wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc)<=Field::MaxX*0.5){
            maxId=oppPlayer.at(i);
            maxAngle=abs(segment1.direction().radian()-segment2.direction().radian());
            maxCount=count;
        }
       // qDebug()<<oppPlayer.at(i)<<":"<<count;
       // qDebug()<<abs(segment1.direction().radian()-segment2.direction().radian());
        count=0;
        RobotTriangle.clear();
    }
    return maxId;
}
bool PlayKickoffOpp::isInsideTriangle(Vector2D pos, Vector2D vertex1){
    bool firstCon=false;
    bool secondCon=false;
    if((vertex1.x-Field::ourGoalPost_L.x)!=0 && pos.y<(vertex1.y-Field::ourGoalPost_L.y)/(vertex1.x-Field::ourGoalPost_L.x)*(pos.x-vertex1.x)+vertex1.y)
        firstCon=true;
    if((vertex1.x-Field::ourGoalPost_R.x)!=0 && pos.y>(vertex1.y-Field::ourGoalPost_R.y)/(vertex1.x-Field::ourGoalPost_R.x)*(pos.x-vertex1.x)+vertex1.y)
        secondCon=true;
    return firstCon && secondCon;
}
Position PlayKickoffOpp::KickerPositioning(Vector2D oppKicker){
    Line2D line(wm->ball.pos.loc,oppKicker);
    Circle2D circle(wm->ball.pos.loc,oppKicker.dist(wm->ball.pos.loc));
    Vector2D firstIntersect,secondIntersect;
    Position pos;
    circle.intersection(line,&firstIntersect,&secondIntersect);
    if(abs(firstIntersect.x-oppKicker.x)>2*ROBOT_RADIUS)
      pos.loc=firstIntersect;
    else if(secondIntersect!=oppKicker)
        pos.loc=secondIntersect;
    pos.dir=oppKicker.dir().radian()*-1;
    return pos;
}
void PlayKickoffOpp::findOppKickerId(){
    QList<int> oppPlayer=wm->kn->ActiveOppAgents();
    double minDist=wm->oppRobot[oppPlayer.at(0)].pos.loc.dist(wm->ball.pos.loc);
    for(int i=0;i<oppPlayer.length();i++){
        if(minDist>wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc)){
            minDist=wm->oppRobot[oppPlayer.at(i)].pos.loc.dist(wm->ball.pos.loc);
            kickerId=oppPlayer.at(i);
        }
    }
}

void PlayKickoffOpp::Positioning(int RobotID){
    Vector2D CenterOfField;
    CenterOfField.x=0;
    CenterOfField.y=0;
    Segment2D defenderRightLine(Field::ourGoalPost_R,CenterOfField);
    Segment2D defenderLeftLine(Field::ourGoalPost_L,CenterOfField);
    Segment2D midAttackerLine(Field::ourGoalCenter,CenterOfField);
    Position firstIntersection,secondInterSection;
    Circle2D circleOfCenter(CenterOfField,Field::centerCircle_R);
    Circle2D circleOfDefense(Field::ourGoalCenter,abs(Field::ourDefPost_L.y-Field::ourGoalCenter.y));
    if(wm->ourRobot[RobotID].Role==AgentRole::DefenderLeft){
        Line2D positionLine(CenterOfField,Field::ourGoalPost_L);
        circleOfDefense.intersection(positionLine,&firstIntersection.loc,&secondInterSection.loc);
        if(firstIntersection.loc.x>secondInterSection.loc.x){
            tDefenderLeft->setUseNav(false);
            firstIntersection.dir=defenderLeftLine.direction().radian();
            tDefenderLeft->setIdlePosition(firstIntersection);
        }
        else{
            secondInterSection.dir=defenderLeftLine.direction().radian();
            tDefenderLeft->setUseNav(false);
            tDefenderLeft->setIdlePosition(secondInterSection);
        }

    }
    else if(wm->ourRobot[RobotID].Role==AgentRole::DefenderRight){
        Line2D positionLine(CenterOfField,Field::ourGoalPost_R);
        circleOfDefense.intersection(positionLine,&firstIntersection.loc,&secondInterSection.loc);
        if(firstIntersection.loc.x>secondInterSection.loc.x){
            firstIntersection.dir=defenderRightLine.direction().radian();
            tDefenderRight->setUseNav(false);
            tDefenderRight->setIdlePosition(firstIntersection);
        }
        else{
            secondInterSection.dir=defenderRightLine.direction().radian();
            tDefenderRight->setUseNav(false);
            tDefenderRight->setIdlePosition(secondInterSection);
        }

    }
    else if(wm->ourRobot[RobotID].Role==AgentRole::AttackerLeft){
        Position ourKickerPos=KickerPositioning(wm->oppRobot[kickerId].pos.loc);
        tAttackerLeft->setIdlePosition(ourKickerPos);

    }
    else if(wm->ourRobot[RobotID].Role==AgentRole::AttackerRight || wm->ourRobot[RobotID].Role==AgentRole::AttackerMid){
        QList<int> oppPlayer=wm->kn->ActiveOppAgents();
        Position man2manSimulate1,man2manSimulate2;
        int first=maximumGoalChanceID(oppPlayer);
        man2manSimulate1.loc.y=wm->oppRobot[first].pos.loc.y;
        man2manSimulate1.loc.x=-1*wm->oppRobot[first].pos.loc.x;
        man2manSimulate1.dir=wm->oppRobot[first].pos.loc.dir().radian()+1.5;
        double distToball1=wm->oppRobot[first].pos.loc.dist(wm->ball.pos.loc);
        oppPlayer.removeOne(first);
        int second=maximumGoalChanceID(oppPlayer);
        man2manSimulate2.loc.y=wm->oppRobot[second].pos.loc.y;
        man2manSimulate2.loc.x=-1*wm->oppRobot[second].pos.loc.x;
        man2manSimulate2.dir=wm->oppRobot[second].pos.loc.dir().radian()+1.5;
        double distToball2=wm->oppRobot[second].pos.loc.dist(wm->ball.pos.loc);
        double dist1=wm->ourRobot[tAttackerMid->getID()].pos.loc.dist(man2manSimulate1.loc);
        double dist2=wm->ourRobot[tAttackerRight->getID()].pos.loc.dist(man2manSimulate1.loc);
            if(dist1<dist2){
                tAttackerMid->setIdlePosition(man2manSimulate1);
                tAttackerRight->setIdlePosition(man2manSimulate2);
            }else{
                tAttackerRight->setIdlePosition(man2manSimulate1);
                tAttackerMid->setIdlePosition(man2manSimulate2);
            }
    }
    else if(wm->ourRobot[RobotID].Role==AgentRole::Golie){
        Vector2D goalie;
        goalie.x=Field::ourGoalCenter.x+90;
        goalie.y=Field::ourGoalCenter.y;
        tGolie->setIdlePosition(goalie);
    }
}

void PlayKickoffOpp::execute(){
    findOppKickerId();
    Vector2D CenterOfField;
    Position center;
    center.loc=CenterOfField;
    CenterOfField.x=0;
    CenterOfField.y=0;
    QList<int> ourCurrentPlayer=wm->kn->ActiveAgents();
    for(int i=0;i<ourCurrentPlayer.length();i++){
        wm->ourRobot[i].Status=AgentStatus::Idle;
    }
    initRole();
    for(int i=0;i<ourCurrentPlayer.length();i++){
        setTactics(ourCurrentPlayer.at(i));
    }
    for(int i=0;i<ourCurrentPlayer.length();i++){
        Positioning(ourCurrentPlayer.at(i));
    }
    if(wm->cmgs.canKickBall()){
        int counter=0;
        QList<int> oppPlayer=wm->kn->ActiveOppAgents();
        for(int i=0;i<oppPlayer.length();i++){
            center.dir=wm->oppRobot[oppPlayer.at(i)].pos.dir;
            if(wm->kn->IsInsideCircle(wm->oppRobot[oppPlayer.at(i)].pos.loc,CenterOfField,Field::centerCircle_R+3000)
                    &&!wm->kn->IsReadyForKick(wm->oppRobot[oppPlayer.at(i)].pos,center,wm->ball.pos.loc)){
                counter++;
                Vector2D defense;
                if(counter==1){
                   defense.x=wm->oppRobot[oppPlayer.at(i)].pos.loc.x-ROBOT_RADIUS-100;
                   defense.y=wm->oppRobot[oppPlayer.at(i)].pos.loc.y;
                   tAttackerLeft->setIdlePosition(defense);
                }else if(counter==2){
                    defense.x=wm->oppRobot[oppPlayer.at(i)].pos.loc.x-ROBOT_RADIUS-100;
                    defense.y=wm->oppRobot[oppPlayer.at(i)].pos.loc.y;
                    tAttackerRight->setIdlePosition(defense);
                }
            }
        }
        counter==0;

   }
}










