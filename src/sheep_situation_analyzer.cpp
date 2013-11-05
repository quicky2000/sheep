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
#include "sheep_situation_analyzer.h"
#include <inttypes.h>

using namespace std;

namespace sheep
{

  //-----------------------------------------------------------------------------
  sheep_situation_analyzer::sheep_situation_analyzer
  (
   void
   ):
    FSM_situation_analyzer<sheep_situation,sheep_transition>()
  {
  }

  //-----------------------------------------------------------------------------
  sheep_situation_analyzer::~sheep_situation_analyzer(void)
  {
  }

  //-----------------------------------------------------------------------------
  const std::string & sheep_situation_analyzer::get_class_name(void)const
  {
    return m_class_name;
  }

  //-----------------------------------------------------------------------------
  vector<const sheep_transition*> & sheep_situation_analyzer::get_transitions
  (
   sheep_situation & p_situation
   )
  {
    vector<const sheep_transition*> l_result;
    const map<pair<unsigned int, unsigned int>,bool > &l_sheeps = p_situation.get_sheeps();

    map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter = l_sheeps.begin();
    map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter_end = l_sheeps.end();

    // Store which positionis blocked bqnd who is blocking
    map<pair<unsigned int, unsigned int>,uint32_t> l_blocked_positions;
  
    // loop which cover all sheeps
    while(l_iter != l_iter_end)
      {
	int l_x = l_iter->first.first;
	int l_y = l_iter->first.second;
	//COMMENT_OUTPUT      cout << endl <<  "Sheep ( " << l_x << " , " << l_y << " ) = " << (l_iter->second?"N":"B") << endl ;

	// Compute reachable positions
	set<pair<unsigned int,unsigned int> > l_reachable_positions;
	get_reachable_positions(l_reachable_positions,l_x,l_y,l_sheeps);
	std::cout << "Determine reachable positions for (" << l_x << "," << l_y << ")" << std::endl ;
      

	// Build corresponding transitions and store reachable positions
	set<pair<unsigned int,unsigned int> >::const_iterator l_iter_reachable = l_reachable_positions.begin();
	set<pair<unsigned int,unsigned int> >::const_iterator l_iter_reachable_end = l_reachable_positions.end();
	while(l_iter_reachable != l_iter_reachable_end)
	  {
	    map<pair<unsigned int, unsigned int>,uint32_t >::iterator l_blocked_iter = l_blocked_positions.find(*l_iter_reachable);
	    if(l_blocked_positions.end() == l_blocked_iter)
	      {
		l_blocked_iter = l_blocked_positions.insert(map<pair<unsigned int,unsigned int>,uint32_t>::value_type(*l_iter_reachable,( l_iter->second ? 2 : 1))).first;
	      }
	    else
	      {
		l_blocked_iter->second |= ( l_iter->second ? 2 : 1);
	      }
	    std::cout << "-> (" << l_iter_reachable->first << "," << l_iter_reachable->second << ") = " << (uint32_t) l_blocked_iter->second << std::endl ;
          
	    l_result.push_back(new sheep_transition(l_iter->first,*l_iter_reachable));
	    //COMMENT_OUTPUTcout << "X = " << l_iter_reachable->first << "\tY = " << l_iter_reachable->second << endl;
	    ++l_iter_reachable;
	  }
	++l_iter;
      }

    // Analysing transitions to remove invalid
    vector<const sheep_transition*>::const_iterator l_result_iter = l_result.begin();
    vector<const sheep_transition*>::const_iterator l_result_iter_end = l_result.end();
    vector<const sheep_transition*> & l_real_result = *(new vector<const sheep_transition*>);
    while(l_result_iter != l_result_iter_end)
      {
	bool l_valid = true;
	//check validity of transition
	map<pair<unsigned int, unsigned int>,uint32_t>::iterator l_blocked_iter = l_blocked_positions.find((*l_result_iter)->get_target());
	if(l_blocked_positions.end() != l_blocked_iter)
	  {
	    // Check that the position is not blocked by a sheep of different colour
	    map<pair<unsigned int, unsigned int>,bool >::const_iterator l_sheep_iter = l_sheeps.find((*l_result_iter)->get_source());
	    assert(l_sheeps.end() != l_sheep_iter);
	    l_valid = 0 == (( l_sheep_iter->second ? 1 : 2) & l_blocked_iter->second);
	  }
	if(l_valid)
	  {
	    std::cout << "Valid -> " << (*l_result_iter)->to_string() << std::endl ;
	    l_real_result.push_back(*l_result_iter);
	  }
	else
	  {
	    delete *l_result_iter;
	  }
	++l_result_iter;
      }
    return l_real_result;
  }

  //-----------------------------------------------------------------------------
  void sheep_situation_analyzer::get_reachable_positions(set<pair<unsigned int, unsigned int> > & p_result,
							 const unsigned int & p_x,
							 const unsigned int & p_y,
							 const map<pair<unsigned int, unsigned int>,bool > & p_sheeps)
  {
    // Determination of relative positions compare to the borders
    int l_x_low = -p_x;
    int l_y_low = -p_y;
    int l_x_high = 4 - p_x - 1;
    int l_y_high = 5 - p_y - 1;
  
    // check ranges for ++ diagonal
    int l_min = (l_x_low < l_y_low)?l_y_low:l_x_low;
    int l_max = (l_x_high < l_y_high)?l_x_high:l_y_high;
    for(int l_index = -1 ; l_index >= l_min && p_sheeps.find(pair<unsigned int,unsigned int>(p_x + l_index,p_y + l_index)) == p_sheeps.end() ; l_index--)
      {
	p_result.insert(pair<unsigned int,unsigned int>(p_x + l_index,p_y + l_index));
      }
    for(int l_index = 1 ; l_index <=l_max && p_sheeps.find(pair<unsigned int,unsigned int>(p_x + l_index,p_y + l_index)) == p_sheeps.end() ; l_index++)
      {
	p_result.insert(pair<unsigned int,unsigned int>(p_x + l_index,p_y + l_index));
      }
  
    // check ranges for +- diagonal
    l_min = (l_x_low < -l_y_high)?-l_y_high:l_x_low;
    l_max = (l_x_high < -l_y_low)?l_x_high:-l_y_low;
    for(int l_index = -1 ; l_index >= l_min && p_sheeps.find(pair<unsigned int,unsigned int>(p_x + l_index,p_y - l_index)) == p_sheeps.end() ; l_index--)
      {
	p_result.insert(pair<unsigned int,unsigned int>(p_x + l_index,p_y - l_index));
      }
    for(int l_index = 1 ; l_index <=l_max && p_sheeps.find(pair<unsigned int,unsigned int>(p_x + l_index,p_y - l_index)) == p_sheeps.end() ; l_index++)
      {
	p_result.insert(pair<unsigned int,unsigned int>(p_x + l_index,p_y - l_index));
      }
  }

  const std::string sheep_situation_analyzer::m_class_name = "sheep_situation_analyzer";
  
}
//EOF
