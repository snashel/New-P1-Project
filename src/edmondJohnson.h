#ifndef P1_EDMONDJOHNSON_H
#define P1_EDMONDJOHNSON_H

#include <functions.h>

void edmondJohnson(Graph stronglyConnectedDigraph);
bool isEvenDegree(Graph digraph, Node** positiveDegreeNodes, Node** negativeDegreeNodes, int* oddDegreeNodeAmount);
void setFlowToOne(Graph digraph);
void circulation_problem(Graph stronglyConnectedDigraph);
int eulerianTourLength(Graph digraph);


#endif //P1_EDMONDJOHNSON_H
