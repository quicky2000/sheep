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
#ifndef _SHEEP_SITUATION_H_
#define _SHEEP_SITUATION_H_

#include "FSM_situation.h"
#include "sheep_context.h"

#include <set>
#include <map>

namespace sheep
{
  class sheep_situation:public FSM_base::FSM_situation<sheep_context>
  {
  public:
    // Constructors and destructors
    sheep_situation(void);
    ~sheep_situation(void);
  
    // Methods inherited from FSM_situation
    const std::string to_string(void)const;
    const std::string get_string_id(void)const;
    void to_string(std::string &)const;
    void get_string_id(std::string &)const;
    bool is_final(void)const;
    bool less(const FSM_situation_if *p_situation)const;
  
    // Dedicated methods
    void add_sheep(const std::pair<unsigned int, unsigned int> & p_sheep,
		   bool p_color);
    const std::map<std::pair<unsigned int, unsigned int>,bool >& get_sheeps(void)const;
    bool less(const sheep_situation *p_situation)const;
    static void init_final_situation(void);
  
  private:
    std::map<std::pair<unsigned int, unsigned int>,bool > m_sheeps;
    static std::map<std::pair<unsigned int, unsigned int>,bool > m_final_sheeps;
  };
}
#endif // _SHEEP_SITUATION_H_
//EOF
