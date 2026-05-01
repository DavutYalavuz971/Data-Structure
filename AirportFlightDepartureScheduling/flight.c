//
//
//

#include "flight.h"

//This function will create a dynamically allocated flight with random values and return its address.
Flight * createRandomFlight(int maxReadyTime, int maxServiceTime){
    //To be completed
}

//This function gets a flights address and prints its values.
void printFlightInformation(Flight* flight){
    if(flight != NULL){
        printf("%c %2d %2d %2d %2d %3s %4s\n", flight->flightType, flight->readyTime, flight->serviceTime, flight->serviceStartTime, flight->runwayNumber, flight->airline, flight->destination);
    }
}
