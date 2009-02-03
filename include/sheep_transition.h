#ifndef _SHEEP_TRANSITION_
#define _SHEEP_TRANSITION_

#include "FSM_transition_if.h"

class sheep_transition: public FSM_transition_if
{
 public:
  // Constructors && Destructors
  sheep_transition(const pair<unsigned int,unsigned int> &p_source,const pair<unsigned int,unsigned int> &p_target);
  ~sheep_transition(void);
  
  // Methods inherited from interface
  string toString(void)const;
  
  // Dedicated methods
  const pair<unsigned int ,unsigned int>& getSource(void)const;
  const pair<unsigned int ,unsigned int>& getTarget(void)const;
  
 private:
  pair<unsigned int ,unsigned int> m_source;
  pair<unsigned int ,unsigned int> m_target;
};
#endif /* _SHEEP_TRANSITION_ */
