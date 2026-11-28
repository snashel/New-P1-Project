#include "yaxiong.h"
#include "dijkstra.h"

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
        // Step 3: Form cycle
        // Get shortest path from t to s

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