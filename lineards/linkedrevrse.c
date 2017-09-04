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
  NODE *head=0,*recent,*temp=0;
  int choice =1,count =0;

  while(choice)
  {
    recent = (NODE*)malloc(sizeof(NODE));
    printf("\n the data t be inserted is \t ");
    scanf("%d",&recent->data);
    if(head!=0)
    {
      head = recent;
     head->link = temp;
      temp = head;
    }
    else
    {
      temp=head=recent;
    }
    fflush(stdin);
    printf("\n do you want to continue \n ");
    scanf("%d",&choice);
  }
//idi got kadaaaa
   printf("the linked list is");
   while(head!=0)
   {
     printf("%d=>",head->data);
     count++;
     head = head -> link;
   }
   printf("\n the number of nodes are %d",count);
  }
