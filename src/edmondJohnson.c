//
// Created by Frede on 27-11-2026.
//

#include "edmondJohnson.h"

void edmondJohnson(Graph stronglyConnectedDigraph) {
    int totalLength;


    // Creates two arrays for all nodes with positive or negative degree of arcs
    Node** positiveDegreeNodes = malloc(sizeof(Node*) * stronglyConnectedDigraph.amountOfNodes/2);
    Node** negativeDegreeNodes = malloc(sizeof(Node*) * stronglyConnectedDigraph.amountOfNodes/2);
    int oddDegreeNodeAmount = 0;


    //Check if the graph is of even degree (the same amount of in- and outdegree arcs for each node)
    if (isEvenDegree(stronglyConnectedDigraph, positiveDegreeNodes, negativeDegreeNodes, &oddDegreeNodeAmount)) {
        setFlowToOne(stronglyConnectedDigraph);
        //Perform eulerian tour
    }
    else {
        circulation_problem(stronglyConnectedDigraph);
        int* eulerianTour = malloc(sizeof(int) * eulerianTourLength(stronglyConnectedDigraph));
        //eulerianTour = eulerian_tour(stronglyConnectedDigraph, &totalLength); Perform eulerian tour
        free(eulerianTour);
    }

    free(positiveDegreeNodes);
    free(negativeDegreeNodes);
}

/**
 * This function updates the arrays with the positive or negative degree nodes and find the length of these (which would be the same)
 * @param digraph Directed graph with access to each node and the following in and out arcs
 * @param positiveDegreeNodes Array which gets updated with all nodes that has more arcs in
 * @param negativeDegreeNodes Array which gets updated with all nodes that has more arcs out
 * @param oddDegreeNodeAmount Amount of nodes with oddDegree for one of the types (as they would be the same)
 * @return If the digraph is of even-degree: return true, else false
 */
bool isEvenDegree(Graph digraph, Node** positiveDegreeNodes, Node** negativeDegreeNodes, int* oddDegreeNodeAmount) {
    int oddInDegreeNodeAmount = 0, oddOutDegreeNodeAmount = 0;

    for (int i = 0; i < digraph.amountOfNodes; i++) {
        if (digraph.nodeArray[i].amountArcsIn - digraph.nodeArray[i].amountArcsOut < 0) {
            negativeDegreeNodes[oddOutDegreeNodeAmount] = &digraph.nodeArray[i];
            oddOutDegreeNodeAmount++;
        }
        else if (digraph.nodeArray[i].amountArcsIn - digraph.nodeArray[i].amountArcsOut > 0) {
            positiveDegreeNodes[oddInDegreeNodeAmount] = &digraph.nodeArray[i];
            oddInDegreeNodeAmount++;
        }
    }
    *oddDegreeNodeAmount = oddOutDegreeNodeAmount;

    if (*oddDegreeNodeAmount == 0) {
        return true;
    }
    return false;
}

/**
 * Set the flow of each arc to 1
 * @param digraph A graph containing directed arcs with belonging flow
 */
void setFlowToOne(Graph digraph) {
    for (int i = 0; i < digraph.amountOfArcs; i++) {
        digraph.arcArray[i].flow = 1;
    }
}

/**
 * Sums the flow of all arcs in a directed graph
 * @param digraph A graph containing directed arcs with belonging flow
 * @return The total flow in the graph
 */
int eulerianTourLength(Graph digraph) {
    int totalFlow = 0;
    for (int i = 0; i < digraph.amountOfArcs; i++) {
        totalFlow += digraph.arcArray[i].flow;
    }
    return totalFlow;
}

void circulation_problem(Graph stronglyConnectedDigraph) {

}