#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "powerOfTwo.h"
#include "graph.h"


int main(int argc, char *argv[])
{
	//computeTwoToTheN();
	struct Graph* graph;
	int shortestPathDist;
	graph = createGraph();

	 printf("The Graph, where 1 is blocked, and 0 is clear");
	 printGraph(graph);

	//no need to worry about a false return from BFS
	//the randGraphGen already checks to make sure
	//there is a path from start to finish
	shortestPathDist = BFS(graph, true);

	printf("The shortest distance from graph[0][0] to graph[%d - 1][%d - 1]: %d\n", graph->height, graph->width, shortestPathDist);

	deleteGraph(graph);

	return 0;
}

