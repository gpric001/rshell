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


BinCmd::BinCmd(const string& c, const vector<string>& a)
{
    cmd = c;
    args = a;
};

int BinCmd::execute()
{
	string path = "/bin/";
	path.append(c);
	const char* transfer = path.c_str();

	pid_t childPid;
	childPid = fork();

	if( childPid >= 0 )
	{
		if( childPod == 0 )
		{
			execvp(transfer, args);
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
