#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void main()
{
  struct node
  {
    int data;
    struct node *link;
  };

  typedef struct node NODE;

  NODE *recent,*head,*temp = 0;
  int choice = 1,count =0;
  head = 0;
  while(choice)
  {
   recent = (NODE*)malloc(sizeof(NODE));
  printf("\n enter the data for the node");
  //scanf("%d \n",&recent->data);
  scanf("%d",&recent->data); //
  if(head!=0)
  {
    temp->link = recent;
    temp = recent;
  }
  else
  {
    temp=head=recent;
  }
  fflush(stdin);
  printf("\n do you want to continue \n ");
  scanf("%d",&choice);
 }
 temp->link = 0;
 temp = head;//to point to head node
 printf("the linked list is");
 while(temp!=0)
 {
   printf("%d",temp->data);
   count++;
   temp = temp -> link;
 }
 printf("\n the number of nodes are %d",count);
}
