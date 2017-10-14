#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void insertNode(int );


struct node
{
  int data;
  struct node *link;
};

typedef struct node NODE;

void findMiddleElement(NODE *);
void printNode(NODE * );

NODE *head = 0, *temp = 0, *recent = 0;

void main()
{
    int choice = 1, num;

   while(choice)
    {
        printf("\n enter data to insert into linked list");
        scanf("%d",&num);
        insertNode(num);
        printf("\n do you want to continue? 0 or 1");
        scanf("%d",&choice );
    }

        temp -> link = 0;
        printf("%d\n",head -> data );
        //printNode(head);
        //first = head;
        findMiddleElement(head);
}

void insertNode(int num)

{

   recent = (NODE*)malloc(sizeof(NODE));
   recent -> data = num;
   recent -> link = 0;


 if(head!=0)
  {
      temp -> link = recent;
      temp = recent;

  }
  else
  {
      temp = head = recent;
  }
}

void printNode(NODE * head)
{   while(head != 0)
    {
      printf("|%d|\n",head -> data );
      head = head -> link;
    }

}



void findMiddleElement(NODE * head)
{   //NODE * first;

    temp = head ;
    int count = 0,i ;


    if(head -> link == 0)
    printf("\n nothing");

    while(temp != 0)
    {
        count++;
        temp =  temp -> link;
    }
     int mid = count/2;
     //printf(" \n mid %d ",mid);
      for(i = 0; i < mid ; i++)
      {
          head = head -> link;
      }
      printf("\n mid element is %d",head -> data );
  }

   /*else
    {
      int mid = count/2;
      for(int i = 0; i <= mid + 1; i++)
      {
          temp = temp -> link;
      }
      printf(" \n  mid element is %d ",temp -> data );
      //temp = temp -> link;
      //printf("\n second mid element is %d ",temp -> data );
      return 0;
      */
