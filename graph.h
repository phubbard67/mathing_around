#include <stdio.h>
#include <stdlib.h>

//graph info obtained at 
//https://www.geeksforgeeks.org/graph-and-its-representations/

//structs for the list
struct AdjListNode;
struct AdjList;
struct Graph;

//graph functions
struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V); 
