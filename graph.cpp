#include "graph.h"

/////////////////////////////////////graph functions
//this creates the graph with width (w) and height (h)
struct Graph* createGraph()
{
  char *uHeight = (char*) malloc(sizeof(char*));
  char *uWidth = (char*) malloc(sizeof(char*));
  struct Graph *graphStruct = (struct Graph*) malloc(sizeof(struct Graph*));
  int h, w;

  printf("Please enter the height for the graph: ");
  scanf("%s", uHeight);
  printf("Please enter a width for the graph: ");
  scanf("%s", uWidth);

  h = atoi(uHeight);
  w = atoi(uWidth);

  int * values = static_cast<int*>(calloc(h*w, sizeof(int)));
  int ** graph = static_cast<int**>(malloc(h*sizeof(int*)));

  for(int i = 0; i<h; ++i)
  {
	graph[i] = values + i*w;
  }

  graphStruct->graph = graph;
  graphStruct->height = h;
  graphStruct->width = w;


  randGraphGen(graphStruct, h, w);



  free(uHeight);
  free(uWidth);
	
  return graphStruct;
}

//this deletes the graph 
void deleteGraph(struct Graph* graph)
{
	free(*graph->graph);
	free(graph->graph);
	free(graph);
}


//this populates the graph with random values
//0 being a clear vertex and 1 being blocked
int randGraphGen(struct Graph* graph, int h, int w)
{ 
	srand(time(0));
	int randBit;

	//nest this in a do while loop that has the while condition
	//set to the return from the BFS

	for(int i = 0; i < h; ++i)
	{
		for(int j = 0; j < w; ++j)
		{
			if((j == 0 && i == 0) || (j == w - 1 && i == h - 1))
			{
				graph->graph[i][j] = 0;
			}
			else
			{
				randBit = rand() % 4;
				switch(randBit)
				{
					case 0:
						randBit = 0;
						break;
					case 1:
						randBit = 0;
						break;
					case 2:
						randBit = 0;
						break;
					case 3:
						randBit = 1;
						break;
				}
				graph->graph[i][j] = randBit;
			}
		}
	}
	return 0;
}
//this is the BFS function that returns the shortest path
int BFS(struct Graph* graph)
{ 

	return 0;
}

//print the graph in ascii art
void printGraph(struct Graph* graph)
{
	for(int i = 0; i < (graph->height); ++i)
	{
		for(int j = 0; j < (graph->width); ++j)
		{
			printf("%d ", graph->graph[i][j]);
		}
		printf("\n");
	}
}


//check to see if the position is in the graph's bounds
bool inBounds(struct Graph* graph, int posX, int posY)
{
	int gHeight = graph->height;
	int gWidth  = graph->width;

	if(posX >= 0 && posY >= 0 && posX < gHeight && posY < gWidth)
		return true;

	return false;
}














