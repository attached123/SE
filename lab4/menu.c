#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linktable.h"
 
 
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
	tLinkTableNode *pNext;
	char* cmd;
	char* desc;
	int (*handler)();
} tDataNode;

int Help();
int Quit();

tDataNode * FindCmd(tLinkTable *linkTable, char * cmd)
{
    if(linkTable == NULL)
    {
    	return NULL;
	}
	
	tDataNode * pNode = (tDataNode *)GetLinkTableHead(linkTable);

	while (pNode != NULL)
    {
        if (strcmp(pNode->cmd,cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode *)GetNextLinkTableNode(linkTable, (tLinkTableNode *)pNode);
    }
    return NULL;
}
 
int ShowAllCmd(tLinkTable* linktable)
{
	tDataNode *pNode = (tDataNode*)GetLinkTableHead(linktable);	
	while(pNode != NULL)
	{
		printf("%s-%s\n",pNode->cmd,pNode->desc);
		pNode = (tDataNode*)GetNextLinkTableNode(linktable,(tLinkTableNode*)pNode);
	}
	return 0;
}

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();

    tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));

    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.3";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode); 

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.3";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    return 0;
}
 
 tLinkTable *linktable = NULL;
 
int main()
{
	InitMenuData(&linktable);
 	while(1)
 	{
 		char cmd[CMD_MAX_LEN];
 		printf("Input a cmd number > ");
 		scanf("%s",cmd);
 		tDataNode *p = FindCmd(linktable,cmd);
 		if(p == NULL)
 		{
 			printf("This is a wrong cmd!\n");
 			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->handler != NULL)
		{
			p->handler();
		}
	 }
}
 
int Help()
{
 	ShowAllCmd(linktable);
 	return 0;
}

int Quit()
{
    exit(0);
}
