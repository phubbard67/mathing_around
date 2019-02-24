#include <stdio.h>
#include <stdlib.h>
#include "powerOfTwo.h"
#include "graph.h"


int main(int argc, char *argv[])
{
	computeTwoToTheN();
	int ** graph = createGraph();

	graph[0][1] = 23;

	printf("graph[0][1]: %d\n", graph[0][1]);

	return 0;
}

