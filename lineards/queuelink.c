#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void enqueue();
void dequeue();
void display();
struct node{
  int data;
  struct node *link;
};
typedef struct node NODE;

NODE *front=0,*rear=0,*recent,*temp;

void main()
{ int choice,option = 1;
  while(option)
  {printf("\n queue operations \n");
  printf("\n 1.enqueue \n 2.dequeue \n 3.display\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    enqueue();
    break;
    case 2:
    dequeue();
    break;
    case 3:
    display();
    break;
    default:
    printf("\n enter a valid choice");
  }
  printf("\n do you want to continue 0 or 1");
  scanf("%d",&option);
}
}

void enqueue()
{
  recent = (NODE*)malloc(sizeof(NODE));
  printf("\n enter the data ");
  scanf("%d",&recent->data);
  //recent->link = 0;
  if(front == 0)
  {
    front = rear = recent;
    recent->link = 0;
  }
  else
  {
    rear->link = recent;
    rear = recent;
  }
}

void dequeue()
{
  if(front==0)
  {
    printf("\n queue is empty");
  }
  printf("\n the deleted data is %d",front->data);
  front = front->link;
}

void display()
{ temp = front;
  if(front==0)
  printf("\n queue is empty");
  else
{ while(temp->link!= 0)
  {
    printf("\n |%d|",temp->data);
    temp = temp->link;
  }
  printf("\n |%d|",temp->data );
}
}
