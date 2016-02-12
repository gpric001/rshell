#include "BinCmd.h"

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

BinCmd::BinCmd(const string& c, const vector<string>& a)
{
    cmd = c;
    args = a;
};

int BinCmd::execute()
{
	string path = "/bin/";
	path.append(cmd);
	const char* transfer = path.c_str();
		
	const size_t size = args.size();
	char** argArray = new char*[ size + 1 ];

	for( size_t i = 0; i < size; i++ )
	{
		argArray[i] = strdup(args[i].c_str());
	}
	argArray[size] = 0;

	pid_t childPid;
	childPid = fork();

	if( childPid >= 0 )
	{
		if( childPid == 0 )
		{
			execvp(transfer, argArray);
		}
		else
		{
			wait(NULL);
    		}
	}
	
	if( errno == 0)
		return 1;
	else
		return 0;

};
