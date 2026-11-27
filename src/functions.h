#ifndef P1_FUNCTIONS_H
#define P1_FUNCTIONS_H

#define MAX_ARCS 4

#include <stdbool.h>

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
    int length;
    int flow;
    int yaxWeight;
    int yaxR;
    bool isCleared;
    bool isUsedInTree;
    bool residualWeight;
};

void run_program();

#endif //P1_FUNCTIONS_H

