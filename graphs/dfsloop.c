#include<stdio.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

typedef struct AdjListNode ADJLISTNODE;

struct AdjList
{
    struct AdjListNode *head;

};

typedef struct AdjList ADJLIST;

struct Graph
{
    int V;
    struct AdjList* array;
};

typedef struct Graph GRAPH;

void depthFirstSearch(GRAPH* graph);
void DFS(int i);
//int isExhausted(ADJLISTNODE *node);

ADJLISTNODE* newAdjListNode(int dest)
{
    ADJLISTNODE *newNode;
    newNode = (ADJLISTNODE*) malloc (sizeof(ADJLISTNODE));

    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


GRAPH* createGraph(int V)
{
    GRAPH *graph;
    graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->V = V;

    graph->array = (ADJLIST*)malloc(V * sizeof(ADJLIST));

    int i;

    //Initilize each Adjacency list as empty by making head as NULL;
    for(i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;

}



void addEdge(GRAPH *graph, int src, int dest)
{
    ADJLISTNODE *newNode  = newAdjListNode(dest);

    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //do opposite too
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void printGraph(GRAPH* graph)
{
    int v;

    for(v = 0; v < graph->V; ++v)
    {
        ADJLISTNODE *crawl;

        crawl = graph->array[v].head;

        printf("\nList of vertex %d\n head",v);

        while(crawl)
        {
            printf("->%d",crawl->dest);
            crawl = crawl->next;
        }

        printf("\n");
    }
}

int visitedArray[8] = {0,0,0,0,0,0,0,0};

int main()
{

        int V = 8;
        struct Graph* graph = createGraph(V);

        //create the graph


        /*
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 4);
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 1, 4);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        */


        addEdge(graph, 0 ,1);
        addEdge(graph, 0 ,3);
        addEdge(graph, 0 ,6);

        addEdge(graph, 1, 5);
        addEdge(graph, 1, 4);

        addEdge(graph, 2, 5);
        addEdge(graph, 2, 7);

        addEdge(graph, 3, 5);
        addEdge(graph, 3, 7);

        addEdge(graph, 4, 6);


    depthFirstSearch(graph);
    return 0;
}


void depthFirstSearch(GRAPH *graph)
{



    int stack[8];

    ADJLISTNODE *crawl;

    int top = 0;
    stack[top] = 0; //initial vertex
    //printf("%d->",stack[top]);
    visitedArray[0] = 1;
    int count = graph->V - 1;
    int i;

  //  printf("%d",count);
    while(count)
    {

        crawl = graph->array[stack[top]].head;

        while(visitedArray[crawl->dest] == 1 && crawl)
        {

            crawl = crawl->next;

        }

        top++;

        stack[top] = crawl->dest;
        visitedArray[crawl->dest] = 1;

      /*
        if(isExhausted(graph->array[stack[top]].head))
        {
          top--;
        }
      */
        count--;

    }


    for(i = 0; i < graph->V; i++)
        printf("%d->",stack[i]);


        printf("\n");


    for(i = 0; i < graph->V; i++)
        printf("%d->",visitedArray[i]);


}

/*int isExhausted(ADJLISTNODE *node)
{

  while(visitedArray[node->dest] == 1)
    {
      node = node -> next;
      if(node == NULL)
        return 1;
      else
        return 0;
    }
} */
