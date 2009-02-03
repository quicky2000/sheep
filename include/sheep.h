
#ifndef _SHEEP_BASE_H_
#define _SHEEP_BASE_H_

#include "FSM.h"
#include "sheep_situation.h"
#include "sheep_transition.h"
#include "sheep_context.h"

class sheep:public FSM<sheep_situation,sheep_transition>
{
	public:
	// Constructors && Destructors
	sheep(void);
	~sheep(void);

	// Methods inherited from FSM
	void configure(void);
	string toString(void)const;
};
#endif
