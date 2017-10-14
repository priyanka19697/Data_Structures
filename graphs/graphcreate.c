// program to show adjacency list representation of graph

#include<stdio.h>
#include<stdlib.h>

//structure to represent adjacency list node
struct AdjListNode
{
    int destination;
    struct AdjListNode *link;
};

//structure to represent adjacency list
struct AdjList
{
    struct AdjListNode *head; //pointer that points to head node
};

//structure to represent a graph i.e here an array of adjacency lists. the array = no of nodes
struct Graph
{
    int Vertex;
    struct AdjList* array; // each vertex has an attached array to point to its adjacent nodes

};

void depthFirstSearch(struct Graph *graph);

//function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int destination)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode -> destination = destination;
    newNode -> link =  NULL;
    return newNode;
}

//function that creates graph of v vertices
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> Vertex = vertices;

    //create an array of adjacency lists.size of array will be number of vertices
    graph -> array = (struct AdjList*)malloc(vertices*sizeof(struct AdjList));

    //initialise each adjacency list by making head as NULL
    for(int i = 0; i < vertices; i++)
    {
        graph -> array[i].head = NULL;
    }
    return graph;
 }

 //function to add edge to an undirected graph
 void addEdge(struct Graph* graph, int source, int destination)
 {
    //add edge from source to destination. and a new node is added to adjacency list of source
    //the node is added at the beginning
    struct AdjListNode *newNode = newAdjListNode(destination);
    newNode -> link = graph -> array[source].head;//links destination to source
    graph -> array[source].head = newNode;

    //since its an undirected graph, add edge from destination to source AdjListNode
    newNode = newAdjListNode(source);
    newNode -> link = graph -> array[destination].head;
    graph -> array[destination].head = newNode;
 }

 //utility function to print the adjacency list representation
 void printGraph(struct Graph *graph)
 {
    int vertice;
    for(vertice = 0; vertice < graph -> Vertex; vertice++)
    {
        struct AdjListNode *temp = graph -> array[vertice].head;
        printf("\n adjacency list of vertex %d \n head", vertice );
        while (temp)
        {
            printf("-> %d ",temp -> destination );
            temp = temp -> link;
        }
        printf("\n" );
    }
 }

 // Driver program to test above functions
 int main()
 {
     // create the graph given in above fugure
     int V = 5;
     struct Graph* graph = createGraph(V);
     addEdge(graph, 0, 1);
     addEdge(graph, 0, 4);
     addEdge(graph, 1, 2);
     addEdge(graph, 1, 3);
     addEdge(graph, 1, 4);
     addEdge(graph, 2, 3);
     addEdge(graph, 3, 4);

     // print the adjacency list representation of the above graph
    // printGraph(graph);
    depthFirstSearch(graph);

     return 0;
 }


 //function to traverse depth first search in a graph
 void depthFirstSearch(struct Graph *graph)
 {
   int stack[5];
   int visitedArray[5] = {0, 0, 0, 0, 0};

   struct AdjListNode *crawl;

   stack[0] = 0;
   visitedArray[0] = 1;

   crawl = graph -> array[stack[0]].head;

   while(crawl && visitedArray[crawl -> destination] == 1)
   {
      crawl = crawl -> link;
   }
   stack[1] = crawl -> destination;
   visitedArray[crawl -> destination] = 1;

   crawl = graph -> array[stack[1]].head;

   while(crawl && visitedArray[crawl -> destination] == 1)
   {
      crawl = crawl -> link;
   }
   stack[2] = crawl -> destination;
   visitedArray[crawl -> destination] = 1;

   crawl = graph -> array[stack[2]].head;

   while(crawl && visitedArray[crawl -> destination] == 1)
   {
      crawl = crawl -> link;
   }
   stack[3] = crawl -> destination;
   visitedArray[crawl -> destination] = 1;

   crawl = graph -> array[stack[3]].head;

   while(crawl && visitedArray[crawl -> destination] == 1)
   {
      crawl = crawl -> link;
   }
   stack[4] = crawl -> destination;
   visitedArray[crawl -> destination] = 1;


    //for printing elements in bfs order
    int i;

    for(i = 0; i < 5; i++)
    {
      printf("%d->",stack[i]);
    }
 }
