#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

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
int populateGraph(struct Graph* graph, int h, int w);
//this is the BFS function that returns the shortest path
int BFS(int ** graphArray);
//delete the graph you made
void deleteGraph(struct Graph* graph);
//print the graph in ascii art
void printGraph(struct Graph* graph);
