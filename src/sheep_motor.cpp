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
#include "sheep_motor.h"

#include <string>
using namespace std;

namespace sheep
{

  //-----------------------------------------------------------------------------
  const string & sheep_motor::get_class_name(void)const
  {
    return m_class_name;
  }

  //-----------------------------------------------------------------------------
  sheep_situation & sheep_motor::run(const sheep_situation & p_situation,
				     const sheep_transition & p_transition)
  {
    sheep_situation & l_result = *(new sheep_situation());
    map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter = p_situation.get_sheeps().begin();
    map<pair<unsigned int, unsigned int>,bool >::const_iterator l_iter_end = p_situation.get_sheeps().end();
    while(l_iter != l_iter_end)
      {
	if(l_iter->first != p_transition.get_source())
	  {
	    l_result.add_sheep(l_iter->first,l_iter->second);
	  }
	else
	  {
	    l_result.add_sheep(p_transition.get_target(),l_iter->second);
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

  const std::string sheep_motor::m_class_name = "sheep_motor";
}
//EOF
