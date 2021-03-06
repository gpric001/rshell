/*  Copyright (C) 2016  Authors: Guthrie Price, Mathew Schaffrath

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program under the filename LICENSE.
    If not, see <http://www.gnu.org/licenses/>.

    This program comes with ABSOLUTELY NO WARRANTY.     */
    
#ifndef Connector_H
#define Connector_H

using namespace std;

#include "CommandComponent.h"

class Connector : public CommandComponent
{
    protected:
        CommandComponent* childL;
        CommandComponent* childR;
        
    public:
        virtual int execute() = 0;
        
        Connector(CommandComponent* c1, CommandComponent* c2)
        {
            childL = c1;
            childR = c2;
        }

};

#endif
