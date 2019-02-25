#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <queue>
#include "myQueue.h"

//struct to hold graph info
typedef struct Graph
{
	int ** graph;
	int width;
	int height;
}Graph;
/////////////////////////////////////graph functions
//this creates the graph with width (w) and height (h)
//provided by the user
struct Graph* createGraph();
//this populates the graph with random values
//0 being a clear vertex and 1 being blocked
int randGraphGen(struct Graph* graph, int h, int w);
//this is the BFS function that returns the shortest path
int BFS(struct Graph* graph);
//delete the graph you made
void deleteGraph(struct Graph* graph);
//print the graph in ascii art
void printGraph(struct Graph* graph);
//check to see if the position is in the graph's bounds
bool inBounds(struct Graph* graph, int posX, int posY);
//initialize a bool graph to keep track of the
//visited positions to all 0's
void initBoolGraph(struct Graph* boolGraph);
