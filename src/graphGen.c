#include "graphGen.h"

Graph* create_sc_digraph(int amountOfNodes) {

    Graph* digraph = calloc(1,sizeof(Graph));

    if (digraph == NULL) {
        printf("ERROR ERROR EXPLODING PC \n");
        exit(EXIT_FAILURE);
    }

    digraph->amountOfNodes = amountOfNodes;

    spanning_tree(digraph, amountOfNodes);

    return digraph;

}

void add_arc(Graph* digraph, int nodeFrom, int nodeTo) {

    digraph->amountOfArcs++;

    Arc created_Arc


    digraph->nodeArray[nodeFrom].arcsOut = *created_edge;
    digraph->nodeArray[nodeFrom].balance--;

    digraph->nodeArray[nodeTo].arcsIn = *created_edge;
    digraph->nodeArray[nodeFrom].balance++;




}

void spanning_tree(Graph* digraph, int amountOfNodes) {

    /*
     *step 1 add node 0 to graph
     *step 2 add next node to graph
     *step 3 connect an arc from a previously added node to the node
     *step 4 repeat until all nodes have been added
     */

    digraph->nodeArray = calloc(amountOfNodes,sizeof(Node));

    for (int i = 1; i < amountOfNodes; i++) {

        int connectFrom;
        do {
            connectFrom = rand()%i;
        }while (digraph->nodeArray[connectFrom].amountArcsOut-1 > MAX_ARCS );

        add_arc(digraph,i,connectFrom);

    }
}


