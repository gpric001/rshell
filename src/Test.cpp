/*	Copyright (C) 2016 Authors: Gutherie Price, Mathew Schaffrath

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


#include "Test.h"

#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

Test::Test(const string& c, const vector<string>& a)
{
	cmd = c;
	args = a;	
}

int Test::execute()
{
	string dotAdd = ".";
	struct stat buf;
	
	if( args.size() == 2)
	{
	string temp1 = args[1];
	dotAdd.append(temp1);
	const char* path = dotAdd.c_str();

		if( stat( path, &buf ) == 0 )
		{
			cout << "(True)" << endl;
			return true;
		}
		else if( stat( path, &buf ) == -1 )
		{
			cout << "(False)" << endl;
			return false;
		}
	}
	else if ( args.size() == 3)
	{
	string temp2 = args[2];
	dotAdd.append(temp2);
	const char* path = dotAdd.c_str();

	stat( path, &buf );

		if( args[1] == "-d" )
		{
			if( stat( path, &buf ) == 0 && S_ISDIR(buf.st_mode) )
			{
				cout << "(True)" << endl;
				return true;
			}
			else
			{
				cout << "(False)" << endl;
				return false;
			}
		}
		else if( args[1] == "-e" )
		{
			if ( stat( path, &buf ) == 0 )
			{
				cout << "(True)" << endl;
				return true;
			}
			else
			{
				cout << "(False)" << endl;
				return false;
			}
		}
		else if( args[1] == "-f" )
		{
			if ( stat( path, &buf ) == 0 && S_ISREG(buf.st_mode) )
			{
				cout << "(True)" << endl;
				return true;
			}
			else
			{
				cout << "(False)" << endl;
				return false;
			}

		}

	}
return 0;
}






 
