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

#ifndef PARSER_H
#define PARSER_H
 
#include <string>
#include <vector>
#include <iterator>
#include <cstring>
#include <algorithm>

typedef std::vector<std::string> tokens;
class Parser{
    public:
        Parser();
        //Parses user input into groups on commands/connectors
        std::vector<tokens> parse(const std::string&);
        //Breaks a single token into multiple tokens
        void split(char*, std::string, tokens&);
        tokens sqrBrktHandler(tokens&);
};
#endif
