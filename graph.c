#include "graph.h"

/////////////////////////////////////graph functions
//this creates the graph with width (w) and hieght (h)
int **createGraph()
{
  char *uHeight = (char*) malloc(sizeof(char*));
  char *uHeightWidth = (char*) malloc(sizeof(char*));
  char *uWidth = (char*) malloc(sizeof(char*));
  int h, w, i;

  printf("Please enter the hieght and width for the graph in the form 'h w': ");
  scanf("%s", uHeightWidth);
  const char * newUHeightWidth = uHeightWidth;

  i = 0;
  while(newUHeightWidth[i] != ' ')
  {
    uHeight[i] = uHeightWidth[i];
    ++i;
  }

  i += 1;

  while(uHeightWidth[i] != NULL)
  {
    uWidth[i] = uHeightWidth[i];
    ++i;
  }

  h = atoi(uHeight);
  w = atoi(uWidth);

  int * values = calloc(h*w, sizeof(int));
  int ** graph = malloc(h*sizeof(int*));

  for(int i = 0; i<h; ++i)
  {
	graph[i] = values + i*w;
  }

  free(uHeight);
  free(uWidth);
  free(uHeightWidth);
	
  return graph;
}

//this deletes the graph 
void deleteGraph(int ** graph)
{
	free(*graph);
	free(graph);
}


//this populates the graph with random values
//0 being a clear vertex and 1 being blocked
int populateGraph(int **graphArray)
{ 
	return 0;
}
//this is the BFS function that returns the shortest path
int BFS(int **graphArray)
{ 
	return 0;
}





















