#include<stdio.h>
#include<stdlib.h>
int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"help") == 0)
        {
            printf("This is help cmd!\n");
        }
        else if(strcmp(cmd,"quit") == 0)
	{
	    exit(0);
	}
	else if(strcmp(cmd,"others") == 0)
	{
 	    printf("others\n");
	}
	else if(strcmp(cmd,"echo") == 0)
	{
	    printf("%s\n",cmd);
	}
	else if(strcmp(cmd,"back") == 0)
	{
	    continue;
	}
	else if(strcmp(cmd,"amounts") == 0)
	{
	    printf("amounts = 8\n");
	}
	else if(strcmp(cmd,"change") == 0)
	{
	    printf("change\n");
	}
	else if(strcmp(cmd,"open") == 0)
	{
	    printf("open\n");
	}   
        else
        {
 	    printf("Wrong cmd!\n");
	}
   }
}
