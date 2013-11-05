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
#include "sheep_transition.h"

#include <sstream>

namespace sheep
{
  //-----------------------------------------------------------------------------
  sheep_transition::sheep_transition
  (
   const std::pair<unsigned int,unsigned int> & p_source,
   const std::pair<unsigned int,unsigned int> & p_target
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
  const std::string sheep_transition::to_string(void)const
  {
    std::stringstream l_result;
    l_result << "Source = (" << m_source.first << " , " << m_source.second << ")\tTarget(" << m_target.first << " , " << m_target.second << ")";
    return l_result.str();
  }

  //-----------------------------------------------------------------------------
  void sheep_transition::to_string(std::string & p_result)const
  {
    std::stringstream l_result;
    l_result << "Source = (" << m_source.first << " , " << m_source.second << ")\tTarget(" << m_target.first << " , " << m_target.second << ")";
    p_result = l_result.str();
  }

  //-----------------------------------------------------------------------------
  const std::pair<unsigned int ,unsigned int>& sheep_transition::get_source(void)const
  {
    return m_source;
  }

  //-----------------------------------------------------------------------------
  const std::pair<unsigned int ,unsigned int>& sheep_transition::get_target(void)const
  {
    return m_target;
  }
}
//EOF
