
#ifndef _SHEEP_MOTOR_H_
#define _SHEEP_MOTOR_H_

#include "FSM_motor.h"
#include "sheep_situation.h"
#include "sheep_transition.h"

class sheep_motor:public FSM_motor<sheep_situation,sheep_transition>
{
 public:
  // Constructors and destructors
  sheep_motor(void);
  ~sheep_motor(void);
  
  // Methods inherited from FSM_motor
  string toString(void);
  sheep_situation* run(sheep_situation* p_situation, sheep_transition *p_transition);
};

#endif
