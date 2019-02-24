/*
 * queue.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Paul
 *      this code was taken from
 *      https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
typedef struct Queue
{
	int ** queue;
	int width;
	int height;
}Queue;

//creates the queue struct
struct Queue* createQueue(int h, int w);
//initializes the queue to all 0's or false
void initQueue(struct Queue* queue);
//checks to see if the location has been visited
//at a given height h and width w
int wasVisited(int ** queue, int h, int w);
//sets a given position to vistied
void setVisited(int ** queue, int h, int w);

#endif /* QUEUE_H_ */
