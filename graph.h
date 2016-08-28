#ifndef _GRAPH_H
#define _GRAPH_H

#include "biclstr.h"

//typedef short discrete;

typedef struct Edge{
	int row1;
	int row2;
	int weight;
} Edge;

struct dStack{
  int top;             /* top element index */
  int items[];		   /* data storage */
};

Edge **edgeL;
Edge *edgeP;

static int calc_edge_weight (const int *c1, const int *c2);

#endif
