#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int vis[1000];

struct Graph {
	int V;
	int** Adj;
};

struct Graph* adjMatrix(long int vertices)
{
	struct Graph* G = (struct Graph*)
		malloc(sizeof(struct Graph));
	if (!G) {
		printf("Memory Error\n");
		return NULL;
	}
	G->V = vertices;

	G->Adj = (int**)malloc((G->V) * sizeof(int*));
	for (int k = 0; k < G->V; k++) {
		G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
	}

	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			if( u != v ){ 
				G->Adj[u][v] = 1;
			}
			else{
				G->Adj[u][v] = 0;
			}
		}
	}
	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			printf("%d  ",G->Adj[u][v]);
		}
		printf("\n");
	}
	/*G->Adj[0][1] = G->Adj[1][0] = 1;
	G->Adj[0][2] = G->Adj[2][0] = 1;
	G->Adj[1][3] = G->Adj[3][1] = 1;
	G->Adj[1][4] = G->Adj[4][1] = 1;
	G->Adj[1][5] = G->Adj[5][1] = 1;
	G->Adj[1][6] = G->Adj[6][1] = 1;
	G->Adj[6][2] = G->Adj[2][6] = 1;*/

	return G;
}

void DFS(struct Graph* G, int u)
{
	vis[u] = 1;
	printf("%d ", u);
	for (int v = 0; v < G->V; v++) {
		if (!vis[v] && G->Adj[u][v]) {
			DFS(G, v);
		}
	}
}

void DFStraversal(struct Graph* G)
{
	for (int i = 0; i < 1000; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < G->V; i++) {
		if (!vis[i]) {
			DFS(G, i);
		}
	}
}
void DFStraversalParallel(struct Graph* G)
{
	for (int i = 0; i < 1000; i++) {
		vis[i] = 0;
	}
	#pragma omp parallel for
	for (int i = 0; i < G->V; i++) {
		if (!vis[i]) {
			DFS(G, i);
		}
	}
}

int main()
{
	struct Graph* G;
	long int vertices;
	printf("Enter the number of vertices : ");
	scanf("%ld",&vertices);
	G = adjMatrix(vertices);

	printf("\nSERIAL DFS TRAVERSAL RESULT\n");

	double start_time = omp_get_wtime();
	DFStraversal(G);
	double end_time = omp_get_wtime();
	printf("Time taken for serial dfs traversal is : %f secs \n",end_time - start_time);
	start_time = omp_get_wtime();
	DFStraversal(G);
	end_time = omp_get_wtime();

	printf("Time taken for parallel dfs traversal is : %f secs \n",end_time - start_time);
	return 0;
}

