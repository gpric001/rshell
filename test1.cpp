#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
using namespace std;

int global; /* In BSS segement, will automatically be assigned '0'*/

int main()
{
    pid_t child_pid;
    int status;
    int local = 0;
    /* now create new process */
    child_pid = fork();
    pid_t wp;

    if (child_pid >= 0) /* fork succeeded */
    {
        if (child_pid == 0) /* fork() returns 0 for the child process */
        {
            printf("child process!\n");

            // Increment the local and global variables
            local++;
            global++;

            printf("child PID =  %d, parent pid = %d\n", getpid(), getppid());
            printf("\n child's local = %d, child's global = %d\n",local,global);

			char temp[] = {'l','s'};
            char* cmd[] = {temp,NULL};
            return execvp("/home/ubuntu/workspace/CS100/bin/ls.exe", cmd);// call command //return
         }
         else /* parent process */
         {
             printf("parent process!\n");
             printf("parent PID =  %d, child pid = %d\n", getpid(), child_pid);

             //wp = waitpid(child_pid, &status, WNOHANG);
             
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("Child exit code: %d\n", WEXITSTATUS(status));

             //The change in local and global variable in child process should not reflect here in parent process.
             printf("\n Parent'z local = %d, parent's  global = %d\n",local,global);

             printf("Parent says bye!\n");
             exit(0);  /* parent exits */
         }
    }
    else /* failure */
    {
        perror("fork");
        exit(0);
        cout << "failure" <<endl;
    }
}

	
	/*
	string cmd;
	cout << "enter cmd" << endl;
	cin >> cmd;
	string complete = "~/workspace/CS100/bin/";
	complete.append(cmd);
	cout << complete << endl;
	complete.append(".exe");
	
	string begin = "source ";
	begin.append(complete);
	
	const char* path = begin.c_str();
	cout << path << endl;
	system(path);

	return 0;
	*/

