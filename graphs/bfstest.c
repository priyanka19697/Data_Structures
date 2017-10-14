#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10


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

void breadthFirstSearch(GRAPH *graph);

struct Queue
{
    int queue_array[MAXSIZE];
    int front , rear;
};

typedef struct Queue QUEUE;

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

QUEUE queue;

void enqueue(int data)
{

    if(queue.front==-1)
        queue.front=0;

    queue.rear = queue.rear + 1;
    queue.queue_array[queue.rear] = data;

}

int dequeue()
{
    int value;

    if(queue.front==-1 || queue.front > queue.rear)
    {
        //printf("\nQueue Underflow\n");
        return 2;
    }

    else
    {
        value = queue.queue_array[queue.front];
        queue.front = queue.front + 1;
        return value;
    }
}

int peek()
{
  int value;

  if(queue.front==-1 || queue.front > queue.rear)
  {
      printf("\nQueue Underflow\n");
      return -1;
  }

  else
  {
      value = queue.queue_array[queue.front];
      return value;
  }
}


int visitedArray[8] = {0,0,0,0,0,0,0,0};

int main()
{

        int V = 8;
        struct Graph* graph = createGraph(V);


        addEdge(graph, 0 ,1);
        addEdge(graph, 0 ,3);
        addEdge(graph, 0 ,6);

        addEdge(graph, 1, 5);
        addEdge(graph, 1, 4);

        addEdge(graph, 2, 5);
        addEdge(graph, 2, 7);

        addEdge(graph, 3, 5);
        //addEdge(graph, 3, 7);

        addEdge(graph, 4, 6);


    //depthFirstSearch(graph); okieee
    breadthFirstSearch(graph);
    return 0;
}



void breadthFirstSearch(GRAPH *graph)
{

    queue.front = queue.rear = -1;

    int visitedArray[8] = {0, 0 ,0 , 0, 0, 0, 0, 0};

    ADJLISTNODE *crawl;
    //enqueue(0);
    printf("%d -> ",0);
    visitedArray[0] = 1;

    crawl = graph->array[0].head;
    int count = graph->V;

    while(count)
    {
      while(crawl && visitedArray[crawl->dest] == 0)
      {

        printf("%d->",crawl->dest );
        visitedArray[crawl->dest] = 1;
        enqueue(crawl->dest);
        crawl = crawl -> next;

      }

      //dequeue();

        crawl = graph->array[dequeue()].head;

      count--;

    }


}
