//
// Copyright (C) 2011 Juan Luis Garrote Molinero
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __RELAYRSTP_ACCESS_H
#define __RELAYRSTP_ACCESS_H


#include "ModuleAccess.h"
#include "RelayRSTP.h"


/**
 * @brief Gives access to RelayRSTP module
 */
class RelayRSTPAccess : public ModuleAccess<RelayRSTP>
{
    public:
    	 RelayRSTPAccess() : ModuleAccess<RelayRSTP>("relay") {}
};

#endif
