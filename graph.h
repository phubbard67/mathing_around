#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//graph info obtained at
//https://www.geeksforgeeks.org/graph-and-its-representations/
/////////////////////////////////////struct

/////////////////////////////////////graph functions
//this creates the graph with width (w) and hieght (h)
//provided by the user
int **createGraph();
//this populates the graph with random values
//0 being a clear vertex and 1 being blocked
int populateGraph(int ** graphArray);
//this is the BFS function that returns the shortest path
int BFS(int ** graphArray);
//delete the graph you made
void deleteGraph(int ** graph);
