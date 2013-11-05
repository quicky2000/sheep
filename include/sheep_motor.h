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
#ifndef _SHEEP_MOTOR_H_
#define _SHEEP_MOTOR_H_

#include "FSM_motor.h"
#include "sheep_situation.h"
#include "sheep_transition.h"

namespace sheep
{
  class sheep_motor:public FSM_base::FSM_motor<sheep_situation,sheep_transition>
    {
    public:
      // Constructors and destructors
      sheep_motor(void);
      ~sheep_motor(void);
  
      // Methods inherited from FSM_motor
      const std::string & get_class_name(void)const;
      sheep_situation & run(const sheep_situation & p_situation,
			   const sheep_transition & p_transition);
    private:
      static const std::string m_class_name;
    };
}
#endif // _SHEEP_MOTOR_H_
//EOF
