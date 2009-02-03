
#include "sheep_situation.h"

#include <iostream>
#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
bool sheep_situation::isFinal(void)const
{
  return m_sheeps == m_final_sheeps;
}

//-----------------------------------------------------------------------------
string sheep_situation::getStringId(void)const
{
  stringstream l_result;
  for(int j=0;j<=4;j++)
    {
      for(int i=0;i<=3;i++)
	{
	  map<pair<unsigned int,unsigned int>,bool>::const_iterator l_iter = m_sheeps.find(pair<unsigned int,unsigned int>(i,j));
	  if(m_sheeps.end() != l_iter)
	    {
	      l_result << (l_iter->second?"N":"B");
	    }
	  else
	    {
	      l_result << "." ;
	    }

	}
    }

  return l_result.str();
}

//-----------------------------------------------------------------------------
string sheep_situation::toString(void)const
{
  stringstream l_result;
  for(int j=0;j<=4;j++)
    {
      for(int i=0;i<=3;i++)
	{
	  map<pair<unsigned int,unsigned int>,bool>::const_iterator l_iter = m_sheeps.find(pair<unsigned int,unsigned int>(i,j));
	  if(m_sheeps.end() != l_iter)
	    {
	      l_result << (l_iter->second?"N":"B");
	    }
	  else
	    {
	      l_result << "." ;
	    }

	}
      l_result << endl;
    }

  return l_result.str();
}

//-----------------------------------------------------------------------------
sheep_situation::~sheep_situation(void)
{
}


//-----------------------------------------------------------------------------
sheep_situation::sheep_situation(void)
{
  this->setContext(new sheep_context());
}

//-----------------------------------------------------------------------------
void sheep_situation::addSheep(const pair<unsigned int, unsigned int> &p_sheep,bool p_color)
{
  assert(m_sheeps.find(p_sheep)==m_sheeps.end());
  m_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(p_sheep,p_color));
}

//-----------------------------------------------------------------------------
const map<pair<unsigned int, unsigned int>,bool >& sheep_situation::getSheeps(void)const 
{
  return m_sheeps;
}


//-----------------------------------------------------------------------------
bool sheep_situation::less(const FSM_situation_if *p_situation)const
{
  return this->less(dynamic_cast<const sheep_situation*>(p_situation)); 
}

//-----------------------------------------------------------------------------
bool sheep_situation::less(const sheep_situation *p_situation)const
{
  return m_sheeps<p_situation->m_sheeps; 
}

//-----------------------------------------------------------------------------
void sheep_situation::initFinalSituation(void)
{
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(0,4),true));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(1,4),true));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(2,4),true));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(3,4),true));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(0,0),false));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(1,0),false));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(2,0),false));
  m_final_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(pair<unsigned int,unsigned int>(3,0),false));
}

 map<pair<unsigned int, unsigned int>,bool > sheep_situation::m_final_sheeps;
//EOF
