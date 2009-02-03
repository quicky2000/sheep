#include "sheep_transition.h"

#include <sstream>

//-----------------------------------------------------------------------------
sheep_transition::sheep_transition
(
 const pair<unsigned int,unsigned int> &p_source,
 const pair<unsigned int,unsigned int> &p_target
):
  m_source(p_source),
  m_target(p_target)
{
}

//-----------------------------------------------------------------------------
sheep_transition::~sheep_transition(void)
{
}

//-----------------------------------------------------------------------------
string sheep_transition::toString(void)const
{
  stringstream l_result;
  l_result << "Source = (" << m_source.first << " , " << m_source.second << ")\tTarget(" << m_target.first << " , " << m_target.second << ")";
  return l_result.str();
}

//-----------------------------------------------------------------------------
const pair<unsigned int ,unsigned int>& sheep_transition::getSource(void)const
{
  return m_source;
}

//-----------------------------------------------------------------------------
const pair<unsigned int ,unsigned int>& sheep_transition::getTarget(void)const
{
  return m_target;
}
