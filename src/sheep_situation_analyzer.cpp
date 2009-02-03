#include "sheep_situation_analyzer.h"

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
string sheep_situation_analyzer::toString(void)
{
  return "sheep_situation_analyzer";
}

//-----------------------------------------------------------------------------
vector<sheep_transition*> sheep_situation_analyzer::getTransitions
(
 sheep_situation* p_situation
 )
{
  assert(p_situation != NULL);
  vector<sheep_transition*> l_result;
  const map<pair<unsigned int, unsigned int>,bool > &l_sheeps = p_situation->getSheeps();

  map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter = l_sheeps.begin();
  map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter_end = l_sheeps.end();

  // Store which positionis blocked bqnd who is blocking
  map<pair<unsigned int, unsigned int>,unsigned char > l_blocked_positions;
  
  // loop which cover all sheeps
  while(l_iter != l_iter_end)
    {
      int l_x = l_iter->first.first;
      int l_y = l_iter->first.second;
      //COMMENT_OUTPUT      cout << endl <<  "Sheep ( " << l_x << " , " << l_y << " ) = " << (l_iter->second?"N":"B") << endl ;

      // Compute reachable positions
      set<pair<unsigned int,unsigned int> > l_reachable_positions;
      getReachablePositions(l_reachable_positions,l_x,l_y,l_sheeps);
	
      // Build corresponding transitions and store reachable positions
      set<pair<unsigned int,unsigned int> >::const_iterator l_iter_reachable = l_reachable_positions.begin();
      set<pair<unsigned int,unsigned int> >::const_iterator l_iter_reachable_end = l_reachable_positions.end();
      while(l_iter_reachable != l_iter_reachable_end)
	{
	  map<pair<unsigned int, unsigned int>,unsigned char >::iterator l_blocked_iter = l_blocked_positions.find(*l_iter_reachable);
	  if(l_blocked_positions.end() == l_blocked_iter)
	    {
	      l_blocked_positions.insert(map<pair<unsigned int,unsigned int>, unsigned char>::value_type(*l_iter_reachable,l_iter->second+1));
	    }
	  else
	    {
	      l_blocked_iter->second |= l_iter->second+1;
	    }
	  l_result.push_back(new sheep_transition(l_iter->first,*l_iter_reachable));
	  //COMMENT_OUTPUTcout << "X = " << l_iter_reachable->first << "\tY = " << l_iter_reachable->second << endl;
	  ++l_iter_reachable;
	}
      ++l_iter;
    }

  // Analysing transitions to remove invalid
  vector<sheep_transition*>::const_iterator l_result_iter = l_result.begin();
  vector<sheep_transition*>::const_iterator l_result_iter_end = l_result.end();
  vector<sheep_transition*> *l_real_result = new vector<sheep_transition*>();
  while(l_result_iter != l_result_iter_end)
    {
      bool l_valid = true;
      //check validity of transition
      map<pair<unsigned int, unsigned int>,unsigned char >::iterator l_blocked_iter = l_blocked_positions.find((*l_result_iter)->getTarget());
      if(l_blocked_positions.end() != l_blocked_iter)
	{
	  // Check that the position is blocked by a sheep of the same colour
	  map<pair<unsigned int, unsigned int>,bool >::const_iterator l_sheep_iter = l_sheeps.find((*l_result_iter)->getSource());
	  assert(l_sheeps.end() != l_sheep_iter);
	  l_valid = (l_sheep_iter->second+1 == l_blocked_iter->second);
	}
      if(l_valid)
	{
	  l_real_result->push_back(*l_result_iter);
	}
      ++l_result_iter;
    }
  return *l_real_result;
}

//-----------------------------------------------------------------------------
void sheep_situation_analyzer::getReachablePositions(set<pair<unsigned int, unsigned int> > & p_result,unsigned int p_x,unsigned int p_y,const map<pair<unsigned int, unsigned int>,bool > &p_sheeps)
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
