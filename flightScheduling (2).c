#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "queue.h"

// To parse input from program arguments
void parseInput(char **, int *, int *, int *, int *);

// To initialise, create and populate the flight list with random flight data
List createFlightList(int, int, int);

//To initialise queue of the arrived flights and runway availability data
int* initialiseSimulator(Queue*, int);

//Adds the arrived flight into the priority queue
void newFlight(Flight*, Queue);

//Randomly assign an available runway to the flight
void serveFlight(Flight*, int*, int);

//Print the statistical data of the simulation run
void reportStatistics(List, int, int, int);

//Clear dynamically allocated memories
void exitFromTheSimulation(List, Queue, int *);

int main(int argc, char *argv[])
{
    //To be completed
    return 0;
}

void parseInput(char *programArguments[], int *noOfFlights, int *noOfRunways, int *maxReadyTime, int *maxServiceTime){
    //To be completed
}

List createFlightList(int numberOfFlights, int maxReadyTime, int maxServiceTime){
    //To be completed
}

int* initialiseSimulator(Queue* flightQueue, int noOfRunways){
    //To be completed
}

void newFlight(Flight* flightData,Queue flightQueue){
    //To be completed
}

// int *runways is the runway array
void serveFlight(Flight* flightData, int* runways, int runwayNumber){
    //To be completed
}

void reportStatistics(List flightsDataList, int noOfRunways, int numberOfFlights, int clockTime){
    //To be completed
}

void exitFromTheSimulation(List flightList, Queue flightQueue, int *flightData){
    //To be completed
}