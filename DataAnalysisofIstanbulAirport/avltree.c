#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"


struct AVLNode* CreateTree(void){
    //To be completed
}

struct AVLNode* MakeEmptyTree(struct AVLNode* t)
{
    //To be completed
}

struct AVLNode* InsertFlight(struct AVLNode* t, struct Flight* flight){
//To be completed
}

//right rotation
struct AVLNode*  SingleRotateWithRight(struct AVLNode*  k2)
{
    //To be completed
}

//left rotation
struct AVLNode*  SingleRotateWithLeft(struct AVLNode*  k1)
{
    //To be completed
}

//left and right rotation
struct AVLNode*  DoubleRotateWithLeft(struct AVLNode*  k3)
{
    //To be completed
}

// right and left rotation
struct AVLNode*  DoubleRotateWithRight(struct AVLNode* k3)
{
    //To be completed
}

int Max(int x, int y)
{
    //To be completed
}

int AVLTreeHeight(struct AVLNode* t)
{
    //To be completed
}

void DisplayTree(struct AVLNode* t)
{
    //To be completed
}

void PrintFlightDetails(struct Flight* flight){
    //To be completed
}

struct Flight* FindDestination(struct AVLNode *t, char *destination){
    //To be completed
}
