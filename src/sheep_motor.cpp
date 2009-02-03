#include "sheep_motor.h"

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
string sheep_motor::toString(void)
{
  string l_result = "sheep_motor";
  return l_result;
}

//-----------------------------------------------------------------------------
sheep_situation* sheep_motor::run(sheep_situation* p_situation,sheep_transition *p_transition)
{
  sheep_situation *l_result = new sheep_situation();
  map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter = p_situation->getSheeps().begin();
  map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter_end = p_situation->getSheeps().end();
  while(l_iter != l_iter_end)
    {
      if(l_iter->first != p_transition->getSource())
	{
	  l_result->addSheep(l_iter->first,l_iter->second);
	}
      else
	{
	  l_result->addSheep(p_transition->getTarget(),l_iter->second);
	}
      ++l_iter;
    }
  return l_result;
}

//-----------------------------------------------------------------------------
sheep_motor::~sheep_motor(void)
{
}

//-----------------------------------------------------------------------------
sheep_motor::sheep_motor(void)
{
}

