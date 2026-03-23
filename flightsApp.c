#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"


struct AVLNode* loadFlights(char *fileName);
struct AVLNode* insertFlight(struct AVLNode* t, char *destination, char *airline, char type, char *date, int miles);
void infoFlights(struct AVLNode* t, char *destination);
void displayFlights(struct AVLNode* t);
struct Flight* findFurthestDestination(struct AVLNode* t);
void FurthestDestinations(struct AVLNode* t, struct Flight* highestMilesFlight);

int main (int argc, char **argv){

    struct AVLNode* myTree = NULL;
    int menuOption, flag = 1;

    if(argc == 1){
        printf("Please provide a file name: ");
        return 0;
    }

    myTree = loadFlights(argv[1]);

    printf("Welcome to data analysis @ Istanbul Airport\n");

    while (flag){
        printf("\n-------Menu-------\n"
               "(1)Insert flight\n"
               "(2)Display the full index of flights\n"
               "(3)Display the details of the flight\n"
               "(4)Display the furthest destination\n"
               "(5)Exit\n"
               "Enter your option:");
        scanf("%d", &menuOption);

        switch (menuOption) {

            case 1:{
                char destination[50], airline[50], type, date[11];
                int miles;

                printf("Please enter flight details:\n");
                printf("Destination: ");
                scanf(" %s", destination);
                printf("Airline: ");
                scanf(" %s", airline);
                printf("Type: ");
                scanf(" %c", &type);
                printf("Date: ");
                scanf(" %s", date);
                printf("Miles: ");
                scanf("%d", &miles);

                myTree = insertFlight(myTree, destination, airline, type, date, miles);
                printf("%s %s has been added successfully.\n", airline, destination);
                break;
            }
            case 2:{
                displayFlights(myTree);
                break;
            }
            case 3:{
                char destination[50];
                printf("Destination: ");
                scanf(" %s", destination);
                infoFlights(myTree,destination);
                break;
            }
            case 4:{
                printf("Detailed information of the furthest destination:\n");
                FurthestDestinations(myTree, findFurthestDestination(myTree));
                break;
            }
            case 5: {
                flag = 0;
                break;
            }
            default:{
                printf("Option %d can't be recognized.\n", menuOption);
            }
        }
    }

    myTree = MakeEmptyTree(myTree);
    return 0;
}

struct AVLNode* insertFlight(struct AVLNode* t, char *destination, char *airline, char type, char *date, int miles) {
    struct Flight* f = (struct Flight*)malloc(sizeof(struct Flight));

    strcpy(f->destination, destination);
    strcpy(f->airline, airline);
    f->type = type;
    strcpy(f->date, date);
    f->miles = miles;
    f->next = NULL;

    return InsertFlight(t, f);
}

struct AVLNode* loadFlights(char *fileName){
    FILE* fp = fopen(fileName, "r");//We just need to read
    char line[256];

    struct AVLNode* t = CreateTree();

    if(fp == NULL)
        return t;//If file does not open return empty Tree

    while(fgets(line, sizeof(line), fp) != NULL){
        char *destination, *airline, *type, *date, *miles;

        destination = strtok(line, ";");
        airline = strtok(NULL, ";");
        type = strtok(NULL, ";");
        date = strtok(NULL, ";");
        miles = strtok(NULL, ";\n");//with \n we are going to another line

        if(destination != NULL && airline != NULL && type != NULL && date != NULL && miles != NULL){
            //if all variables are full then insert it
            t = insertFlight(t, destination, airline, type[0], date, atoi(miles));
        }
    }

    fclose(fp);
    return t;
}

void displayFlights(struct AVLNode* t){
    DisplayTree(t);
}

void infoFlights(struct AVLNode* t, char *destination){
    struct Flight* f = FindDestination(t, destination);

    if(f == NULL){//if dest have not found
        printf("There is no available flight whose destination is %s.\n", destination);
        return;
    }

    while(f != NULL){
        PrintFlightDetails(f);
        f = f->next;
    }
    /*Complexity Discussion
      - Searching is O(logN) where N is different Nodes in the tree
      - Writing is O(K) where K is the number of flights for same destination
      - Totally it is O(logN + K)
      - If K is very big, complexity will grow very fast. We can use max-heap to prevent this instead of linked list

    Possible improvement:
      Flights for the same destination are currently stored in a linked list.
      This list can be replaced with a balanced search tree to reduce the
      linear dependency on K and improve performance for large datasets*/

}

struct Flight* findFurthestDestination(struct AVLNode* t){
    if(t == NULL)
        return NULL;

    struct Flight* maxFlight = NULL;//I am using it to hold the maximum mile of the flights

    struct Flight* leftMax = findFurthestDestination(t->left);
    if(leftMax != NULL)
        maxFlight = leftMax;// maximum of the left side of the tree is now maxFlight

    struct Flight* rightMax = findFurthestDestination(t->right);//controlling right for max
    if(rightMax != NULL && (maxFlight == NULL || rightMax->miles > maxFlight->miles))
        maxFlight = rightMax;//if greater than current then it is maxFlight now

    struct Flight* cur = t->data;
    while(cur != NULL){
        if(maxFlight == NULL || cur->miles > maxFlight->miles)
            maxFlight = cur;//now cur is max since it is greater
        cur = cur->next;
    }

    return maxFlight;
}

void FurthestDestinations(struct AVLNode* t, struct Flight* highestMilesFlight){
    if(t == NULL || highestMilesFlight == NULL)
        return;

    FurthestDestinations(t->left, highestMilesFlight);

    struct Flight* cur = t->data;
    while(cur != NULL){
        if(cur->miles == highestMilesFlight->miles)
            PrintFlightDetails(cur);
        cur = cur->next;
    }

    FurthestDestinations(t->right, highestMilesFlight);
    /* Time complexity is O(N + M) where N is the number of AVL nodes
     * and M is the total number of flights
     * For possible improvement each node can store maximum value of its subtree
     * so subtrees that cannot contain flights with the maximum miles can be skipped,
     * which reduces the time complexity to O(logN+K) where K is the number of flights with greates miles*/

}
