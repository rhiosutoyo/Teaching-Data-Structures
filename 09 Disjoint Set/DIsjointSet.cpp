#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int parent[15] = {0};

void makeset(int vCount){
	for(int i=0;i<vCount;i++){
		parent[i] = i;
	}
}

int findParent(int vertex){
	if(parent[vertex]==vertex){
		return vertex;
	}
	return findParent(parent[vertex]);
}

void join(int vertexA, int vertexB){
	int parentVA = findParent(vertexA);
	int parentVB = findParent(vertexB);
	
	parent[parentVA] = parentVB;
}

bool isSameSet(int vertexA,int vertexB){
	return findParent(vertexA) == findParent(vertexB);
}

int main(){
	makeset(5);
	join(0,1);
	join(1,2);
	join(3,4);
	if(isSameSet(0,2)){
		printf("0 & 2 ada di set ayng sama");
	}else{
		printf("0 & 2 tidak ada di set yang sama");
	}
	return 0;
}
