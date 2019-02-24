#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "powerOfTwo.h"
#include "graph.h"


int main(int argc, char *argv[])
{
	//computeTwoToTheN();
	struct Graph* graph;
	graph = createGraph();

	printGraph(graph);

	deleteGraph(graph);

	return 0;
}

