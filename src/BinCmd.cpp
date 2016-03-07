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

#include "BinCmd.h"		// included files and libraries

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

BinCmd::BinCmd(const string& c, const vector<string>& a)	// sets command and argument list
{
    cmd = c;
    args = a;
}

int BinCmd::execute()
{
	string path = "/bin/";		// creates proper path for bin commands
	path.append(cmd);
	const char* transfer = path.c_str();
		
	const size_t size = args.size();		// creates new array to transfer to execvp
	char** argArray = new char*[ size + 1 ];

	for( size_t i = 0; i < size; i++ )
	{
		argArray[i] = strdup(args[i].c_str());
	}
	argArray[size] = 0;

	pid_t childPid;				// forking process to create child processes
	int chkFork = ( childPid = fork() );
	if( chkFork == -1 )				// error checking for all system calls
		perror("Error - Fork Failed");

	if( childPid >= 0 )
	{
		if( childPid == 0 )
		{
			int chkExe = ( execvp(transfer, argArray) );
			if( chkExe == -1 )
			{
				perror("Error - Execution Failed");
				//return false;				
				exit(1);	
			}
		}
		else
		{
			int chkWait = ( wait(NULL) );
			if( chkWait == -1)
			{
				perror("Error - Wait Failed");
				//return false;
			}
    		}	
	}
	
	if( errno == 0)		// return success of failure
	{

		return false;
	}
	else
	{

		return true;
	}

}
