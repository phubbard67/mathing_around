/*
 * queue.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Paul
 *      code ideas derived from
 *      https://en.wikipedia.org/wiki/Lee_algorithm
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

//a struct to represent the location in the matrix
struct Location{
	int x;
	int y;
};

//A node for the queue
struct QNode{
	//count holding how many steps that have been taken through the graph
	//up to this point
	int count;
	//struct holding the nodes position
	Location location;
};

#endif /* QUEUE_H_ */
