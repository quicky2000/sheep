
#ifndef _SHEEP_CONTEXT_H_
#define _SHEEP_CONTEXT_H_

#include "FSM_context.h"
#include "sheep_transition.h"

#include <set>

class sheep_context:public FSM_context<sheep_transition>
{
 public:
  sheep_context(void);

  // Methods inherited from interface
  string toString(void)const;

  // Specific methods

 private:
};

#endif
