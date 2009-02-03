
#ifndef _SHEEP_SITUATION_H_
#define _SHEEP_SITUATION_H_

#include "FSM_situation.h"
#include "sheep_context.h"

#include <set>
#include <map>

class sheep_situation:public FSM_situation<sheep_context>
{
 public:
  // Constructors and destructors
  sheep_situation(void);
  ~sheep_situation(void);
  
  // Methods inherited from FSM_situation
  string toString(void)const;
  string getStringId(void)const;
  bool isFinal(void)const;
  bool less(const FSM_situation_if *p_situation)const;
  
  // Dedicated methods
  void addSheep(const pair<unsigned int, unsigned int> &p_sheep,bool p_color);
  const map<pair<unsigned int, unsigned int>,bool >& getSheeps(void)const;
  bool less(const sheep_situation *p_situation)const;
  static void initFinalSituation(void);
  
 private:
  map<pair<unsigned int, unsigned int>,bool > m_sheeps;
  static map<pair<unsigned int, unsigned int>,bool > m_final_sheeps;
};

#endif
