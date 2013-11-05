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
#ifndef _SHEEP_CONTEXT_H_
#define _SHEEP_CONTEXT_H_

#include "FSM_context.h"
#include "sheep_transition.h"

#include <set>

namespace sheep
{
  class sheep_context:public FSM_base::FSM_context<sheep_transition>
  {
  public:
    sheep_context(void);

    // Methods inherited from interface
    const std::string to_string(void)const;
    void to_string(std::string &)const;

    // Specific methods

  private:
  };
}
#endif // _SHEEP_CONTEXT_H_
//EOF
