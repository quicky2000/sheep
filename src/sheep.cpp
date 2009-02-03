#include "sheep.h"
#include "sheep_motor.h"
#include "sheep_situation_analyzer.h"

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
sheep::sheep(void):FSM<sheep_situation,sheep_transition>("sheep",new sheep_motor(), new sheep_situation_analyzer())
{
  setSituation(new sheep_situation());
  getSituation()->addSheep(pair<unsigned int,unsigned int>(0,0),true);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(1,0),true);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(2,0),true);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(3,0),true);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(0,4),false);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(1,4),false);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(2,4),false);
  getSituation()->addSheep(pair<unsigned int,unsigned int>(3,4),false);

  sheep_situation::initFinalSituation();
}

//-----------------------------------------------------------------------------
sheep::~sheep(void)
{
}

//-----------------------------------------------------------------------------
void sheep::configure(void)
{
}

//-----------------------------------------------------------------------------
string sheep::toString(void)const
{
  string l_result = "Not implemented";
  return l_result;
}

//-----------------------------------------------------------------------------
FSM_if* createSheep()
{
  return new sheep();
}

//-----------------------------------------------------------------------------
extern "C"
{
  void registerFsm(map<string,FSM_creator> *p_factory)
  {
    registerFsm("sheep",createSheep,p_factory);
  }
}
