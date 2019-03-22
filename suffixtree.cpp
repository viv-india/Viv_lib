#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256
 /*******************************************the Skeleton************************************************************/
struct Node {
    struct Node *children[MAX_CHAR];
    struct Node *suffixLink;
    int start;
    int *end;
    int suffixIndex;
};
/*************************************The great chunk of variables**************************************************/
string text; //Input string
Node *root = NULL; //Pointer to root node
Node *lastNewNode = NULL;
Node *activeNode = NULL;
int activeEdge = -1;
int activeLength = 0;
int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1; //Length of input string
/******************************************Function giving new node*************************************************/ 
Node *newNode(int start, int *end)
{
    Node *node =(Node*) malloc(sizeof(Node));
    int i;
    for (i = 0; i < MAX_CHAR; i++)
          node->children[i] = NULL;
    node->suffixLink = root;
    node->start = start;
    node->end = end;
    node->suffixIndex = -1;
    return node;
}
/*****************************************Baccha function*********************************************************/ 
int edgeLength(Node *n) {
    return *(n->end) - (n->start) + 1;
}
/*******************Function to decide creation of inner new node************************************************/
bool walkDown(Node *currNode)
{  if (activeLength >= edgeLength(currNode))
    {
        activeEdge += edgeLength(currNode);
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}
/**************************************The real function********************************************************/ 
void extendSuffixTree(int pos)
{  leafEnd = pos;
   remainingSuffixCount++;
   lastNewNode = NULL;
   while(remainingSuffixCount > 0) {
       if (activeLength == 0)
            activeEdge = pos; //APCFALZ
       if (activeNode->children[text[activeEdge]] == NULL)
        {  activeNode->children[text[activeEdge]] = newNode(pos, &leafEnd);
            if (lastNewNode != NULL)
            {  lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;}}
        else
        {  Node *next = activeNode->children[text[activeEdge]];
            if (walkDown(next))    continue;
            if (text[next->start + activeLength] == text[pos])
            {  if(lastNewNode != NULL && activeNode != root)
                {  lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;}
                   activeLength++;
                   break;}
            splitEnd = (int*) malloc(sizeof(int));
            *splitEnd = next->start + activeLength - 1;
            Node *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;
            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;
            if (lastNewNode != NULL)
            lastNewNode->suffixLink = split;
            lastNewNode = split;
        }
        remainingSuffixCount--;
        if (activeNode == root && activeLength > 0) //APCFER2C1
        {   activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;}
        else if (activeNode != root) //APCFER2C2
            activeNode = activeNode->suffixLink; }}
/*********************************************simple query[don't mind :) ]*********************************************************/ 
void print(int i, int j)
{
    int k;
    for (k=i; k<=j; k++)
        printf("%c", text[k]);
}
/************************************************                                  ***************************************************/
void setSuffixIndexByDFS(Node *n, int labelHeight)
{   if (n == NULL)  return;
    if (n->start != -1) //A non-root node
        print(n->start, *(n->end));
    int leaf = 1;
    for (int i = 0; i < MAX_CHAR; i++)
    { if (n->children[i] != NULL)
        { if (leaf == 1 && n->start != -1)
            printf(" [%d]\n", n->suffixIndex);
            leaf = 0;
            setSuffixIndexByDFS(n->children[i], labelHeight + edgeLength(n->children[i]));   }    }
    if (leaf == 1)
    { n->suffixIndex = size - labelHeight;
        printf(" [%d]\n", n->suffixIndex);}
}
/**************************************************                                        ******************************************/ 
void freeSuffixTreeByPostOrder(Node *n)
{ if (n == NULL)  return;
    for (int i = 0; i < MAX_CHAR; i++)
        if (n->children[i] != NULL)
         freeSuffixTreeByPostOrder(n->children[i]);
    if (n->suffixIndex == -1)
        free(n->end);
    free(n);}
/*****************************************The function to just call other functions :P*************************************/
void buildSuffixTree()
{   size =text.size();
    rootEnd = (int*) malloc(sizeof(int));
    *rootEnd = - 1;//set rootEnd as any invalid index
    root = newNode(-1, rootEnd);
    activeNode = root; //First activeNode will be root
    for (int i=0; i<size; i++)
    extendSuffixTree(i);
    setSuffixIndexByDFS(root,0);
    freeSuffixTreeByPostOrder(root);               }
/*********************************************************you know this guy****************************************************/
int main()
{cout<<"Enter text to be preprocessed\n";
cin>>text;
text=text+"$";
buildSuffixTree();//here we go

    return 0;
}
