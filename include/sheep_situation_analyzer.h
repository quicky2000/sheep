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
#ifndef _SHEEP_SITUATION_ANALYZER_
#define _SHEEP_SITUATION_ANALYZER_

#include "FSM_situation_analyzer.h"
#include "sheep_situation.h"
#include "sheep_transition.h"

namespace sheep
{
  class sheep_situation_analyzer: public FSM_base::FSM_situation_analyzer<sheep_situation,sheep_transition>
    {
    public:
      // Constructors and Destructors
      sheep_situation_analyzer(void);
      ~sheep_situation_analyzer(void);
  
      // Methods inherited from FSM_situation_analyzer
      const std::string & get_class_name(void)const;
      std::vector<const sheep_transition*> & get_transitions(sheep_situation & p_situation);

      // Specific methods
      void get_reachable_positions(std::set<std::pair<unsigned int, unsigned int> > & p_result,
				   const unsigned int & p_x,
				   const unsigned int & p_y,
				   const std::map<std::pair<unsigned int, unsigned int>,bool > & p_sheeps);

    private:
      static const std::string m_class_name;
    };
}
#endif // _SHEEP_SITUATION_ANALYZER_ 
//EOF
