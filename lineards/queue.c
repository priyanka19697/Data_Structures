#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX];
int rear = -1;
int front = -1;
void insert();
void delete();
void display();
void main()
{
  int choice;
  while(1)
  {
    printf("1.Insert element to queue \n");
printf("2.Delete element from queue \n");
printf("3.Display all elements of queue \n");
printf("4.Quit \n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("Wrong choice \n");
} /*End of switch*/
  }
}

 void insert()
 {
   int item;
   if(rear == MAX -1)
   {
     printf("queue overflow");
   }
   else
   {
     if(front==-1)//if queue is empty
     front =0;
     printf("insert eleement in the queue");
     scanf("%d",&item);
     rear = rear +1;
     queue[rear] = item;
     }
 }//end of insert

 void delete()
 {
   if(front == -1 || front >rear)
   {
     printf("queue underflow \n");
     return ;
   }
   else
   {
     printf("element deleted from queue is %d",queue[front]);
     front = front +1;
   }
 }
 void display()
 {
   int i;
   if(front == -1)
   printf("queue is empty \n");
   else{
     printf("\n status of the queue is");
     for(i = front;i<= rear;i++)
     {
       printf("|%d|",queue[i]);
       printf("\n");
     }
   }
 }
