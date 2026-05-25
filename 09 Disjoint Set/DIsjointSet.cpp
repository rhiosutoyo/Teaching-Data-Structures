/*  FUNCTION IN DISJOINT SET

	makeSet()     = create initial groups
	findParent()  = find group representative
	join()        = merge two groups
	isSameSet()   = check whether two vertices are in the same group
*/

/*  EXECUTION VISUALIZATION

	Initial:
	{0} {1} {2} {3} {4}

	join(0,1)
	0 -> 1

	join(1,2)
	0 -> 1 -> 2

	join(3,4)
	3 -> 4

	Final groups:
	{0,1,2}
	{3,4}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>   // needed for bool type

// parent array stores the representative (parent) of each vertex
// index = vertex number
// value = parent of that vertex
int parent[15] = {0};

/*
	makeSet()

	Purpose:
	Initialize all vertices so that each vertex belongs
	to its own set.

	Example:
	makeset(5)

	Before:
	parent = [0,0,0,0,0]

	After:
	parent = [0,1,2,3,4]

	Sets become:
	{0} {1} {2} {3} {4}
*/
void makeset(int vCount){
	for(int i=0;i<vCount;i++){
		parent[i] = i;
	}
}

/*
	findParent()

	Purpose:
	Find the representative (root parent)
	of a vertex's set.

	Example structure:

	0 -> 1 -> 2
	         ^
	         root

	findParent(0)

	Process:
	findParent(0)
	-> findParent(1)
	-> findParent(2)
	-> return 2

	Result:
	0 belongs to set represented by vertex 2
*/
int findParent(int vertex){

	// if vertex is its own parent,
	// it means this is the root node
	if(parent[vertex]==vertex){
		return vertex;
	}

	// keep moving upward until root is found
	return findParent(parent[vertex]);
}

/*
	join()

	Purpose:
	Merge two sets.

	Example:

	Initially:
	{0} {1} {2}

	join(0,1)

	Becomes:
	0 -> 1

	join(1,2)

	Becomes:
	0 -> 1 -> 2

	Set:
	{0,1,2}
*/
void join(int vertexA, int vertexB){

	// find root parent of vertexA
	int parentVA = findParent(vertexA);

	// find root parent of vertexB
	int parentVB = findParent(vertexB);

	// connect parent of set A
	// to parent of set B
	parent[parentVA] = parentVB;
}

/*
	isSameSet()

	Purpose:
	Check whether two vertices belong
	to the same set.

	Example:

	0 -> 1 -> 2

	3 -> 4

	isSameSet(0,2)
	true

	isSameSet(0,4)
	false
*/
bool isSameSet(int vertexA,int vertexB){

	// compare root parent of both vertices
	return findParent(vertexA) == findParent(vertexB);
}

int main(){

	// create 5 independent sets
	// {0} {1} {2} {3} {4}
	makeset(5);

	/*
	join(0,1)

	parent:
	0 -> 1

	Sets:
	{0,1}
	{2}
	{3}
	{4}
	*/
	join(0,1);

	/*
	join(1,2)

	parent:
	0 -> 1 -> 2

	Sets:
	{0,1,2}
	{3}
	{4}
	*/
	join(1,2);

	/*
	join(3,4)

	parent:
	3 -> 4

	Final sets:
	{0,1,2}
	{3,4}
	*/
	join(3,4);

	// check whether 0 and 2
	// belong to the same set
	if(isSameSet(0,2)){
		// TRUE because:
		// findParent(0) = 2
		// findParent(2) = 2
		printf("0 & 2 ada di set yang sama\n");

	}else{
		// FALSE if root parents differ
		printf("0 & 2 tidak ada di set yang sama\n");
	}

	// check whether 0 and 4
	// belong to the same set
	if(isSameSet(0,3)){
		// TRUE because:
		// findParent(0) = 2
		// findParent(3) = 4
		printf("0 & 4 ada di set yang sama\n");

	}else{
		// FALSE if root parents differ
		printf("0 & 4 tidak ada di set yang sama\n");
	}

	return 0;
}
