#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<stdbool.h>
# define MAX_VERTICES 1000
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
        /*G->Adj[0][1] = G->Adj[1][0] = 1;
        G->Adj[0][2] = G->Adj[2][0] = 1;
	 G->Adj[1][3] = G->Adj[3][1] = 1;
        G->Adj[1][4] = G->Adj[4][1] = 1;
        G->Adj[1][5] = G->Adj[5][1] = 1;
        G->Adj[1][6] = G->Adj[6][1] = 1;
        G->Adj[6][2] = G->Adj[2][6] = 1;*/

        return G;
}


void Graph_BFS(struct Graph* G)
{	int s=0;
        // Mark all the vertices as not visited
        bool visited[MAX_VERTICES];
        for (int i = 0; i < G->V; i++) {
                visited[i] = false;
        }

        // Create a queue for BFS
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue[rear++] = s;

        while (front != rear) {

                // Dequeue a vertex from queue and print it
                s = queue[front++];

                printf("%d ", s);

                // Get all adjacent vertices of the dequeued
                // vertex s.
                // If an adjacent has not been visited,
                // then mark it visited and enqueue it
                for (int adjacent = 0; adjacent < G->V;
                        adjacent++) {
                        if (G->Adj[s][adjacent] && !visited[adjacent]) {
                                visited[adjacent] = true;
                                queue[rear++] = adjacent;
                        }
                }
        }

}
void Graph_parallel_BFS(struct Graph* G)
{       int s=0;
        // Mark all the vertices as not visited
        bool visited[MAX_VERTICES];
        for (int i = 0; i < G->V; i++) {
                visited[i] = false;
        }

        // Create a queue for BFS
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue[rear++] = s;

        while (front != rear) {

                // Dequeue a vertex from queue and print it
                s = queue[front++];

                printf("%d ", s);

                // Get all adjacent vertices of the dequeued
                // vertex s.
                // If an adjacent has not been visited,
                // then mark it visited and enqueue it
		# pragma omp for
                for (int adjacent = 0; adjacent < G->V;
                        adjacent++) {
                        if (G->Adj[s][adjacent] && !visited[adjacent]) {
                                visited[adjacent] = true;
                                queue[rear++] = adjacent;
                        }
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

        printf("\n\nSerial BFS Traversal\n\n");

        double start_time = omp_get_wtime();
        Graph_BFS(G);
        double end_time = omp_get_wtime();
        printf("\n\nTime taken for serial bfs traversal is : %f seconds \n\n",end_time - start_time);
	printf("\n\nParallel BFS Traversal\n\n");
        start_time = omp_get_wtime();
        Graph_parallel_BFS(G);
        end_time = omp_get_wtime();

        printf("\n\nTime taken for parallel bfs traversal is : %f seconds \n\n",end_time - start_time);
        return 0;
}

