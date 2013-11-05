
/*
  This file is part of sheep, implementation of sheep brain-teaser
  Copyright (C) 2013  Julien Thevenon ( julien_thevenon at yahoo.fr )

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "sheep_situation.h"

#include <iostream>
#include <sstream>
using namespace std;

namespace sheep
{
  //-----------------------------------------------------------------------------
  bool sheep_situation::is_final(void)const
  {
    return m_sheeps == m_final_sheeps;
  }

  //-----------------------------------------------------------------------------
  const string sheep_situation::get_string_id(void)const
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
  void sheep_situation::get_string_id(std::string & p_result)const
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

    p_result = l_result.str();
  }

  //-----------------------------------------------------------------------------
  const string sheep_situation::to_string(void)const
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
  void sheep_situation::to_string(std::string & p_result)const
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

    p_result = l_result.str();
  }

  //-----------------------------------------------------------------------------
  sheep_situation::~sheep_situation(void)
  {
  }


  //-----------------------------------------------------------------------------
  sheep_situation::sheep_situation(void)
  {
    this->set_context(*(new sheep_context()));
  }

  //-----------------------------------------------------------------------------
  void sheep_situation::add_sheep(const pair<unsigned int, unsigned int> & p_sheep,
				  bool p_color)
  {
    assert(m_sheeps.find(p_sheep)==m_sheeps.end());
    m_sheeps.insert(map<pair<unsigned int,unsigned int>,bool>::value_type(p_sheep,p_color));
  }

  //-----------------------------------------------------------------------------
  const map<pair<unsigned int, unsigned int>,bool >& sheep_situation::get_sheeps(void)const 
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
  void sheep_situation::init_final_situation(void)
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
}
//EOF
