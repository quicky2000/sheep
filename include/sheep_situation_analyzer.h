#ifndef _SHEEP_SITUATION_ANALYZER_
#define _SHEEP_SITUATION_ANALYZER_

#include "FSM_situation_analyzer.h"
#include "sheep_situation.h"
#include "sheep_transition.h"

class sheep_situation_analyzer: public FSM_situation_analyzer<sheep_situation,sheep_transition>
{
 public:
  // Constructors and Destructors
  sheep_situation_analyzer(void);
  ~sheep_situation_analyzer(void);
  
  // Methods inherited from FSM_situation_analyzer
  string toString(void);
  vector<sheep_transition*> getTransitions(sheep_situation* p_situation);

  // Specific methods
  void getReachablePositions(set<pair<unsigned int, unsigned int> > & p_result,unsigned int p_x,unsigned int p_y,const map<pair<unsigned int, unsigned int>,bool > &p_sheeps);
  };
#endif /* _SHEEP_SITUATION_ANALYZER_ */
