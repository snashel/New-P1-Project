#ifndef P1_FUNCTIONS_H
#define P1_FUNCTIONS_H

#include "eulerTour.h"
#include "dijkstra.h"
#include "edmondJohnson.h"
#include "graphGen.h"
#include "yaxiong.h"

#define MAX_ARCS 4

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node Node;
typedef struct arc Arc;

typedef struct {
    Node* nodeArray;
    Arc* arcArray;
    int amountOfNodes;
    int amountOfArcs;

} Graph;

struct node {
    Arc* arcsIn[MAX_ARCS];
    Arc* arcsOut[MAX_ARCS];
    short balance;
    unsigned short distFromSrc;
    short yaxP;
    unsigned short amountArcsIn;
    unsigned short amountArcsOut;
    bool isUsedInTree;
};

struct arc {
    Node* nodeFrom;
    Node* nodeTo;
    unsigned short length;
    unsigned short flow;
    short yaxWeight;
    int yaxR;
    bool isUsedInTree;
    bool residualWeight;
};

void run_program();

#endif //P1_FUNCTIONS_H

