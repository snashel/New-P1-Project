#include "eulerTour.h"

/*
 *  1. Select any vertex in Graph and denote it by v*
 *  2. Form an intree T that spans Graph and that is rooted at v*
 *  3. For each vertex w in Graph, w != v*
 *      Label the out-arcs from w randomly with consecutive integers,
 *      subject to the restriction that the last (highest) label is given
 *      to the arc in intree T.
 *  4. Label the out-arcs from v* arbitrarily.
 *  5. Starting at vertex v*, trace an eulerian tour in Graph by always selecting the
 *  untraversed out-arc with the smallest label.
 *
 *
 *  An easy way to form an intree T of digraph Graph is to start with T = {v*}
 *  and proceed iteratively: select at each iteration an arc in Graph that is directed
 *  from a vertex in V(G) - V(T) to a vertex in T; repeat until T spans Graph.
 *
 **/
void euler_tour(Graph graph) { // Currently missing return type and test functionality.

    short labelCount; // loops around n shit

    // 1. Select random starting node
    Node* startNode = &graph.nodeArray[rand() % graph.amountOfNodes];

    // 2. Form an intree inTree
    startNode->isUsedInTree = true;
    construct_intree(startNode);

    // 3. Label the out arcs from w randomly with cons. ints.
    for (int i = 0; i < graph.amountOfNodes; i++) {
        Node* tempNode = &graph.nodeArray[i];
        labelCount = 0;
        for (int j = 0; j < tempNode->amountArcsOut; j++) {
            if (tempNode->arcsOut[j]->isUsedInTree) { // 4.
                tempNode->arcsOut[j]->inTreeLabel = tempNode->amountArcsOut;
            } else {
                labelCount++;
                tempNode->arcsOut[j]->inTreeLabel = labelCount;
            }
        }
    }


}

void construct_intree(Node* startNode) {
    for (int i = 0; i < startNode->amountArcsIn; i++) {
        Node* newNode = startNode->arcsIn[i]->nodeFrom; // Select at each iteration a directed arch from a
        if (newNode->isUsedInTree) {
            continue;
        } else {
            newNode->isUsedInTree = true;
            startNode->arcsIn[i]->isUsedInTree = true;
            construct_intree(newNode);
        }
    }
}


