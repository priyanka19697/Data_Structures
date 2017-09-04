#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void main()
{
  struct node
  {
    int data;
    struct node *ptr;
  };

  typedef struct node NODE;

  NODE *head,*first,*temp = 0;
  int choice = 1,count =0;
  first = 0;
  while(choice)
  {
   head = (NODE*)malloc(sizeof(NODE));
  printf("\n enter the data for the node");
  //scanf("%d \n",&head->data);
  scanf("%d",&head->data); //ikada error em ledk adaaaa :| adey kada same program ndku execute avtundi linked,c
  if(first!=0)
  {
    temp->ptr = head;
    temp = head;
  }
  else
  {
    temp=first=head;
  }
  fflush(stdin);
  printf("\n do you want to continue \n ");
  scanf("%d",&choice);
 }
 temp->ptr = 0;
 temp = first;//to point to first node
 printf("the linked list is");
 while(temp!=0)
 {
   printf("%d",temp->data);
   count++;
   temp = temp -> ptr;
 }
 printf("\n the number of nodes are %d",count);
}
