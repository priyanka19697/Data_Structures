//program to show adjacency list representation of graph

#include<stdio.h>
#include<stdlib.h>

//structure to represent adjacency list node
struct AdjListNode
{
    int destination;
    struct AdjListNode *link;
};
typedef struct AdjListNode adjlistnode;

//structure to represent adjacency list
struct AdjList
{
    adjlistnode *head;
};
typedef struct AdjList adjlist;

//structure to represent graph i.e an array of adjacency lists.array length = no of vertices
struct Graph
{
    int vertex;
    adjlist *array; // each vertex has an attached array to point to its adjacent nodes
};
typedef struct Graph graph;

//function to create a new adjacency list nodes
adjlistnode * newAdjListNode(int destination)
{
    adjlistnode * newNode = (adjlistnode*)malloc(sizeof(adjlistnode));
    newNode -> destination = destination;
    newNode -> link = NULL;
    return newNode;
}

graph * createGraph(int vertices)
{
    graph GRAPH = (graph*)malloc(sizeof(graph));
    GRAPH -> vertex = vertices;

    //create an array of adjacency lists for each vertex.arraysize = no of vertices
    GRAPH -> array = (adjlist*)malloc(vertices*sizeof(adjlist));

    //initialising the heads of adjlistnode to NULL
    for(int i = 0; i < vertices; i++)
    {
        GRAPH -> array[i].head = NULL;
    }
    return GRAPH;
}

//function to add edge to an undirected graph
void addEdge(graph GRAPH, int source, int destination)
{
    //adding edge from source to destination a new node is added to adjacency list of source
    //the node is added at the beginning
    adjlistnode * newNode = newAdjListNode(destination);
    newNode -> link = GRAPH -> array[source].head

}
