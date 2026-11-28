#include "yaxiong.h"
#include "dijkstra.h"

# define MAX_ARCS 100 // TODO: Replace with actual variable

void yaxiong(Graph graph){
    // Step 1: Set initial solution
    for (int i = 0; i < graph.amountOfArcs; i++){
        graph.arcArray[i].flow = 0;
        graph.arcArray[i].yaxR = graph.arcArray[i].length;
        graph.arcArray[i].yaxWeight = 0;
    }

    // Initial arc (s,t), doesn't matter which since all are unfeasible.
    Arc currArc = graph.arcArray[0];
    // Step 2: Check status of arcs (in while loop condition)
    while (currArc.flow == 0) {
        // Step 3: Form cycle and change flow
        // Get shortest path from s to t
        Arc* path[MAX_ARCS];
        int pathSize = dijkstra(path);
        // Cycle created by shortestPath(s,t) + (t,s)

        // Change flow for each arc in cycle. +1 flow if arc follows direction of (t,s), -1 flow if not
        // currArc gets +1 flow always
        currArc.flow++;
        // Change flow for rest of the arcs in cycle
        Node* previousNodePtr = currArc.nodeTo;
        for (int i = 0; i < pathSize; i++){
            // If the arc goes FROM the previous node, it follows the directions of (t,s)
            if (path[i]->nodeFrom == previousNodePtr){
                path[i]->flow++;
                previousNodePtr = path[i]->nodeTo;
            } 
            // If the arc goes TO the previous node, it's going against the direction of (t,s)
            else if (path[i]->nodeTo == previousNodePtr){
                path[i]->flow--;
                previousNodePtr = path[i]->nodeFrom;
            } 
            
            else {
                printf("Yaxiong error: Shortest path is not continuous");
                return;
            }
        }

        // Step 4: Calculate arc values
        Arc unfeasibleArc;
        for (int i = 0; i < graph.amountOfArcs; i++){
            Arc iterArc = graph.arcArray[i];
            // R(i,j) = min{d(i), d(t)} + R(i, j) - min{d(j), d(t)};
            int iDelta = fmin(iterArc.nodeFrom->distFromSrc, currArc.nodeFrom->distFromSrc);
            int jDelta = fmin(iterArc.nodeTo->distFromSrc, currArc.nodeFrom->distFromSrc);
            iterArc.yaxR = iDelta + iterArc.yaxR - jDelta;

            // Adjust weight according to flow
            switch (iterArc.flow)
            {
            case 0:
                iterArc.yaxWeight = 0;
                iterArc.residualWeight = false;
                // Save an unfeasible arc for later
                unfeasibleArc = iterArc;
                break;
            case 1:
                iterArc.yaxWeight = iterArc.yaxR;
                iterArc.residualWeight = false;
                break;
            default:
                iterArc.yaxWeight = 0;
                iterArc.residualWeight = true;
                break;
            }
        }
        // Also part of step 2, pick new unfeasible arc
        currArc = unfeasibleArc;
    }
}