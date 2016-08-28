#include "graph.h"

static int calc_edge_weight (const int *c1, const int *c2)
{
	int weight = 0;
	int i;
	for (i=0;i<rows;i++)
	{
		if (*c1==*c2 && (*c1!=0)) 
			weight++;
		c1++; 
		c2++;
	}
	return weight;
}

 //#define AllocArray(pt, size) (pt = xmalloc(sizeof(*pt) * (size)))

void create_graph()
{
	int i, j;
	i = cols*(cols-1)/2;
	edgeL = malloc(sizeof(*edgeL)*(i));

	struct fibheap *heap;
	heap = fh_makeheap();

	for (i = 0; i < cols; i++)
	{
		for (j = i+1; j < cols; j++)
		{
			edgeP = malloc(sizeof(*edgeP));
			edgeP -> gene_one = i;
			edgeP -> gene_two = j;
			edgeP -> score = cnt;	


}