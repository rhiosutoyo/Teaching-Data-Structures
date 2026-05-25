#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// parent array stores representative parent
int parent[15] = {0};

// rank array stores tree height
int rank[15] = {0};

/*
	makeset()

	Create initial independent sets

	Example:
	{0} {1} {2} {3} {4}
*/
void makeset(int vCount){
	for(int i=0;i<vCount;i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

/*
	swap()

	Exchange two integers
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
	find_set()

	Find representative parent

	Using Path Compression

	Example:

	Before:
	0 -> 1 -> 2

	After:
	0 ----\
	1 ----- > 2
	2 ----/
*/
int find_set(int vertex){

	// root found
	if(vertex == parent[vertex]){
		return vertex;
	}

	// path compression
	return parent[vertex] = find_set(parent[vertex]);
}

/*
	union_sets()

	Merge two groups using
	Union by Rank
*/
void union_sets(int vertexA, int vertexB){

	// find representative of set A
	vertexA = find_set(vertexA);

	// find representative of set B
	vertexB = find_set(vertexB);

	// merge only if different groups
	if(vertexA != vertexB){

		// keep larger rank as root
		if(rank[vertexA] < rank[vertexB]){
			swap(&vertexA, &vertexB);
		}

		// attach smaller tree
		parent[vertexB] = vertexA;

		// increase rank if equal
		if(rank[vertexA] == rank[vertexB]){
			rank[vertexA]++;
		}
	}
}

/*
	isSameSet()

	Check whether two vertices
	belong to same set
*/
bool isSameSet(int vertexA, int vertexB){

	return find_set(vertexA) ==
		   find_set(vertexB);
}

int main(){

	// create initial sets
	// {0} {1} {2} {3} {4}

	makeset(5);

	/*
	union_sets(0,1)

	Result:
	    0
	   /
	  1
	*/
	union_sets(0,1);

	/*
	union_sets(1,2)

	Result:
	    0
	   / \
	  1   2
	*/
	union_sets(1,2);

	/*
	union_sets(3,4)

	Result:
	    3
	   /
	  4
	*/
	union_sets(3,4);

	// check whether 0 and 2
	// belong to same set
	if(isSameSet(0,2)){
		printf("0 & 2 ada di set yang sama\n");
	}else{
		printf("0 & 2 tidak ada di set yang sama\n");
	}

	// check whether 0 and 3
	// belong to same set
	if(isSameSet(0,3)){
		printf("0 & 3 ada di set yang sama\n");
	}else{
		printf("0 & 3 tidak ada di set yang sama\n");
	}

	return 0;
}