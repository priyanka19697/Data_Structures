#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *link;
};
typedef node NODE;
NODE *head,*first=0,*temp
}


void addnode(int choice)
{

}
void traversenode(int place)
{
  /*node = (NODE*)malloc(sizeof(NODE));
  printf("enter the data in new node");
  if(first->link = 0)
  {
    scanf("%d",&node->data);
    node->link = null;
    }
   else if(n=0)
  {
    scanf("%d",&node->data);
    node->link = *first;
  }
  else if(n=count)
  {

  }*/
  for(i=1;i<=n;i++)
  {
    temp -> ptr = head;
    temp = head;
  }
  
}
void main()
{
  printf("do you want to enter a node yes or no 1//0");
  scanf("%d",&choice);
  addnode(choice);
  printf("\n where do you want to insert the new node");
  scanf("%d",&n);
  traversenode(n);
}
