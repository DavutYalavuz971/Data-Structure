#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"


struct AVLNode* CreateTree(void){
    return NULL;
}

struct AVLNode* MakeEmptyTree(struct AVLNode* t)
{
    if(t == NULL)
        return NULL;

    t->left = MakeEmptyTree(t->left);
    t->right = MakeEmptyTree(t->right);

    struct Flight* f = t->data;
    while(f != NULL){
        struct Flight* temp = f;
        f = f->next;
        free(temp);
    }

    free(t);
    return NULL;
}

struct AVLNode* InsertFlight(struct AVLNode* t, struct Flight* flight){
    if(t == NULL){
        struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
        node->data = flight;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
        return node;
    }

    int cmp = strcmp(flight->destination, t->data->destination);

    if(cmp < 0){//Using strcmp returning
        t->left = InsertFlight(t->left, flight);
    }
    else if(cmp > 0){
        t->right = InsertFlight(t->right, flight);
    }
    else{//It is equal
        struct Flight* cur = t->data;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = flight;
        return t;
    }

    t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;

    int balance = AVLTreeHeight(t->left) - AVLTreeHeight(t->right);

    if(balance > 1){
        if(strcmp(flight->destination, t->left->data->destination) < 0)
            return SingleRotateWithRight(t);
        else
            return DoubleRotateWithLeft(t);
    }
    if(balance < -1){
        if(strcmp(flight->destination, t->right->data->destination) > 0)
            return SingleRotateWithLeft(t);
        else
            return DoubleRotateWithRight(t);
    }

    return t;
}

//right rotation
struct AVLNode*  SingleRotateWithRight(struct AVLNode*  k2)
{
    struct AVLNode* k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = Max(AVLTreeHeight(k2->left), AVLTreeHeight(k2->right)) + 1;
    k1->height = Max(AVLTreeHeight(k1->left), AVLTreeHeight(k1->right)) + 1;

    return k1;
}

//left rotation
struct AVLNode*  SingleRotateWithLeft(struct AVLNode*  k1)
{
    struct AVLNode* k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = Max(AVLTreeHeight(k1->left), AVLTreeHeight(k1->right)) + 1;
    k2->height = Max(AVLTreeHeight(k2->left), AVLTreeHeight(k2->right)) + 1;

    return k2;
}

//left and right rotation
struct AVLNode*  DoubleRotateWithLeft(struct AVLNode*  k3)
{
    k3->left = SingleRotateWithLeft(k3->left);
    return SingleRotateWithRight(k3);
}

// right and left rotation
struct AVLNode*  DoubleRotateWithRight(struct AVLNode* k3)
{
    k3->right = SingleRotateWithRight(k3->right);
    return SingleRotateWithLeft(k3);
}

int Max(int x, int y)
{
    if(x > y)
        return x;
    return y;
}

int AVLTreeHeight(struct AVLNode* t)
{
    if(t == NULL)
        return -1;
    return t->height;
}

void DisplayTree(struct AVLNode* t)
{
    if(t == NULL)
        return;

    DisplayTree(t->left);

    struct Flight* cur = t->data;
    while(cur != NULL){
        PrintFlightDetails(cur);
        cur = cur->next;
    }

    DisplayTree(t->right);
}

void PrintFlightDetails(struct Flight* flight){
    printf("%s %s %c %s %d\n",
           flight->destination,
           flight->airline,
           flight->type,
           flight->date,
           flight->miles);
}

struct Flight* FindDestination(struct AVLNode *t, char *destination){
    if(t == NULL)
        return NULL;

    int cmp = strcmp(destination, t->data->destination);

    if(cmp == 0)
        return t->data;
    else if(cmp < 0)
        return FindDestination(t->left, destination);
    else
        return FindDestination(t->right, destination);
}


