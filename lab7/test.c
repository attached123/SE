#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <unistd.h>
#include <getopt.h>

int Quit(int argc,char *argv[])
{
	int opt;
	while((opt=getopt(argc,argv,"a")) != -1)
	{
		printf("opt=%c/n",opt);
	}
	exit(0);
}

int Add(int argc, char* argv[])
{
	
    int i,r;
    if(argc !=3)
    {
        printf("warning input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])+atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}

int main(int argc,char* argv[])
{
	MenuConfig("add","Add two numbers", Add);
	MenuConfig("version","menu Version1.3",NULL);
	MenuConfig("quit","Quit from menu",Quit);
	ExecuteMenu();
}
