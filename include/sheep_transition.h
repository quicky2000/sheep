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
#ifndef _SHEEP_TRANSITION_
#define _SHEEP_TRANSITION_

#include "FSM_transition_if.h"
#include <utility>

namespace sheep
{
  class sheep_transition: public FSM_interfaces::FSM_transition_if
  {
  public:
    // Constructors && Destructors
    sheep_transition(const std::pair<unsigned int,unsigned int> & p_source,
		     const std::pair<unsigned int,unsigned int> & p_target);
    ~sheep_transition(void);
  
    // Methods inherited from interface
    const std::string to_string(void)const;
    void to_string(std::string &)const;
  
    // Dedicated methods
    const std::pair<unsigned int ,unsigned int> & get_source(void)const;
    const std::pair<unsigned int ,unsigned int> & get_target(void)const;
  
  private:
    std::pair<unsigned int ,unsigned int> m_source;
    std::pair<unsigned int ,unsigned int> m_target;
  };
}
#endif // _SHEEP_TRANSITION_ 
//EOF
