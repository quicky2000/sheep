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
#include "sheep.h"
#include "sheep_motor.h"
#include "sheep_situation_analyzer.h"

#include <iostream>
using namespace std;

namespace sheep
{
  //-----------------------------------------------------------------------------
  sheep::sheep(void):
    FSM<sheep_situation,sheep_transition>("sheep",
					  *(new sheep_motor()), *(new sheep_situation_analyzer()))
  {
    set_situation(*(new sheep_situation()));
    get_situation().add_sheep(pair<unsigned int,unsigned int>(0,0),true);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(1,0),true);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(2,0),true);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(3,0),true);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(0,4),false);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(1,4),false);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(2,4),false);
    get_situation().add_sheep(pair<unsigned int,unsigned int>(3,4),false);

    sheep_situation::init_final_situation();
  }

  //-----------------------------------------------------------------------------
  sheep::~sheep(void)
  {
  }

  //-----------------------------------------------------------------------------
  void sheep::configure(void)
  {
  }

  //-----------------------------------------------------------------------------
  const string & sheep::get_class_name(void)const
  {
    return m_class_name;
  }

  //-----------------------------------------------------------------------------
  FSM_interfaces::FSM_if & create_sheep(void)
  {
    return *(new sheep());
  }

  //-----------------------------------------------------------------------------
  extern "C"
  {
    void register_fsm(map<string,FSM_interfaces::FSM_creator_t> & p_factory)
    {
      register_fsm("sheep",create_sheep,p_factory);
    }

  }
  const std::string sheep::m_class_name = "sheep";
}
//EOF
