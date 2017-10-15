#include "linktable.h"
#include <stdlib.h>
#include<stdio.h>

tLinkTable * CreateLinkTable() 
{
    tLinkTable * pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	if(pLinkTable == NULL)
    {
    	return NULL;
	}
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    return pLinkTable;
}


int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode) 
{
    if(pLinkTable->SumOfNode == 0)
    {
    	pLinkTable->pHead = pNode;
    	pLinkTable->pTail = pNode;
    	pLinkTable->SumOfNode ++;
    	pNode->pNext=NULL;
    	return 0;
	}
    pLinkTable->pTail->pNext = pNode;
    pLinkTable->pTail = pNode;
    pNode->pNext = NULL;
    pLinkTable->SumOfNode ++;
    return 0;
}

int DelLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if (pLinkTable->SumOfNode == 0)
	{
		printf("LinkTable is NULL");
		exit(0);
	}
	tLinkTableNode *q = pLinkTable->pHead;
	if (q == pNode)
	{
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		free(pNode);
		return 0;
	}
	while(q->pNext!=pNode)
	{
		q = q->pNext;
	}
	tLinkTableNode *r = q->pNext;
	q->pNext = r->pNext;
	free(r);
	return 0;
}

tLinkTableNode * GetLinkTableHead(tLinkTable *LinkTable) 
{
	return LinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode * pNode)
{
    return pNode->pNext;
}
 
 
 
 
 
 
 
