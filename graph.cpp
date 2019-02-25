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
	int stop = 0;

	//nest this in a do while loop that has the while condition
	//set to the return from the BFS
	while(stop == 0)
	{
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
					randBit = rand() % 5;
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
						case 4:
							randBit = 1;
							break;
					}
					graph->graph[i][j] = randBit;
				}
			}
		}


		if(BFS(graph, false) != -1)
			stop = 1;
	}

	return 0;
}
//this is the BFS function that returns the shortest path
int BFS(struct Graph* graph, bool printShortstPath)
{ 
	struct Graph* boolGraph = (struct Graph*) malloc(sizeof(struct Graph*));
	boolGraph->height = graph->height;
	boolGraph->width = graph->width;
	initBoolGraph(boolGraph); //Initialize bool graph to all 0's
	struct Graph* graphToPrint = (struct Graph*) malloc(sizeof(struct Graph*));
	graphToPrint->height = graph->height;
	graphToPrint->width = graph->width;
	initBoolGraph(graphToPrint); //Initialize bool graph to all 0's
	std::queue<QNode> newQueue;
	QNode initNode;
	int leftDown = -1;
	int rightUp = 1;
	int row;
	int col; //ints to keep track of the adjacent rows
	int hasLesser; //used for checking the shortest path to print
	initNode.location.x = 0;
	initNode.location.y = 0;
	initNode.count = 0;

	//push the first node onto the queue
	//this does not require a check for zero,
	//because the graph will always have a 0 in the
	//first position
	newQueue.push(initNode);


	while(!newQueue.empty())
	{
		QNode curNode = newQueue.front();
		Location curLoc = curNode.location;

		if(curLoc.y == graph->width - 1 && curLoc.x == graph->height - 1)
		{
			if(printShortstPath)
			{
				//work backwards from the width - 1 and height - 1
				//if the graph has a value one lesser than it in any
				//direction, store that value into a new graph seperate
				//from the graphToPrint graph in its respective cell. This will be a new graph
				//that is initialized to zero, and as you find a new value one lesser than
				//the highest, find a way to move directly to that cell and start over.

					hasLesser = 0;
					int j = graphToPrint->width -1;
					int i = graphToPrint->height -1;

					while(i != 0 && j != 0)
					{
						if(j == graphToPrint->width - 1 && i == graphToPrint->height - 1)
						{
							hasLesser = 1;
						}
						//check left
						row = i - 1;
						col = j;

						if(inBounds(graph, row, col) && (graphToPrint->graph[i][j] = graphToPrint->graph[row][col]))
						{
							hasLesser = 1;
						}

						//check right
						row = i + 1;
						col = j;

						if(inBounds(graph, row, col) && (graphToPrint->graph[i][j] < graphToPrint->graph[row][col]))
						{
							hasLesser = 1;
						}

						//check up
						row = i;
						col = j + 1;

						if(inBounds(graph, row, col) && (graphToPrint->graph[i][j] < graphToPrint->graph[row][col]))
						{
							hasLesser = 1;
						}

						//check down
						row = i;
						col = j - 1;

						if(inBounds(graph, row, col) && (graphToPrint->graph[i][j] < graphToPrint->graph[row][col]))
						{
							hasLesser = 1;
						}

						if(hasLesser == 0)
						{
							graphToPrint->graph[i][j] = 0;
						}
						else
						{
							hasLesser = 0;
						}
					}

				printf("Every possible shortest path, with some potential overhang (trying to fix this).");
				graphToPrint->graph[0][0] = 0;
				printGraph(graphToPrint);
			}
			deleteGraph(boolGraph);
			deleteGraph(graphToPrint);
			return curNode.count;
		}
		else
			newQueue.pop();

		//check left
		row = curLoc.x;
		col = curLoc.y + leftDown;

		if(inBounds(graph, row, col) && graph->graph[row][col] == 0 && boolGraph->graph[row][col] == 0)
		{
			QNode left;
			left.location.x = row;
			left.location.y = col;
			left.count = curNode.count + 1;
			newQueue.push(left);
			graphToPrint->graph[row][col] = curNode.count + 1;
			boolGraph->graph[row][col] = 1;
		}

		//check right
		row = curLoc.x;
		col = curLoc.y + rightUp;

		if(inBounds(graph, row, col) && graph->graph[row][col] == 0 && boolGraph->graph[row][col] == 0)
		{
			QNode right;
			right.location.x = row;
			right.location.y = col;
			right.count = curNode.count + 1;
			newQueue.push(right);
			graphToPrint->graph[row][col] = curNode.count + 1;
			boolGraph->graph[row][col] = 1;
		}

		//check up
		row = curLoc.x + rightUp;
		col = curLoc.y;

		if(inBounds(graph, row, col) && graph->graph[row][col] == 0 && boolGraph->graph[row][col] == 0)
		{
			QNode up;
			up.location.x = row;
			up.location.y = col;
			up.count = curNode.count + 1;
			newQueue.push(up);
			graphToPrint->graph[row][col] = curNode.count + 1;
			boolGraph->graph[row][col] = 1;
		}

		//check down
		row = curLoc.x + leftDown;
		col = curLoc.y;

		if(inBounds(graph, row, col) && graph->graph[row][col] == 0 && boolGraph->graph[row][col] == 0)
		{
			QNode down;
			down.location.x = row;
			down.location.y = col;
			down.count = curNode.count + 1;
			newQueue.push(down);
			graphToPrint->graph[row][col] = curNode.count + 1;
			boolGraph->graph[row][col] = 1;
		}
	}

	deleteGraph(boolGraph);
	return -1;
}

//print the graph in ascii art
void printGraph(struct Graph* graph)
{
	//print an initial new line for spacing purposes
	printf("\n");

	for(int i = 0; i < (graph->height); ++i)
	{
		for(int j = 0; j < (graph->width); ++j)
		{
			printf("%d ", graph->graph[i][j]);
		}
		printf("\n");
	}
	//print a final new line for spacing purposes
	printf("\n");
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



void initBoolGraph(struct Graph* boolGraph)
{
	int * values = static_cast<int*>(calloc(boolGraph->height*boolGraph->width, sizeof(int)));
	int ** graph = static_cast<int**>(malloc((boolGraph->height)*sizeof(int*)));

	for(int i = 0; i<boolGraph->height; ++i)
	{
		graph[i] = values + i*boolGraph->width;
	}

	boolGraph->graph = graph;

	for(int i = 0; i < boolGraph->height; ++i)
	{
		for(int j = 0; j < boolGraph->width; ++ j)
		{
			boolGraph->graph[i][j] = 0;
		}
	}
}







