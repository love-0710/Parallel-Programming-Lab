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
