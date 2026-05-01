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
    //To be completed
}

struct AVLNode* loadFlights(char *fileName){
    //To be completed
}

void displayFlights(struct AVLNode* t){
    //To be completed
}

void infoFlights(struct AVLNode* t, char *destination){
    //To be completed
}

struct Flight* findFurthestDestination(struct AVLNode* t){
    //To be completed
}

void FurthestDestinations(struct AVLNode* t, struct Flight* highestMilesFlight){
    //To be completed
}
