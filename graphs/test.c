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


void depthFirstSearch(GRAPH);
void breadthFirstSearch(GRAPH);


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


int main()
{

    int V = 5;
    GRAPH *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    depthFirstSearch(graph);
    return 0;
}


/*void depthFirstSearch(GRAPH *graph)
{
  int visitedArray[5] = {0, 0, 0, 0, 0};
  int stack[5];

  ADJLISTNODE *crawl;

  stack[0] = 0;//push into stack
  visitedArray[0] = 1;//visit the node at top of stack

  crawl = graph->array[stack[0]].head;  //look at top of stack and Point to adjancent node
  while(visitedArray[crawl->dest] == 1 && crawl)//when that node is visited and not null
  {
    crawl = crawl->next;//point to next node as previous node is already visited
  }

  stack[1] = crawl->dest; //update top of stack to newly encountered node
  visitedArray[crawl->dest] = 1;//visit that node

  crawl = graph->array[stack[1]].head; //check for the adjacent nodes of the previously visited nodes(top of stack)

  while(visitedArray[crawl->dest] == 1 && crawl)
  {
    crawl = crawl->next;
  }

  stack[2] = crawl->dest;
  visitedArray[crawl->dest] = 1;

  crawl = graph->array[stack[2]].head;

  while(visitedArray[crawl->dest] == 1 && crawl)
  {
    crawl = crawl->next;

  }

  stack[3] = crawl->dest;
  visitedArray[crawl->dest] = 1;

  crawl = graph->array[stack[3]].head;

  while(visitedArray[crawl->dest] == 1 && crawl)
  {
    crawl = crawl->next;
  }

  stack[4] = crawl->dest;
  visitedArray[crawl->dest] = 1;

  int i;

  for(i = 0; i < 5; i++)
  {
    printf("%d->",stack[i]);
  }
}
 */

 //function to do dfs using loops

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


   for(i = 0; i < 8; i++)
       printf("%d->",stack[i]);


       printf("\n");


   for(i = 0; i < 8; i++)
       printf("%d->",visitedArray[i]);


}

//function for traversing breadthFirstSearch
void breadthFirstSearch(GRAPH *graph)
{
    int queue[8];

    ADJLISTNODE *crawl;




}
