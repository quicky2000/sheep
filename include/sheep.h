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
#ifndef _SHEEP_BASE_H_
#define _SHEEP_BASE_H_

#include "FSM.h"
#include "sheep_situation.h"
#include "sheep_transition.h"
#include "sheep_context.h"

namespace sheep
{
  class sheep:public FSM_base::FSM<sheep_situation,sheep_transition>
    {
    public:
      // Constructors && Destructors
      sheep(void);
      ~sheep(void);

      // Methods inherited from FSM
      void configure(void);
      const std::string & get_class_name(void)const;

    private:
      static const std::string m_class_name;
    };
}
#endif // _SHEEP_BASE_H_
//EOF
